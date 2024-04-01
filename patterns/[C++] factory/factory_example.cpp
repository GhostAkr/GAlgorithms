#include "factory.hpp"

int main()
{
    IMsgProcessor* emailMsgProcessor = new EmailMsgProcessor();
    emailMsgProcessor->sendUserMsg();
    
    IMsgProcessor* tgMsgProcessor = new TGMsgProcessor();
    tgMsgProcessor->sendUserMsg();
}
