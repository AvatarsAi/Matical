
namespace matical{
  //Please #include or import <type_traits> and <cmath>;
  inline namespace {
  template<class T>
concept my_type = std::is_fundamental<T>::value; //relationship with built-in types


template<my_type T>
class Final final{ //Final not to be mistaken with final
private:
    constexpr static int value = 1024;
    T imm;
public:
    constexpr Final(T stable):imm{stable}{} //literal type
    Final(const Final<T>& copy)=default; //copy constructor
    [[noreturn]] Final(Final&& move)=delete; //move constructor
    [[noreturn]] Final& operator=(const Final<T>& copy)=delete; //no changeof value allowed
    [[noreturn]]Final& operator=(auto x)=delete;
    [[noreturn]]Final& operator=(Final&& move)=delete;
    [[noreturn]]operator&()=delete;
    [[noreturn]] operator~()=delete;

    [[maybe_unused]] T operator+(){return +this->imm;}
    [[maybe_unused]] T operator-(){return -this->imm;}
    [[deprecated("use the get() method")]] T operator*(){return this->imm;}
    T operator!(){return !this->imm;}

    template<my_type X>
    constexpr operator X(){ return static_cast<X>(this->imm);}

    constexpr explicit operator bool(){return static_cast<bool>(this->imm);} //boolean conversion is explicit

    T get(){ return this->imm;} //NB: get() method is a "fundamental" removing it will trash the system

  //OVERLOADING OF operators
    template<class X>
    auto operator%(Final<X> arg){ return std::fmod(imm,arg.get());}

   template<my_type X> //noticed the my_type from concept declaration
    auto operator%(X arg){ return std::fmod(imm, arg);}

    template<class X>
    auto operator+(Final<X>arg){return imm + arg.get();}

    template<my_type X>
    auto operator+(X arg){return imm + arg;}

    template<class X>
    auto operator-(Final<X>arg){return imm - arg.get();}

    template<my_type X>
    auto operator-(X arg){return imm - arg;}

    template<class X>
    auto operator*(Final<X>arg){return imm * arg.get();}

    template<my_type X>
    auto operator*(X arg){return imm * arg;}

    template<my_type X>
    auto operator/(X arg){return imm / arg;}

    template<class X>
    auto operator/(Final<X>arg){return imm / arg.get();}

    template<class X>
    auto operator^(Final<X> arg){ return (static_cast<int>(imm) ^ static_cast<int>(arg.get()));}

    template<my_type X>
    auto operator^(X arg){ return (static_cast<int>(imm) ^ static_cast<X>(arg));}

    template<class X>
    auto operator<<(Final<X> arg){ return (static_cast<int>(imm) << static_cast<int>(arg.get()));}

    template<my_type X>
    auto operator<<(X arg){ return (static_cast<int>(imm) << static_cast<X>(arg));}

    template<class X>
    auto operator>>(Final<X> arg){ return (static_cast<int>(imm) << static_cast<int>(arg.get()));}

    template<my_type X>
    auto operator>>(X arg){ return (static_cast<int>(imm) << static_cast<X>(arg));}

    template<class X>
    auto operator&(Final<X> arg){ return (static_cast<int>(imm) & static_cast<int>(arg.get()));}

    template<my_type X>
    auto operator&(X arg){ return (static_cast<int>(imm) & static_cast<X>(arg));}

    template<class X>
    auto operator|(Final<X> arg){ return (static_cast<int>(imm) | static_cast<int>(arg.get()));}

    template<my_type X>
    auto operator|(X arg){ return (static_cast<int>(imm) | static_cast<X>(arg));}

    template<class X>
    auto operator<(Final<X> arg){ return imm < arg.get();}

    template<my_type X>
    auto operator<(X arg){return imm < arg;}

    template<class X>
    auto operator>(Final<X> arg){ return imm > arg.get();}

    template<my_type X>
    auto operator>(X arg){return imm > arg;}

    template<class X>
    auto operator==(Final<X> arg){ return imm == arg.get();}

    template<my_type X>
    auto operator==(X arg){return imm == arg;}

    template<class X>
    auto operator!=(Final<X> arg){ return imm != arg.get();}

    template<my_type X>
    auto operator!=(X arg){return imm != arg;}

    template<class X>
    auto operator>=(Final<X> arg){ return imm >= arg.get();}

   template<my_type X>
    auto operator>=(X arg){return imm >= arg;}

    template<class X>
    auto operator<=(Final<X> arg){ return imm <= arg.get();}

    template<my_type X>
    auto operator<=(X arg){ return imm <= arg;}

    template<class X>
    auto operator<=>(Final<X> arg){ return imm <=> arg.get();}

    template<my_type X>
    auto operator<=>(X arg){return imm <=> arg;}

    template<class X>
    auto operator&&(Final<X>arg){ return imm && arg.get();}

    template<my_type X>
    auto operator&&(X arg){return imm && arg;}

    template<class X>
    auto operator||(Final<X>arg){ return imm || arg.get();}

    template<my_type X>
    auto operator||(X arg){return imm || arg;}



};

//BUILT-IN LHS relationship with RHS Final type operator overloading

template<my_type X, class Y> //notice the my_type concept relationship
auto operator%(X arg1, Final<Y>arg2){
    return std::fmod(arg1,arg2.get());
}

template<my_type X, class Y>
auto operator+(X arg1, Final<Y>arg2){
    return arg1 + arg2.get();
}

template<my_type X, class Y>
auto operator-(X arg1, Final<Y>arg2){
    return arg1 - arg2.get();
}

template<my_type X, class Y>
auto operator*(X arg1, Final<Y>arg2){
    return arg1 * arg2.get();
}

template<my_type X, class Y>
auto operator/(X arg1, Final<Y>arg2){
    return arg1 / arg2.get();
}


template<my_type X, class Y>
auto operator^(X arg1, Final<Y>arg2){
     return (static_cast<int>(arg1) ^ static_cast<int>(arg2.get()));
}

template<my_type X, class Y>
auto operator&(X arg1, Final<Y>arg2){
     return (static_cast<int>(arg1) & static_cast<int>(arg2.get()));
}

template<my_type X, class Y>
auto operator|(X arg1, Final<Y>arg2){
     return (static_cast<int>(arg1) | static_cast<int>(arg2.get()));
}

template<my_type X, class Y>
auto operator<<(X arg1, Final<Y>arg2){
     return (static_cast<int>(arg1) << static_cast<int>(arg2.get()));
}

template<my_type X, class Y>
auto operator>>(X arg1, Final<Y>arg2){
     return (static_cast<int>(arg1) >> static_cast<int>(arg2.get()));
}

template<my_type X, class Y>
auto operator<(X arg1, Final<Y>arg2){
     return  arg1 < arg2.get();
}

template<my_type X, class Y>
auto operator>(X arg1, Final<Y>arg2){
     return  arg1 > arg2.get();
}

template<my_type X, class Y>
auto operator==(X arg1, Final<Y>arg2){
     return  arg1 == arg2.get();
}

template<my_type X, class Y>
auto operator!=(X arg1, Final<Y>arg2){
     return  arg1 != arg2.get();
}

template<my_type X, class Y>
auto operator>=(X arg1, Final<Y>arg2){
     return  arg1 >= arg2.get();
}
template<my_type X, class Y>
auto operator<=(X arg1, Final<Y>arg2){
     return  arg1 <= arg2.get();
}

template<my_type X, class Y>
auto operator<=>(X arg1, Final<Y>arg2){
    return arg1 <=> arg2.get();
}

template<my_type X, class Y>
auto operator&&(X arg1, Final<Y>arg2){
    return arg1 && arg2.get();
}

template<my_type X, class Y>
auto operator||(X arg1, Final<Y>arg2){
    return arg1 || arg2.get();
}

}

}
