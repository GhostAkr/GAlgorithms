#include <utility>
#include <iostream>

class CopyAndSwap
{
public:
    CopyAndSwap()
        : _pVal(new int)
    {}

    ~CopyAndSwap()
    {
        delete _pVal;
    }

    CopyAndSwap(const CopyAndSwap& other)
        : _pVal(new int)
    {
        std::cout << "Copy ctor" << std::endl;
        *_pVal = *(other._pVal);
    }

    CopyAndSwap& operator=(CopyAndSwap other)
    {
        std::cout << "Universal assignment" << std::endl;
        swap(other);
        return *this;
    }

    void swap(CopyAndSwap& other)
    {
        std::swap(this->_pVal, other._pVal);
    }
private:
    int* _pVal;
};

int main()
{
    CopyAndSwap obj1;
    CopyAndSwap obj2;
    obj2 = obj1;

    CopyAndSwap obj3;
    obj3 = std::move(obj1);
}
