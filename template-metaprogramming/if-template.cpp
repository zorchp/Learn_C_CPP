template <bool cond, typename Then, typename Else>
struct If;

template <typename Then, typename Else>
struct If<true, Then, Else> {
    typedef Then type;
};

template <typename Then, typename Else>
struct If<false, Then, Else> {
    typedef Else type;
};
