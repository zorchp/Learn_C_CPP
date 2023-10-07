struct VideoFile;
struct TextFile;
struct Visitor {
    virtual void visit(VideoFile &) = 0;
    virtual void visit(TextFile &) = 0;
    virtual ~Visitor() = default;
};

struct Elem {
    virtual void accept(Visitor &visit) = 0;
    virtual ~Elem() = default;
};

// more same code, try to use CRTP
struct VideoFile : Elem {
    void accept(Visitor &visitor) override { visitor.visit(*this); }
};

struct TextFile : Elem {
    void accept(Visitor &visitor) override { visitor.visit(*this); }
};
