#include "C4BoardPartWidget.hpp"
#include "C4PieceWidget.hpp"
#include "GraphicsAdditions.hpp"
#include "Constants.hpp"
#include <math.h>

using namespace std;
using namespace genv;
using namespace Constants;

C4BoardPartWidget::C4BoardPartWidget(window* parent, int x, int y, int partSize): BasicWidget(parent, x, y, partSize*2, partSize*2), m_radius(partSize), m_relativePositionX(0), m_relativePositionY(0)
{
}

void C4BoardPartWidget::handleWidgetEvent(event event) {
}

/*bool C4BoardPartWidget::isMouseInside(Mouse& mouse) {
    return (_x >= mouse.getX() && _y >= mouse.getY() && _x+15 <= mouse.getX() && _y+15 <= mouse.getY()) && !(pow(_x-mouse.getX(), 2) + pow(_y-mouse.getY(), 2) <= pow(_width,2));
}*/

void C4BoardPartWidget::drawWidget() {
    if(m_radius != -1) {
        gout << Box(_x, _y, m_radius*2, m_radius*2, 255, 255, 255);
        for(int dx = -m_radius; dx <= m_radius; dx++) {
            for(int dy = -m_radius; dy <= m_radius; dy++) {
                if((pow(dx, 2)+pow(dy, 2)) <= pow(m_radius,2)) {
                    if((pow(dx-m_relativePositionX-m_radius*2, 2)+pow(dy-m_relativePositionY-m_radius, 2)) <= pow(m_radius, 2)) {
                        gout << Dot(_x-m_relativePositionX+dx, _y-m_relativePositionY+dy, 255, 0, 0);
                    }/* else {
                        gout << Dot(_x+dx, _y+dy, 100, 100, 100);
                    }*/
                    gout << Dot(_x+dx+m_radius, _y+dy+m_radius, 0, 0, 0);
                }
            }
        }
    }
}

string C4BoardPartWidget::getValues() {
    return "";
}

void C4BoardPartWidget::updateRelativePositionFromPiece(C4PieceWidget* widget) {
    m_relativePositionX = _x - widget->getPosition()[0];
    m_relativePositionY = _y - widget->getPosition()[1];
}
