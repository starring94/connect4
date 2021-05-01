#ifndef BasicWidget_HPP_INCLUDED
#define BasicWidget_HPP_INCLUDED

#include "graphics.hpp"
#include "window.hpp"
#include "mouse.hpp"

class BasicWidget {
protected:
    window *_parent;
    int _x, _y, _width, _height;
    Mouse _mouse;
    bool isSelected = false;
public:
    BasicWidget();
    BasicWidget(window* parent, int x, int y, int width, int height);
    BasicWidget(int x, int y, int width, int height);
    virtual void handleWidgetEvent(genv::event event) = 0;
    virtual bool isMouseInside(Mouse &mouse);
    virtual void drawWidget() = 0;
    virtual std::string getValues();
    std::vector<int> getPosition();
    void setMouseValue(int x, int y);
    void setSelected(bool yes);
    Mouse getMouse();
};

#endif // BasicWidget_HPP_INCLUDED
