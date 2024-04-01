#include <iostream>
#include <string>

class IPrinter
{
public:
    virtual ~IPrinter()
    {}

    virtual void print(std::string msg) = 0;
};

class EmailPrinter : public IPrinter
{
public:
    virtual ~EmailPrinter() override
    {}

    virtual void print(std::string msg) override
    {
        std::cout << "Email has been sent: " << msg << std::endl;
    }
};

class TGPrinter : public IPrinter
{
    virtual ~TGPrinter() override
    {}

    virtual void print(std::string msg) override
    {
        std::cout << "Telegram message has been sent: " << msg << std::endl;
    }
};

class IMsgProcessor
{
public:
    virtual ~IMsgProcessor()
    {}

    void sendUserMsg()
    {
        std::string msg = getUserMsg();

        IPrinter* printer = constructPrinter();
        printer->print(msg);
    }

protected:
    virtual IPrinter* constructPrinter() = 0;

private:
    std::string getUserMsg()
    {
        std::string msg;

        std::cout << "Enter message to send: ";
        std::cin >> msg;
        std::cout << std::endl;

        return msg;
    }
};

class EmailMsgProcessor : public IMsgProcessor
{
public:
    virtual ~EmailMsgProcessor()
    {}

protected:
    virtual IPrinter* constructPrinter() override
    {
        return new EmailPrinter {};
    }
};

class TGMsgProcessor : public IMsgProcessor
{
public:
    virtual ~TGMsgProcessor()
    {}

protected:
    virtual IPrinter* constructPrinter() override
    {
        return new TGPrinter {};
    }
};
