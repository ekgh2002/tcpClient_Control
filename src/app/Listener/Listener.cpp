#include "Listener.h"

Listener::Listener(Button *ledButton, Button *clientButton, Controller *controller)
{
    this->ledButton = ledButton;
    this->clientButton = clientButton;
    this->controller = controller;
}

Listener::~Listener()
{

}

void Listener::checkEvent()
{
    if(ledButton->getState() == RELEASE_ACTIVE)
        controller->updateEvent("ledButton");

    if(clientButton->getState() == RELEASE_ACTIVE)
        controller->updateEvent("clientButton");
}