
#include <iostream>
#include "CowPtr.hpp"

class SomeClass
{
public:
    SomeClass() = default;
    explicit SomeClass(const SomeClass& other)
        : _val(other._val)
    {
        std::cout << "[Copy ctor]" << std::endl;
    }

    SomeClass& operator=(int val)
    {
        _val = val;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const SomeClass& obj)
    {
        os << obj._val;
        return os;
    }

    int _val;
};



int main()
{
    CowPtr<SomeClass> cPtr (new SomeClass);
    const CowPtr<SomeClass> cPtr2(cPtr);
    CowPtr<SomeClass> cPtr3(cPtr);
    
    std::cout << "cPtr value before: " << cPtr->_val << std::endl;
    cPtr3->_val = 5;
    std::cout << "cPtr value after: " << cPtr->_val << std::endl;
    std::cout << "cPtr2 value: " << cPtr2->_val << std::endl;
    std::cout << "cPtr3 value: " << cPtr3->_val << std::endl;

    const CowPtr<SomeClass> cPtr4(cPtr);
    CowPtr<SomeClass> cPtr5(cPtr);
    std::cout << "cPtr value before: " << (*cPtr)._val << std::endl;
    (*cPtr5)._val = 7;
    std::cout << "cPtr value after: " << (*cPtr)._val << std::endl;
    std::cout << "cPtr4 value: " << (*cPtr4)._val << std::endl;
    std::cout << "cPtr5 value: " << (*cPtr5)._val << std::endl;
}
