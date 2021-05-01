#ifndef RADIOWIDGET_HPP_INCLUDED
#define RADIOWIDGET_HPP_INCLUDED

#include <CheckboxWidget.hpp>


class RadioWidget : public CheckboxWidget {
public:
    RadioWidget();
    RadioWidget(window* parent, int x, int y, int size);
    RadioWidget(window* parent, int x, int y, int size, std::string label);
    RadioWidget(window* parent, int x, int y, int size, std::string label, bool isChecked);
    virtual void drawWidget();
    virtual bool isMouseInside(Mouse &mouse);
};

#endif // RADIOWIDGET_HPP_INCLUDED
