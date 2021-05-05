#include "C4PieceWidget.hpp"
#include "C4BoardRowWidget.hpp"
#include "C4BoardPartWidget.hpp"
#include "GraphicsAdditions.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

C4BoardRowWidget::C4BoardRowWidget(window* parent, int x, int y, int columnSize, int boardPartSize, int rowNumber): BasicWidget(parent, x, y, boardPartSize*2, columnSize*2*boardPartSize), m_columnSize(columnSize), m_boardPartSize(boardPartSize), m_rowNumber(rowNumber)
{
    for(int i = 0; i < columnSize; i++) {
        m_boardParts.push_back(new C4BoardPartWidget(parent, x, y+(i)*boardPartSize*2, boardPartSize));
    }
}

void C4BoardRowWidget::handleWidgetEvent(event event)
{
    Mouse mouse(event.pos_x, event.pos_y);
    if(event.pos_x != 0 || event.pos_y != 0) {
        _mouse = mouse;
        //cout << event.pos_x << " " << event.pos_y << endl;
        //cout << _width << " " << _height << endl;
        //cout << (mouse.getX() > _x && mouse.getY() > _y && mouse.getX() < _x+_width && mouse.getY() < _y+_height) << endl;
    }
    if(event.type == ev_mouse && event.button == btn_left) {
        handleWidgetButtonClick(event.button, _mouse);
    }
}

void C4BoardRowWidget::handleWidgetButtonClick(int button, Mouse &mouse){
    if(isMouseInside(mouse)) {
        addNewPiece();
    }
}

bool C4BoardRowWidget::isMouseInside(Mouse &mouse) {
    return mouse.getX() > _x && mouse.getY() > 0 && mouse.getX() < _x + _width && mouse.getY() < _y+_height;
}

void C4BoardRowWidget::drawWidget() {
    gout << Box(_x, _y-5-m_boardPartSize*2, _width, _height, 155, 255, 255);
}

string C4BoardRowWidget::getValues()
{
    return "";
}

void C4BoardRowWidget::addNewPiece() {
    // c4_1 = new C4PieceWidget(this, 500, 100-5, 255, 0, 0);
    if((int)m_pieces.size() != m_columnSize) {
        m_pieces.push_back(new C4PieceWidget(_parent, _x+m_boardPartSize, _y-5, 255, 0, 0, m_boardPartSize, this, m_boardParts, (m_pieces.size() == 0) ? 0 : m_pieces.size(), m_rowNumber));
    }
}

vector<C4PieceWidget*> C4BoardRowWidget::getPieces() {
    return m_pieces;
}

int C4BoardRowWidget::getColumnSize() {
    return m_columnSize;
}
