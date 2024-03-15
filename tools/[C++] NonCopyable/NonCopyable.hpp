namespace GAlg
{
    class NonCopyable
    {
    public: 
        NonCopyable(const NonCopyable& other) = delete;
        NonCopyable& operator=(const NonCopyable& other) = delete;
    protected:
        NonCopyable() = default;
        ~NonCopyable() = default;

        NonCopyable(NonCopyable&& other) = default;
        NonCopyable& operator=(NonCopyable&& other) = default;
    };
}
