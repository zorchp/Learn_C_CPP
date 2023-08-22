#include <list>
#include <iostream>
#include <string>

/// Observer（观察者）:  Observer
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0; // 纯虚基类

protected:
    Observer() = default;
};

/// Subject（目标）： Blog
class Blog {
public:
    virtual ~Blog() = default;
    void attach(Observer *observer) { // 添加观察者
        observerList.push_back(observer);
    }
    void remove(Observer *observer) { // 移除观察者
        observerList.remove(observer);
    }
    void notify() { // 通知观察者, 循环, 全部通知
        for (auto observer : observerList) {
            observer->update();
        }
    }
    virtual void setStatus(std::string s) = 0; // 纯虚基类
    virtual std::string getStatus() = 0;       // 获得状态
private:
    std::list<Observer *> observerList; // 观察者链表
protected:
    Blog() = default;
    std::string status; // 状态
};

/// ConcreteSubject（具体目标）:  BlogCSDN
class BlogCSDN : public Blog {
public:
    explicit BlogCSDN(const std::string &name) {
        this->name = name;
        std::cout << "BlogCSDN Hello,name = " << this->name << std::endl;
    }
    ~BlogCSDN() override {
        std::cout << "BlogCSDN Bye,name = " << this->name << std::endl;
    }
    void setStatus(std::string s) override { // 具体设置状态信息
        status = "CSDN通知 : " + name + s;
    }
    std::string getStatus() override { return status; }

private:
    std::string name; // 博主名称
};

/// ConcreteObserver（具体观察者）： ObserverBlog
class ObserverBlog : public Observer {
public:
    explicit ObserverBlog(const std::string &name, Blog *blog) {
        this->name = name;
        this->blog = blog;
        std::cout << "ObserverBlog Hello,name = " << this->name << std::endl;
    }
    ~ObserverBlog() override {
        std::cout << "ObserverBlog Bye,name = " << this->name << std::endl;
    }

    void update() override { // 获得更新状态
        std::string status = blog->getStatus();
        std::cout << name << "-------" << status << std::endl;
    }

private:
    std::string name; // 观察者名称
    Blog *blog;
};


int main(int argc, char *argv[]) {
    Blog *blog = new BlogCSDN("墨1024");
    Observer *observer1 = new ObserverBlog("张三", blog);
    Observer *observer2 = new ObserverBlog("李四", blog);
    blog->attach(observer1);
    blog->attach(observer2);
    std::cout << "==================" << std::endl;
    blog->setStatus("发表了一篇Blog");
    blog->notify();
    std::cout << "==================" << std::endl;
    blog->remove(observer1);
    blog->setStatus("更新了一条blink");
    blog->notify();
    std::cout << "==================" << std::endl;
    delete blog;
    delete observer1;
    delete observer2;
    return 0;
    // BlogCSDN Hello,name = 墨1024
    // ObserverBlog Hello,name = 张三
    // ObserverBlog Hello,name = 李四
    // ==================
    // 张三-------CSDN通知 : 墨1024发表了一篇Blog
    // 李四-------CSDN通知 : 墨1024发表了一篇Blog
    // ==================
    // 李四-------CSDN通知 : 墨1024更新了一条blink
    // ==================
    // BlogCSDN Bye,name = 墨1024
    // ObserverBlog Bye,name = 张三
    // ObserverBlog Bye,name = 李四
}
