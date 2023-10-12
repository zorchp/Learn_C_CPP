template <typename T>
class P {
    typename T::SubType *str; // treat T::SubType* as a type
    T::SubType *str1;         // treat T::SubType* as a value
};
