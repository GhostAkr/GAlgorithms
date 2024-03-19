#include <memory>

template <typename T>
class CowPtr
{
public:
    explicit CowPtr(T* raw)
        : _data(raw)
    {}

    explicit CowPtr(const std::shared_ptr<T>& smart)
        : _data(smart)
    {}

    void detach()
    {
        T* raw = _data.get();
        if (raw && !_data.unique())
            _data = std::shared_ptr<T>(new T(*raw));
    }

    T& operator*(void)
    {
        detach();
        return *_data;
    }

    const T& operator*(void) const
    {
        return *_data;
    }

    T* operator->()
    {
        detach();
        return _data.operator->();
    }

    const T* operator->() const
    {
        return _data.operator->();
    }

    
private:
    std::shared_ptr<T> _data;
};
