#ifndef C4PIECEWIDGET_HPP_INCLUDED
#define C4PIECEWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"

class C4PieceWidget : public BasicWidget {
protected:
    int m_r;
    int m_g;
    int m_b;
public:
    C4PieceWidget(window* parent, int x, int y, int r, int g, int b);
    virtual void handleWidgetEvent(genv::event event);
    virtual bool isMouseInside(Mouse &mouse);
    virtual void drawWidget();
    virtual std::string getValues();
};

#endif // C4PIECEWIDGET_HPP_INCLUDED
