#ifndef LISTENER_H
#define LISTENER_H

#pragma once

#include "Button.h"
#include "tcpClient.h"
#include "Led.h"
#include "Controller.h"

class Listener
{
private:
    Button *ledButton;
    Button *clientButton;
    Controller *controller;

public:
    Listener(Button *ledButton, Button *clientButton, Controller *controller);
    ~Listener();
    void checkEvent();
};

#endif