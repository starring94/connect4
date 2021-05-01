#ifndef NUMBERWIDGET_HPP_INCLUDED
#define NUMBERWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"

class NumberWidget: public BasicWidget {
protected:
    int _lowerBound;
    int _upperBound;
    int _currentNumber;
public:
    NumberWidget();
    NumberWidget(window* parent, int x, int y, int width);
    NumberWidget(window* parent, int x, int y, int width, int lowerBound, int upperBound);
    NumberWidget(window* parent, int x, int y, int width, int lowerBound, int upperBound, int startingNumber);
    bool isMouseInsideLeft(Mouse &mouse);
    bool isMouseInsideChanger(Mouse &mouse, int direction = 0); // 0 = fel, 1 = le
    virtual std::string getValues();
    virtual void drawWidget();
    virtual void handleWidgetEvent(genv::event event);
    virtual void handleWidgetButtonClick(int button, Mouse &mouse);
    virtual void handleWidgetKeyPress(int keycode);
    void handleNumberChange(bool isGrowing = true, int number = 1);
    int getLowerBound();
    int getUpperBound();
    int getCurrentNumber();
    void setLowerBound(int num);
    void setUpperBound(int num);
    void setCurrentNumber(int num);
};


#endif // NUMBERWIDGET_HPP_INCLUDED
