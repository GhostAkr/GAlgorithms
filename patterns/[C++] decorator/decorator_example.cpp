#include "decorator.hpp"

int main()
{
    INotifier* notifier = new Notifier("Hello, world!");
    INotifier* notifierSMS = new NotifierSMS(notifier, "Hello, world");
    INotifier* notifierTG = new NotifierTG(notifierSMS, "Hello, world");
    notifierTG->print();

    delete notifier;
    delete notifierSMS;
    delete notifierTG;

    return 0;
}
