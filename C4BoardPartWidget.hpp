#ifndef C4BOARDPARTWIDGET_HPP_INCLUDED
#define C4BOARDPARTWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"
#include "C4PieceWidget.hpp"

class C4PieceWidget;

class C4BoardPartWidget : public BasicWidget {
protected:
    int m_radius;
    int m_relativePositionX;
    int m_relativePositionY;
public:
    C4BoardPartWidget(window* parent, int x, int y, int partSize);
    virtual void handleWidgetEvent(genv::event event);
    //virtual bool isMouseInside(Mouse &mouse);
    virtual void drawWidget();
    virtual std::string getValues();
    void updateRelativePositionFromPiece(C4PieceWidget* widget);
};

#endif // C4BOARDPARTWIDGET_HPP_INCLUDED
