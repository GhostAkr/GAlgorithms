#include <iostream>
#include "singleton.hpp"

int main()
{
    std::cout << "Val before: " << App::instance()->getVal() << std::endl;
    App::instance()->setVal(3);
    std::cout << "Val after: " << App::instance()->getVal() << std::endl;

    return 0;
}
