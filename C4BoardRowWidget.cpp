#include "C4PieceWidget.hpp"
#include "C4BoardRowWidget.hpp"
#include "C4BoardPartWidget.hpp"
#include "GraphicsAdditions.hpp"
#include <vector>
#include <math.h>

using namespace std;
using namespace genv;

C4BoardRowWidget::C4BoardRowWidget(window* parent, int x, int y, int columnSize, int boardPartSize, int rowNumber, C4Board* board): BasicWidget(parent, x, y, boardPartSize*2, columnSize*2*boardPartSize), m_columnSize(columnSize), m_boardPartSize(boardPartSize), m_rowNumber(rowNumber), m_board(board)
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
    }
    if(event.type == ev_mouse && event.button == btn_left && isMouseInside(_mouse)) {
        handleWidgetButtonClick(event.button, _mouse);
    }
}

void C4BoardRowWidget::handleWidgetButtonClick(int button, Mouse &mouse){
    if(!m_board->getWinCondition()) {
        addNewPiece();
    }
}

bool C4BoardRowWidget::isMouseInside(Mouse &mouse) {
    return mouse.getX() > _x && mouse.getY() > 0 && mouse.getX() < _x + _width && mouse.getY() < _y+_height;
}

void C4BoardRowWidget::drawWidget() {
    if(isMouseInside(_mouse)) {
        vector<int> colors;
        if(m_board->getCurrentPlayer() == 0) {
            colors = {255, 0, 0};
        } else {
            colors = {0, 0, 255};
        }
        int radius = m_boardPartSize;
        for(int dx = -radius; dx <= radius; dx++) {
            for(int dy = -radius; dy <= radius; dy++) {
                if((pow(dx, 2)+pow(dy, 2)) <= pow(radius,2)) {
                    gout << Dot(_x+dx+m_boardPartSize, _y+dy-m_boardPartSize, colors[0], colors[1], colors[2]);
                }
            }
        }
    }
}

string C4BoardRowWidget::getValues()
{
    return "";
}

void C4BoardRowWidget::addNewPiece() {
    if((int)m_pieces.size() != m_columnSize) {
        vector<int> colors;
        if(m_board->getCurrentPlayer() == 0) {
            colors = {255, 0, 0};
        } else {
            colors = {0, 0, 255};
        }
        m_board->handleButtonClick(m_rowNumber, (m_pieces.size() == 0) ? 0 : m_pieces.size());
        m_pieces.push_back(new C4PieceWidget(_parent, _x+m_boardPartSize, _y-5, colors[0], colors[1], colors[2], m_boardPartSize, this, m_boardParts, (m_pieces.size() == 0) ? 0 : m_pieces.size(), m_rowNumber, m_board));
    }
}

vector<C4PieceWidget*> C4BoardRowWidget::getPieces() {
    return m_pieces;
}

int C4BoardRowWidget::getColumnSize() {
    return m_columnSize;
}
