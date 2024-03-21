#include <iostream>
#include <string>

class INotifier
{
public:
    INotifier(const std::string& msg)
        : _msg(msg)
    {}

    virtual ~INotifier() = default;
    virtual void print() = 0;

protected:
    std::string _msg;
};

class Notifier : public INotifier
{
public:
    Notifier(const std::string& msg)
        : INotifier(msg)
    {}

    virtual void print() override
    {
        std::cout << "Sending email: " << "\"" << _msg << "\"" << std::endl;
    }
};

class NotifierDecorator : public INotifier
{
public:
    NotifierDecorator(INotifier* notifier, std::string msg)
        : INotifier(msg)
        , notifier(notifier)
    {}

    virtual void print() override
    {
        notifier->print();
    }

protected:
    INotifier* notifier;
};

class NotifierSMS : public NotifierDecorator
{
public:
    NotifierSMS(INotifier* notifier, std::string msg)
        : NotifierDecorator(notifier, msg)
    {}

    virtual void print() override
    {
        notifier->print();
        std::cout << "Sending SMS: " << _msg << std::endl;
    }
};

class NotifierTG : public NotifierDecorator
{
public:
    NotifierTG(INotifier* notifier, std::string msg)
        : NotifierDecorator(notifier, msg)
    {}

    virtual void print() override
    {
        notifier->print();
        std::cout << "Sending Telegram message: " << _msg << std::endl;
    }
};
