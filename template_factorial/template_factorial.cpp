#include "template_factorial.hpp"

int recursiveFactorial(int n)
{
    if (n < 0)
    {
        return -1;
        // TODO: throw a error here
    }

    if (n == 0)
    {
        return 1;
    }

    return n * recursiveFactorial(n - 1);
}
