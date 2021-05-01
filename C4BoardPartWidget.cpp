#include "C4BoardPartWidget.hpp"
#include "C4PieceWidget.hpp"
#include "GraphicsAdditions.hpp"
#include "Constants.hpp"
#include <math.h>

using namespace std;
using namespace genv;
using namespace Constants;

C4BoardPartWidget::C4BoardPartWidget(window* parent, int x, int y): BasicWidget(parent, x, y, 0, 0), m_radius(15), m_relativePositionX(0), m_relativePositionY(0)
{
}

void C4BoardPartWidget::handleWidgetEvent(event event) {
}

bool C4BoardPartWidget::isMouseInside(Mouse& mouse) {
    return (_x >= mouse.getX() && _y >= mouse.getY() && _x+15 <= mouse.getX() && _y+15 <= mouse.getY()) && !(pow(_x-mouse.getX(), 2) + pow(_y-mouse.getY(), 2) <= pow(_width,2));
}

void C4BoardPartWidget::drawWidget() {
    int radius = 15;
    int trueRad = radius;
    gout << Box(_x-radius, _y-radius, radius*2+1, radius*2+1, 255, 255, 255);
    for(int dx = -trueRad; dx <= trueRad; dx++) {
        for(int dy = -trueRad; dy <= trueRad; dy++) {
            if((pow(dx, 2)+pow(dy, 2)) <= pow(trueRad,2)) {
                if((pow(dx, 2)+pow(dy-25, 2)) <= pow(trueRad, 2)) {
                    gout << Dot(_x+dx, _y-25+dy, 255, 0, 0);
                } else {
                    gout << Dot(_x+dx, _y+dy, 100, 100, 100);
                }
                gout << Dot(_x+dx, _y+dy, 0, 0, 0);
            }
        }
    }
}

string C4BoardPartWidget::getValues() {
    return "";
}

void C4BoardPartWidget::updateRelativePositionFromPiece(C4PieceWidget widget) {
    m_relativePositionX = _x - widget->getPosition()[0];
    m_relativePositionY = _y - widget->getPosition()[1];
}
