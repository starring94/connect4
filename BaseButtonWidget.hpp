#ifndef BASEBUTTONWIDGET_HPP_INCLUDED
#define BASEBUTTONWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"

class BaseButtonWidget : public BasicWidget {
protected:
    bool m_isStorable;
    bool m_isPressedDown;
    std::string m_text;
public:
    BaseButtonWidget();
    BaseButtonWidget(window* parent, int x, int y, int width, int height, std::string text, bool p_isStorable, bool p_isPressedDown);
    virtual std::string getValues();
    virtual void drawWidget();
    virtual void handleWidgetEvent(genv::event event);
    virtual void handleWidgetButtonClick(int button, Mouse &mouse);
    virtual void handleWidgetAction() = 0;
    bool isStorable();
    bool isPressedDown();
    std::string getText();
    void setStorable(bool value);
    void toggledPressedDown();
    void setText(std::string text);
};

#endif // BASEBUTTONWIDGET_HPP_INCLUDED
