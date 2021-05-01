#ifndef SELECTWIDGET_HPP_INCLUDED
#define SELECTWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"
#include <vector>

class SelectWidget : public BasicWidget {
protected:
    std::vector<std::string> _elements;
    int _selected;
    int _scrollTop;
    bool _isOpened;
    int _maxNumberOfParts;
public:
    SelectWidget();
    SelectWidget(window* parent, int x, int y, int width);
    SelectWidget(window* parent, int x, int y, int width, std::vector<std::string> elements, int selected, int maxNumberOfParts);
    virtual bool isMouseInside(Mouse &mouse);
    int isMouseInsidePart(Mouse &mouse, int partId);
    int getPartIdWithMouseInside(Mouse &mouse);
    virtual void drawWidget();
    virtual void handleWidgetEvent(genv::event event);
    virtual void handleWidgetButtonClick(int button, Mouse &mouse);
    virtual std::string getValues();
    int getSelected();
    std::vector<std::string> getElements();
    void addToElements(std::string element);
    void addListToElements(std::vector<std::string> elements);
    void removeElementFromList(int position);
    void toggleOpen();
    void setSelectedValue(int val);
    std::string fitTextInBox(std::string text, int num = 0);
};


#endif // SELECTWIDGET_HPP_INCLUDED
