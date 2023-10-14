#ifndef OPENGL_MSAT_DEV_MESSAGING_HPP
#define OPENGL_MSAT_DEV_MESSAGING_HPP

#include <string>
#include <iostream>

enum MessagingBehavior {
    Silent,
    StdCout,
    StdCerr,
    ThrowException,
};

class DeveloperMessaging {
public:
    static MessagingBehavior noticeBehavior,
        warningBehavior,
        criticalBehavior;

protected:
    static void notice(const std::string& msg)
    {
        handleMessage("NOTICE: " + msg, noticeBehavior);
    }

    static void warn(const std::string& msg)
    {
        handleMessage("WARNING: " + msg, warningBehavior);
    }

    static void critical(const std::string& msg)
    {
        handleMessage("CRITICAL: " + msg, criticalBehavior);
    }

    std::string getClassName()
    {
        return typeid(*this).name();
    }

private:
    static void handleMessage(const std::string& msg, MessagingBehavior behavior)
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

};

#endif
