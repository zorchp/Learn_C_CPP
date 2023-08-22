template <bool cond, typename Body>
struct WhileLoop;


template <typename Body>
struct WhileLoop<true, Body> {
    typedef
        typename WhileLoop<Body::cond_val, typename Body::next_type>::type type;
};

template <typename Body>
struct WhileLoop<false, Body> {
    typedef typename Body::res_type type;
};

template <typename Body>
struct While {
    typedef typename WhileLoop<Body::cond_val, Body>::type type;
};
