#ifndef C4PIECEWIDGET_HPP_INCLUDED
#define C4PIECEWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"
#include "C4BoardPartWidget.hpp"
#include "C4BoardRowWidget.hpp"

class C4BoardRowWidget;
class C4BoardPartWidget;

class C4PieceWidget : public BasicWidget {
protected:
    int m_r;
    int m_g;
    int m_b;
    int m_partSize;
    C4BoardRowWidget* m_parentRow;
    std::vector<C4BoardPartWidget*> m_partPieces;
    int m_columnNumber;
    int m_rowNumber;
public:
    C4PieceWidget(window* parent, int x, int y, int r, int g, int b, int partSize);
    C4PieceWidget(window* parent, int x, int y, int r, int g, int b, int partSize, C4BoardRowWidget* parentRow, std::vector<C4BoardPartWidget*> partPieces, int columnNumber, int rowNumber);
    virtual void handleWidgetEvent(genv::event event);
    virtual bool isMouseInside(Mouse &mouse);
    virtual void drawWidget();
    void moveWidget();
    virtual std::string getValues();
};

#endif // C4PIECEWIDGET_HPP_INCLUDED
