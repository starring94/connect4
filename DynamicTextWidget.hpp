#ifndef DYNAMICTEXTWIDGET_HPP_INCLUDED
#define DYNAMICTEXTWIDGET_HPP_INCLUDED

#include "StaticTextWidget.hpp"

class DynamicTextWidget : public StaticTextWidget {
protected:
    bool isShift = false;
public:
    DynamicTextWidget();
    DynamicTextWidget(window* parent, int x, int y, int width, int height);
    DynamicTextWidget(window* parent, int x, int y, int width, int height, std::string text);
    virtual void drawWidget();
    virtual void handleWidgetEvent(genv::event event);
    virtual void handleWidgetKeyPress(int keycode);
};

#endif // DYNAMICTEXTWIDGET_HPP_INCLUDED
