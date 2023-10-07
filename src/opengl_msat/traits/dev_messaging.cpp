#include "opengl_msat/traits/dev_messaging.hpp"

MessagingBehavior DeveloperMessaging::noticeBehavior = MessagingBehavior::StdCout;
MessagingBehavior DeveloperMessaging::warningBehavior = MessagingBehavior::StdCerr;
MessagingBehavior DeveloperMessaging::criticalBehavior = MessagingBehavior::ThrowException;
