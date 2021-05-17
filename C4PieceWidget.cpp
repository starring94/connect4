#include "C4PieceWidget.hpp"
#include "GraphicsAdditions.hpp"
#include "Constants.hpp"
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
using namespace genv;
using namespace Constants;

C4PieceWidget::C4PieceWidget(window* parent, int x, int y, int r, int g, int b, int partSize, C4Board* board): BasicWidget(parent, x, y, 0, 0), m_r(r), m_g(g), m_b(b), m_partSize(partSize), m_parentRow(new C4BoardRowWidget(parent, x, y, -1, 0, 0, board)), m_partPieces({}), m_columnNumber(0), m_rowNumber(0), m_board(board)
{
}

C4PieceWidget::C4PieceWidget(window* parent, int x, int y, int r, int g, int b, int partSize, C4BoardRowWidget* parentRow, vector<C4BoardPartWidget*> partPieces, int columnNumber, int rowNumber, C4Board* board): BasicWidget(parent, x, y, 0, 0), m_r(r), m_g(g), m_b(b), m_partSize(partSize),  m_parentRow(parentRow), m_partPieces(partPieces), m_columnNumber(columnNumber), m_rowNumber(rowNumber), m_board(board)
{
}

void C4PieceWidget::handleWidgetEvent(event event) {
}

bool C4PieceWidget::isMouseInside(Mouse& mouse) {
    return pow(_x-mouse.getX(), 2) + pow(_y-mouse.getY(), 2) <= pow(_width,2);
}

void C4PieceWidget::drawWidget() {
    int radius = m_partSize;
    for(int dx = -radius; dx <= radius; dx++) {
        for(int dy = -radius; dy <= radius; dy++) {
            if((pow(dx, 2)+pow(dy, 2)) <= pow(radius,2)) {
                gout << Dot(_x+dx, _y+dy, m_r, m_g, m_b);
            }
        }
    }
    moveWidget();
}

void C4PieceWidget::moveWidget() {
    int val = m_parentRow->getColumnSize() - 1 - m_columnNumber;
    if(_y < m_partPieces[val]->getPosition()[1]+m_partSize) {
        _y+=5;
        vector<int> yPos;
        for(size_t i = 0; i < m_partPieces.size(); i++) {
            yPos.push_back(abs(m_partPieces[i]->getPosition()[1]-_y));
        }
    }
}

string C4PieceWidget::getValues() {
    return "";
}
