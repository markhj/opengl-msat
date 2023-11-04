#include "opengl_msat/controls/input_controller.hpp"

bool SignalList::has(unsigned int signal)
{
    return std::find(signals.begin(), signals.end(), signal) != signals.end();
}

void InputController::onSignal(unsigned int signal, std::function<void()> func)
{
    onSignals[signal] = std::move(func);
}

void InputController::attach(InputControllerRole *role)
{
    roles.push_back(role);
}

void InputController::process(std::vector<unsigned int> list)
{
    SignalList signalList(list);

    for (InputControllerRole* role : roles) {
        role->handle(signalList);
    }

    for (unsigned int signal : list) {
        auto f = onSignals.find(signal);
        if (f != onSignals.end()) {
            f->second();
        }
    }
}
