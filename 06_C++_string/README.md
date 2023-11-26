Իրականացնել դինամիկ տող (string), որը կիրականացվի վեկտորի նման՝ ունենալով size/capacity, ներքին ցուցիչ char-երի վրա, բայց անհրաժեշտ է օպտիմիզացնել փոքր տողերի համար։ Եթե տողի չափը չի գերազանցում 16 սիմվոլը, ապա տողը պետք է պահվի ստեկում, հակառակ դեպքում՝ heap-ում։ Խնդրի լուծման համար կարող եք օգտագործել union, որը կկիրառվի մոտավորապես այսպես.

```cpp
class my_string 
{ 
    // ...
private: 
    struct dyn_str 
    { 
        int size; 
        char* ptr;
    }; 
    union { 
        char onstack[16]; 
        dyn_str str; 
    } string;
    bool isOnHeap;
};

default constructor
constructor with parameters
copy constructor
move constructor
destructor
copy assignment operator`  string& operator=(string& rhs);
move assignment operator` string& operator=(string&& rhs) noexcept;
operator+=` string& operator+=(const string& s);
                             string& operator+=(const char* s);
operator+`    string operator+(const string& s1, const string& s2);
                             string operator+(const string& s1, const char* s2);
                             string operator+(const char* s1, const string& s2);
operator<<` std::ostream& operator<<(std::ostream& cout, string& str);
operator>>` std::istream& operator>>(std::istream& cin, string& str);
size()
c_str()
