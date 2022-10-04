#include "Controller.h"

Controller::Controller(View *view)
{
    activeState = INACITVE;
    ledState = LED_OFF;
    this->view = view;
}

Controller::~Controller()
{

}

void Controller::updateEvent(std::string strbtn)
{
    if(activeState == ACTIVE)
    {
        if(strbtn == "ledButton")
        {
            ledState = LED_ON;
            view->setLedState(ledState);
        }
    }
    else if(activeState == INACITVE)
    {
        if(strbtn == "ledActive")
        {
            activeState = ACTIVE;
            view->setActState(activeState);
        }
    }
    
}