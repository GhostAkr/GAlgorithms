#include <string_view>
#include <vector>

namespace GAlg
{
    std::vector<std::string_view> splitIntoWords(std::string_view src)
    {
        std::vector<std::string_view> res;

        size_t spacePos = 0;
        while(spacePos != src.npos)
        {
            spacePos = src.find(' ');
            res.push_back(src.substr(0, spacePos));

            if (spacePos != src.npos)
                src.remove_prefix(spacePos + 1);
        }

        return res;
    }
}
