#include "RadioWidget.hpp"
#include "Constants.hpp"
#include "GraphicsAdditions.hpp"
#include "GlobalSettings.hpp"
#include <math.h>

using namespace std;
using namespace genv;
using namespace Constants;

RadioWidget::RadioWidget() : CheckboxWidget()
{
}

RadioWidget::RadioWidget(window* parent, int x, int y, int size) : CheckboxWidget(parent, x+size/2, y, ceil(size/2))
{
}

RadioWidget::RadioWidget(window* parent, int x, int y, int size, string label) : CheckboxWidget(parent, x+size/2, y, ceil(size/2), label)
{
}

RadioWidget::RadioWidget(window* parent, int x, int y, int size, string label, bool isChecked) : CheckboxWidget(parent, x+size/2, y, ceil(size/2), label, isChecked)
{
}

void RadioWidget::drawWidget() {
    int radEx = _width;
    int colors[3] = { 255, 255, 255 };
    if(GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS && isSelected) {
        colors[1] = 0;
        colors[2] = 0;
    } else {
        colors[1] = 255;
        colors[2] = 255;
    }
    gout << Text(_x+_width+BOX_MARGIN, _y+_height/3, _label, colors[0], colors[1], colors[2]);
    for(int dx = -radEx; dx <= radEx; dx++) {
        for(int dy = -radEx; dy<= radEx; dy++) {
            if((pow(dx, 2)+pow(dy, 2)) <= pow(radEx,2)) {
                if((pow(dx, 2)+pow(dy, 2)) <= pow(radEx-2,2)) {
                    if(_isChecked) {
                        if((pow(dx, 2)+pow(dy, 2)) <= pow(radEx-6,2)) {
                            gout << color(colors[0], colors[1], colors[2]);
                        } else {
                            gout << color(0, 0, 0);
                        }
                    } else {
                        gout << color(0, 0, 0);
                    }
                } else {
                    gout << color(colors[0], colors[1], colors[2]);
                }
                gout << move_to(_x+dx, _y+dy) << dot;
            }
        }
    }
}

bool RadioWidget::isMouseInside(Mouse &mouse) {
    return pow(_x-mouse.getX(), 2) + pow(_y-mouse.getY(), 2) <= pow(_width,2);
}
