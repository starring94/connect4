#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "BasicWidget.hpp"

class StaticTextWidget: public BasicWidget {
protected:
    std::string _text;
public:
    StaticTextWidget();
    StaticTextWidget(window* parent, int x, int y, int width, int height);
    StaticTextWidget(window* parent, int x, int y, int width, int height, std::string text);
    virtual std::string getValues();
    virtual void drawWidget();
    virtual void handleWidgetEvent(genv::event event);
    std::string getText();
    void setText(std::string text);
};

#endif // STATICTEXT_HPP_INCLUDED
