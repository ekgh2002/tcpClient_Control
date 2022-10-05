#include "Controller.h"
#include <string.h>
#include <iostream>

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
    if(activeState == ACTIVE && ledState == LED_OFF)
    {
        if(strbtn == "ledButton")
        {
            std::cout << "LED ON!!!" << std::endl;
            ledState = LED_ON;
            view->setLedState(ledState);
        }
    }
    else if(activeState == ACTIVE && ledState == LED_ON)
    {
        if(strbtn == "ledButton")
        {
            std::cout << "LED OFF!!!" << std::endl;
            ledState = LED_OFF;
            view->setLedState(ledState);
        }
    }
}

void Controller::updateEvent(char* str)
{
    if(activeState == INACITVE)
    {
        if(strncmp(str, "ledActive", strlen("ledActive")-1) == 0)
        {
            std::cout << "LED 활성화!!!" << std::endl;
            activeState = ACTIVE;
            view->setActState(activeState);
        }
    }
    else if(activeState == ACTIVE)
    {
        if(strncmp(str, "ledInActive", strlen("ledInActive")-1) == 0)
        {
            std::cout << "LED 비활성화!!!" << std::endl;
            activeState = INACITVE;
            view->setActState(activeState);
        }
    }
}