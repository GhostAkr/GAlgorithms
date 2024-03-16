#include <algorithm>
#include <vector>

namespace GAlg
{
    template <typename T>
    void remove(std::vector<T>& vec, const T& item)
    {
        auto eraseStart = std::remove(vec.begin(), vec.end(), item);
        vec.erase(eraseStart, vec.end());
    }
}