#include "BasicWidget.hpp"
#include "graphics.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace genv;

BasicWidget::BasicWidget() : _x(0), _y(0), _width(0), _height(0), _mouse(Mouse(0, 0))
{
}

BasicWidget::BasicWidget(window* parent, int x, int y, int width, int height) : _parent(parent), _x(x), _y(y), _width(width), _height(height), _mouse(Mouse(0, 0))
{
    parent->addToWidgets(this);
}

bool BasicWidget::isMouseInside(Mouse &mouse) {
    return mouse.getX() > _x && mouse.getY() > _y && mouse.getX() < _x+_width && mouse.getY() < _y+_height;
}

string BasicWidget::getValues() {
    return "type=CLASS(" + ((string)typeid(*this).name()).substr(2) +
            ")\nposX=INT(" + to_string(_x) +
            ")\nposY=INT(" + to_string(_y) +
            ")\nwidth=INT(" + to_string(_width) +
            ")\nheight=INT(" + to_string(_height) +
            ")\nmouseX=INT(" + to_string(_mouse.getX()) +
            ")\nmouseY=INT(" + to_string(_mouse.getY()) +
            ")\nisSelected=BOOLEAN(" + ((isSelected) ? "TRUE" : "FALSE") + ")";
}

vector<int> getPosition() {
    return { _x, _y };
}

void BasicWidget::setMouseValue(int x, int y) {
    _mouse.setValue(x, y);
}

void BasicWidget::setSelected(bool yes) {
    isSelected = yes;
}

Mouse BasicWidget::getMouse() {
    return _mouse;
}
