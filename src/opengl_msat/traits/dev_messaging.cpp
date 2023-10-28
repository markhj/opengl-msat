#include "opengl_msat/traits/dev_messaging.hpp"

MessagingBehavior DeveloperMessaging::noticeBehavior = MessagingBehavior::StdCout;
MessagingBehavior DeveloperMessaging::warningBehavior = MessagingBehavior::StdCerr;
MessagingBehavior DeveloperMessaging::criticalBehavior = MessagingBehavior::ThrowException;

void DeveloperMessaging::notice(const std::string &msg)
{
    handleMessage("NOTICE: " + msg, noticeBehavior);
}

void DeveloperMessaging::warn(const std::string &msg)
{
    handleMessage("WARNING: " + msg, warningBehavior);
}

void DeveloperMessaging::critical(const std::string &msg)
{
    handleMessage("CRITICAL: " + msg, criticalBehavior);
}

std::string DeveloperMessaging::getClassName()
{
    return typeid(*this).name();
}

void DeveloperMessaging::handleMessage(const std::string &msg, MessagingBehavior behavior)
{
    switch (warningBehavior) {
        case MessagingBehavior::Silent:
            break;
        case MessagingBehavior::ThrowException:
            throw std::runtime_error(msg);
        case MessagingBehavior::StdCout:
            std::cout << msg << std::endl;
            break;
        case MessagingBehavior::StdCerr:
            std::cerr << msg << std::endl;
            break;
    }
}
