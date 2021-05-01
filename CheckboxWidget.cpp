#include "CheckboxWidget.hpp"
#include "Constants.hpp"
#include "GraphicsAdditions.hpp"
#include "GlobalSettings.hpp"
#include <string>

using namespace std;
using namespace genv;
using namespace Constants;

CheckboxWidget::CheckboxWidget() : BasicWidget(), _isChecked(false), _label("Empty")
{
}

CheckboxWidget::CheckboxWidget(window* parent, int x, int y, int size) : BasicWidget(parent, x, y, size, size), _isChecked(false), _label("Empty")
{
}

CheckboxWidget::CheckboxWidget(window* parent, int x, int y, int size, string label) : BasicWidget(parent, x, y, size, size), _isChecked(false), _label(label)
{
}

CheckboxWidget::CheckboxWidget(window* parent, int x, int y, int size, string label, bool isChecked) : BasicWidget(parent, x, y, size, size), _isChecked(isChecked), _label(label)
{
}

string CheckboxWidget::getValues() {
    return BasicWidget::getValues() + ";isChecked=" + to_string(_isChecked) + ";label=" + _label;
}

void CheckboxWidget::drawWidget() {
    int colors[3] = { 255, 255, 255 };
    if(GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS && isSelected) {
        colors[1] = 0;
        colors[2] = 0;
    } else {
        colors[1] = 255;
        colors[2] = 255;
    }
    gout << Box(_x, _y, _width, _height, colors[0], colors[1], colors[2]);
    gout << Box(_x+BOX_BORDER, _y+BOX_BORDER, _width-BOX_BORDER*2, _height-BOX_BORDER*2, 0, 0, 0);
    gout << Text(_x+_width+BOX_MARGIN, _y+_width/2+5, _label, colors[0], colors[1], colors[2]);
    if(_isChecked) {
        gout << move_to(_x+_width-BOX_BORDER-LENGTH_FROM_BORDER, _y+BOX_BORDER+LENGTH_FROM_BORDER) << color(colors[0], colors[1], colors[2]) << line_to(_x+_width/3, _y+_height-LENGTH_FROM_BORDER-BOX_BORDER);
        gout << move_to(_x+_width/3, _y+_height-LENGTH_FROM_BORDER-BOX_BORDER) << color(colors[0], colors[1], colors[2]) << line_to(_x+BOX_BORDER+LENGTH_FROM_BORDER, _y+_height/2);
    }
}

void CheckboxWidget::handleWidgetEvent(event event){
    if(event.type == ev_mouse && event.button == btn_left) {
        Mouse mouse(event.pos_x, event.pos_y);
        handleWidgetButtonClick(event.button, mouse);
    }
}

void CheckboxWidget::handleWidgetButtonClick(int button, Mouse &mouse){
    if(isMouseInside(mouse)) {
        toggleChecked();
    }
}

bool CheckboxWidget::isChecked() {
    return _isChecked;
}

string CheckboxWidget::getLabel() {
    return _label;
}

void CheckboxWidget::toggleChecked() {
    _isChecked = !_isChecked;
}

void CheckboxWidget::setChecked(bool isTrue) {
    _isChecked = isTrue;
}

void CheckboxWidget::setLabel(string label) {
    _label = label;
}
