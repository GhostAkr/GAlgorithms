#include <iostream>

#include "template_factorial.hpp"

void testRecursiveFactorial()
{
    std::cout << "Recursive factorial tests:" << std::endl;

    int n1 = -1, n2 = 0, n3 = 1, n4 = 2, n5 = 5, n6 = 6;

    int r1 = recursiveFactorial(n1);
    std::cout << n1 << "! = " << r1 << std::endl;

    int r2 = recursiveFactorial(n2);
    std::cout << n2 << "! = " << r2 << std::endl;

    int r3 = recursiveFactorial(n3);
    std::cout << n3 << "! = " << r3 << std::endl;

    int r4 = recursiveFactorial(n4);
    std::cout << n4 << "! = " << r4 << std::endl;

    int r5 = recursiveFactorial(n5);
    std::cout << n5 << "! = " << r5 << std::endl;

    int r6 = recursiveFactorial(n6);
    std::cout << n6 << "! = " << r6 << std::endl;
}

void testTemplateFactorial()
{
    std::cout << "Template factorial tests:" << std::endl;

    const int n1 = -1, n2 = 0, n3 = 1, n4 = 2, n5 = 5, n6 = 6;

    // int r1 = TemplateFactorial<n1>().value();
    // std::cout << n1 << "! = " << r1 << std::endl;

    int r2 = TemplateFactorial<n2>().value();
    std::cout << n2 << "! = " << r2 << std::endl;

    int r3 = TemplateFactorial<n3>().value();
    std::cout << n3 << "! = " << r3 << std::endl;

    int r4 = TemplateFactorial<n4>().value();
    std::cout << n4 << "! = " << r4 << std::endl;

    int r5 = TemplateFactorial<n5>().value();
    std::cout << n5 << "! = " << r5 << std::endl;

    int r6 = TemplateFactorial<n6>().value();
    std::cout << n6 << "! = " << r6 << std::endl;
}

int main()
{
    testRecursiveFactorial();
    testTemplateFactorial();
}
