#ifndef MESSAGEBUTTONWIDGET_HPP_INCLUDED
#define MESSAGEBUTTONWIDGET_HPP_INCLUDED

#include "BaseButtonWidget.hpp"

class MessageButtonWidget : public BaseButtonWidget
{
protected:
    std::string m_id;
public:
    MessageButtonWidget(window* parent, int x, int y, int width, int height, std::string text, bool p_isStorable, bool p_isPressedDown, std::string message);
    virtual void handleWidgetAction();
    std::string getId();
    void setId(std::string val);
};

#endif // MESSAGEBUTTONWIDGET_HPP_INCLUDED
