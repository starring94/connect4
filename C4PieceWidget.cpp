#include "C4PieceWidget.hpp"
#include "GraphicsAdditions.hpp"
#include "Constants.hpp"
#include <math.h>

using namespace std;
using namespace genv;
using namespace Constants;

C4PieceWidget::C4PieceWidget(window* parent, int x, int y, int r, int g, int b): BasicWidget(parent, x, y, 0, 0), m_r(r), m_g(g), m_b(b)
{
}

void C4PieceWidget::handleWidgetEvent(event event) {
}

bool C4PieceWidget::isMouseInside(Mouse& mouse) {
    return pow(_x-mouse.getX(), 2) + pow(_y-mouse.getY(), 2) <= pow(_width,2);
}

void C4PieceWidget::drawWidget() {
    int radius = 15;
    for(int dx = -radius; dx <= radius; dx++) {
        for(int dy = -radius; dy <= radius; dy++) {
            if((pow(dx, 2)+pow(dy, 2)) <= pow(radius,2)) {
                gout << Dot(_x+dx, _y+dy, m_r, m_g, m_b);
            }
        }
    }
}

string C4PieceWidget::getValues() {
    return "";
}
