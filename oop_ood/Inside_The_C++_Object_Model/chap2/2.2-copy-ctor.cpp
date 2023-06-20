#include <cstdio>
#include <queue>


namespace when_call_copy_ctor {

class X {
public:
    X(){};
    ~X(){};
    X(const X &) {
        printf("copy %s\n", __func__);
    };
};

void foo(X x) {
}

X bar() {
    X x;
    // ...
    return x;
}

} // namespace when_call_copy_ctor


void t1() {
    using namespace when_call_copy_ctor;
    X x;
    X xx = x; // copy X
    foo(x);   // copy X
    // CXX_FLAG: -fno-elide-constructors
    auto xxx = bar(); // copy X
}

namespace default_memberwise_initialization {

class String {
public:
    String(const char *) {
        printf("%s\n", __func__);
    }
    // 没有显式声明 copy-ctor

private:
    char *str;
    int len;
};

class Word {
public:
    //
    Word(const char *) : _word("") {
        printf("%s\n", __func__);
    }
    ~Word() {
        printf("%s\n", __func__);
    }

private:
    int _occurs;
    String _word; // String 是 Word 的一个成员
};
} // namespace default_memberwise_initialization

void t2() {
    using namespace default_memberwise_initialization;
    String noun("book"); // String
    String verb = noun;
    // 类似于: 逐个成员拷贝
    // verb.str = noun.str;
    // verb.len = noun.len;

    Word w("");
    // 先拷贝其内建的成员 _occurs,
    // 然后再于 String 成员 _word 上递归实施成员逐位初始化
}

namespace bitwise_copy_semantics {
class Word_non_auto_copy_ctor {
public:
    Word_non_auto_copy_ctor(const char *) {
        printf("%s\n", __func__);
    }
    ~Word_non_auto_copy_ctor() {
        delete[] str;
    }

private:
    int cnt;
    char *str;
};

class String {
public:
    String(const char *) {
    }
    String(const String &) { // 主要是因为这里有 copy-ctor
    }
    ~String() {
    }
};
class Word { // 这种情况并没有逐位拷贝语义
    // 编译器会合成出来 copy-ctor
public:
    Word(const char *s) : cnt(), str(s) {
    }
    // 会报错
    // Word(const String &) {
    // }
    ~Word() {
    }

private:
    int cnt;
    String str;
};
} // namespace bitwise_copy_semantics

void t3() {
    using namespace bitwise_copy_semantics;
    Word_non_auto_copy_ctor noun("book");
    Word_non_auto_copy_ctor verb = noun;
    // 这种调用不合成默认的拷贝构造, 因为默认拷贝语义
}

void t4() {
    using namespace bitwise_copy_semantics;
    Word noun("book");
    Word verb = noun;
}

namespace vtbl_reset {
class ZooAnimal {
public:
    ZooAnimal() {
        printf("ZooAnimal::%s\n", __func__);
    }
    virtual ~ZooAnimal() {
        printf("ZooAnimal::%s\n", __func__);
    }
    virtual void animate() {
        printf("ZooAnimal::%s\n", __func__);
    }
    virtual void draw() {
        printf("ZooAnimal::%s\n", __func__);
    }

private:
    int data; // 4bytes
};

class Bear : public ZooAnimal {
public:
    Bear() {
        printf("Bear::%s\n", __func__);
    }
    void animate() {
        printf("Bear::%s\n", __func__);
    }
    void draw() {
        printf("Bear::%s\n", __func__);
    }
    virtual void dance() {
        printf("Bear::%s\n", __func__);
    }

private:
    int data; // 4bytes
};
} // namespace vtbl_reset

void t5() {
    //
    using namespace vtbl_reset;
    Bear yogi; // yogi 的虚指针被设定指向 Bear 类的虚表
    // printf("%ld\n", sizeof(ZooAnimal)); // 16, 8+4+4对齐
    // printf("%ld\n", sizeof(Bear));      // 16, 8+4+4
    Bear winnie = yogi;

    // ZooAnimal::ZooAnimal
    // Bear::Bear
    // ZooAnimal::~ZooAnimal
    // ZooAnimal::~ZooAnimal
}

void t6() {
    using namespace vtbl_reset;
    Bear yogi;
    ZooAnimal franny = yogi; // sliced
    auto draw = [](ZooAnimal &zoey) { zoey.draw(); };
    draw(yogi);   // Bear::draw
    draw(franny); // ZooAnimal::draw

    ZooAnimal &ref_franny = yogi; // Reference, 或者指针, 都不会影响 sliced
    draw(ref_franny);             // Bear::draw

    ZooAnimal *ptr_franny = &yogi; // Reference, 或者指针, 都不会影响 sliced
    draw(*ptr_franny);             // Bear::draw
}

namespace virtual_base_class {
class ZooAnimal {
public:
    ZooAnimal() {
        printf("ZooAnimal::%s\n", __func__);
    }
    virtual ~ZooAnimal() {
        printf("ZooAnimal::%s\n", __func__);
    }
    virtual void animate() {
        printf("ZooAnimal::%s\n", __func__);
    }
    virtual void draw() {
        printf("ZooAnimal::%s\n", __func__);
    }

private:
    // data
};
class Racoon : public virtual ZooAnimal {
public:
    Racoon() {
    }
    Racoon(int) {
    }

private:
    // data
};

class RedPanda : public Racoon {
public:
    RedPanda() {
    }
    RedPanda(int) {
    }

private:
    //
};
} // namespace virtual_base_class

void t7() {
    using namespace virtual_base_class;
    Racoon rocky;
    Racoon little_critter = rocky; // call copy-ctor

    // 合成 copy-ctor 以改正虚基类指针的偏移量的初值
    RedPanda little_red;
    Racoon little_critter1 = little_red;

    // 逐位拷贝不一定有效
    Racoon *ptr{}; // runtime error: reference binding to null pointer of type
                   // 'const virtual_base_class::Racoon'
    Racoon little_critter2 = *ptr;
}
int main(int argc, char *argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    // t5();
    // t6();
    t7();
    return 0;
}
