class App
{
public:
    App() = default;
    App(const App& other) = delete;
    App(App&& other) = delete;

    App* operator=(const App& other) = delete;
    App* operator=(App&& other) = delete;

    static App* instance()
    {
        if (_instance == nullptr)
            _instance = new App;

        return _instance;
    }

    int getVal()
    {
        return _val;
    }

    void setVal(int val)
    {
        _val = val;
    }
private:
    static App* _instance;

    int _val;
};

App* App::_instance = nullptr;
