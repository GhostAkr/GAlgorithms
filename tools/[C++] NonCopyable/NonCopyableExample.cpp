#include <utility>

#include "NonCopyable.hpp"

class SomeClass : private GAlg::NonCopyable
{};

int main()
{
    SomeClass obj1;

    // Can't be copied or copy-assigned
    // SomeClass obj2(obj1);
    // SomeClass obj3 = obj1;

    // Can be moved or move-assigned
    SomeClass obj4(std::move(obj1));
    SomeClass obj5 = std::move(obj4);
}
