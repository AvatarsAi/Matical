namespace matical{ //Generate namespace library
    inline namespace version_1{ //"local" namespace library
        class number_line{
            signed long long int pointer{}; // "pointer" invariant for pulgacpp starts at zero


        public:
            constexpr number_line()=default;
            constexpr explicit number_line(long long arg):pointer{arg}{}


            template<class X> operator X()=delete;
            operator <<(long long arg){return pointer -= arg;}
            operator >>(long long arg){ return pointer += arg;}
            operator()(long long arg){return pointer += arg;}
            operator *(){return pointer;}
            operator&(){return &this->pointer;}
            operator==(long long arg){return (pointer == *arg)?true:false;}
            operator==(number_line&arg){return (pointer == *arg)?true:false;}
            operator==(number_line&&arg){return (pointer == *arg)?true:false;}

            operator!=(long long arg){return (pointer != *arg)?true:false;}
            operator!=(number_line&arg){return (pointer != *arg)?true:false;}
            operator!=(number_line&&arg){return (pointer != *arg)?true:false;}


            operator<(long long arg){return (pointer < *arg)?true:false;}
            operator<(number_line&arg){return (pointer < *arg)?true:false;}
            operator<(number_line&&arg){return (pointer < *arg)?true:false;}

            operator>(long long arg){return (pointer > *arg)?true:false;}
            operator>(number_line&arg){return (pointer > *arg)?true:false;}
            operator>(number_line&&arg){return (pointer > *arg)?true:false;}

            operator<=>(long long arg){return (pointer <=> *arg)?true:false;}
            operator<=>(number_line&arg){return (pointer <=> *arg)?true:false;}
            operator<=>(number_line&&arg){return (pointer <=> *arg)?true:false;}

            operator>=(long long arg){return (pointer >= *arg)?true:false;}
            operator>=(number_line&arg){return (pointer >= *arg)?true:false;}
            operator>=(number_line&&arg){return (pointer >= *arg)?true:false;}


            operator<=(long long arg){return (pointer <= *arg)?true:false;}
            operator<=(number_line&arg){return (pointer <= *arg)?true:false;}
            operator<=(number_line&&arg){return (pointer <= *arg)?true:false;}



            auto get(){ return this->pointer; }
            auto max(){ return std::numeric_limits<long long>::max();}
            auto min(){ return std::numeric_limits<long long>::min();}
            auto clear(){return pointer = 0;}
            auto point(){return pointer;}
            auto prev(int prev = 1){return pointer -= prev;}
            auto next(int next = 1 ){ return pointer += next;}

        };

    }

}
