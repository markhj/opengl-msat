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
    static void notice(const std::string& msg);

    static void warn(const std::string& msg);

    static void critical(const std::string& msg);

    std::string getClassName();

private:
    static void handleMessage(const std::string& msg, MessagingBehavior behavior);

};

#endif
