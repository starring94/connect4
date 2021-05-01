#ifndef RADIOLISTWIDGET_HPP_INCLUDED
#define RADIOLISTWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"
#include "RadioWidget.hpp"
#include <vector>

class RadioListWidget : public BasicWidget {
protected:
    std::vector<RadioWidget> selectable;
public:
    RadioListWidget();
    RadioListWidget(window* parent, int x, int y);
    RadioListWidget(window* parent, int x, int y, std::vector<RadioWidget> list);
    virtual std::string getValues();
    virtual bool isMouseInside(Mouse &mouse);
    virtual void drawWidget();
    virtual void handleWidgetEvent(genv::event event);
    virtual void handleWidgetButtonClick(int button, Mouse &mouse);
    void addElementToList(RadioWidget radioelement);
    std::vector<std::string> getList();
    void setChecked(int id);
};

#endif // RADIOLISTWIDGET_HPP_INCLUDED
