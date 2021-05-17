#ifndef C4BOARDROWWIDGET_HPP_INCLUDED
#define C4BOARDROWWIDGET_HPP_INCLUDED

#include "BasicWidget.hpp"
#include "C4BoardPartWidget.hpp"
#include "C4PieceWidget.hpp"
#include "C4Board.hpp"
#include <vector>

class C4Board;
class C4PieceWidget;
class C4BoardPartWidget;

class C4BoardRowWidget : public BasicWidget {
protected:
    int m_columnSize;
    int m_boardPartSize;
    std::vector<C4PieceWidget*> m_pieces;
    std::vector<C4BoardPartWidget*> m_boardParts;
    int m_rowNumber;
    C4Board* m_board;
public:
    C4BoardRowWidget(window* parent, int x, int y, int columnSize, int boardPartSize, int rowNumber, C4Board* board);
    virtual void handleWidgetEvent(genv::event event);
    virtual void handleWidgetButtonClick(int button, Mouse &mouse);
    virtual bool isMouseInside(Mouse &mouse);
    virtual void drawWidget();
    virtual std::string getValues();
    void addNewPiece();
    std::vector<C4PieceWidget*> getPieces();
    int getColumnSize();
};

#endif // C4BOARDROWWIDGET_HPP_INCLUDED
