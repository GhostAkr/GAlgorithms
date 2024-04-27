#include <iostream>
#include <string>
#include "split_str_view.hpp"

int main()
{
    std::string testStr {"here is some test string"};

    std::vector<std::string_view> splittedTestStr = GAlg::splitIntoWords(testStr);

    for (std::string_view word : splittedTestStr)
    {
        std::cout << word << std::endl;
    }

    return 0;
}
