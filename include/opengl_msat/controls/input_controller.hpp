#ifndef OPENGL_MSAT_INPUT_CONTROLLER_HPP
#define OPENGL_MSAT_INPUT_CONTROLLER_HPP

#include <iostream>
#include <utility>
#include "keyboard.hpp"
#include "mouse.hpp"

class SignalList {
public:
    explicit SignalList(std::vector<unsigned int> signals) : signals(std::move(signals)) { }

    bool has(unsigned int signal);

private:
    std::vector<unsigned int> signals;

};

class InputControllerRole {
public:
    virtual void handle(SignalList inputStates) = 0;

};

class InputController {
public:
    void onSignal(unsigned int signal, std::function<void()> func);

    void attach(InputControllerRole* role);

    void process(std::vector<unsigned int> list);

private:
    std::map<unsigned int, std::function<void()>> onSignals;

    std::vector<InputControllerRole*> roles;

};

#endif
