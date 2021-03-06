#ifndef C4BOARDWIDGET_HPP_INCLUDED
#define C4BOARDWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"
#include "C4Board.hpp"
#include "C4BoardRowWidget.hpp"

class C4Board;
class C4BoardRowWidget;

class C4BoardWidget : public BasicWidget {
protected:
    std::vector<C4BoardRowWidget*> m_boardRows;
    int m_numberOfRows;
    int m_numberOfColumns;
    int m_partSize;
    C4Board* m_board;
public:
    C4BoardWidget(window* parent, int x, int y, int numberOfRows, int numberOfColumns, int partSize, C4Board* board);
    virtual void handleWidgetEvent(genv::event event);
    virtual bool isMouseInside(Mouse &mouse);
    virtual void drawWidget();
    virtual std::string getValues();
};

#endif // C4BOARDWIDGET_HPP_INCLUDED
