inline namespace {
  template<class T>
concept my_type = std::is_fundamental<T>::value;


template<my_type T>
class Final{
private:
    constexpr static int value = 1024;
    T imm;
    static_assert(std::is_fundamental<T>::value);
public:
    constexpr Final(T stable):imm{stable}{}
    Final(const Final<T>& copy)=default;
    Final(Final&& move)=delete;
    Final& operator=(const Final<T>& copy)=delete;
    Final& operator=(auto x)=delete;
    Final& operator=(Final&& move)=delete;
    operator&()=delete;
    operator~()=delete;

    [[maybe_unused]] consteval T operator+(){return +this->imm;}
    [[maybe_unused]] consteval T operator-(){return -this->imm;}
    consteval T operator*(){return this->imm;}
    consteval T operator!(){return !this->imm;}

    template<my_type X>
    constexpr operator X(){ return static_cast<X>(this->imm);}

    constexpr explicit operator bool(){return static_cast<bool>(this->imm);}

    T get(){ return this->imm;}

    template<class X>
    auto operator%(Final<X> arg){ return std::fmod(imm,arg.get());}

   template<my_type X>
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

template<my_type X, class Y>
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

