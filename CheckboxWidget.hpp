#ifndef CHECKBOXWIDGET_HPP_INCLUDED
#define CHECKBOXWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"

class CheckboxWidget: public BasicWidget {
protected:
    bool _isChecked;
    std::string _label;
public:
    CheckboxWidget();
    CheckboxWidget(window* parent, int x, int y, int size);
    CheckboxWidget(window* parent, int x, int y, int size, std::string label);
    CheckboxWidget(window* parent, int x, int y, int size, std::string label, bool isChecked);
    virtual std::string getValues();
    virtual void drawWidget();
    virtual void handleWidgetEvent(genv::event event);
    virtual void handleWidgetButtonClick(int button, Mouse &mouse);
    bool isChecked();
    std::string getLabel();
    void toggleChecked();
    void setChecked(bool isTrue);
    void setLabel(std::string label);
};

#endif // CHECKBOXWIDGET_HPP_INCLUDED
