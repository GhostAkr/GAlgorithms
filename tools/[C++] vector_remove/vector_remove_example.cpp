#include <iostream>
#include <vector>

#include "vector_remove.cpp"

int main()
{
    std::vector<int> v1 {1, 2, 3, 2, 2, 4};

    std::cout << "v1 before" << std::endl;
    for (auto elem : v1)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    GAlg::remove(v1, 2);

    std::cout << "v1 after" << std::endl;
    for (auto elem : v1)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
