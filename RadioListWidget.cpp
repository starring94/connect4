#include "RadioWidget.hpp"
#include "RadioListWidget.hpp"
#include <vector>

using namespace std;
using namespace genv;

RadioListWidget::RadioListWidget() : BasicWidget()
{
}

RadioListWidget::RadioListWidget(window* parent, int x, int y) : BasicWidget(parent, x, y, 0, 0)
{
}

RadioListWidget::RadioListWidget(window* parent, int x, int y, vector<RadioWidget> list) : BasicWidget(parent, x, y, 0, 0), selectable(list)
{
}

string RadioListWidget::getValues() {
    return BasicWidget::getValues();
}

bool RadioListWidget::isMouseInside(Mouse &mouse) {
    for(RadioWidget x: selectable) {
        if(x.isMouseInside(mouse)) {
            return true;
        }
    }
    return false;
}

void RadioListWidget::drawWidget() {
}

void RadioListWidget::handleWidgetEvent(event event){}

void RadioListWidget::handleWidgetButtonClick(int button, Mouse &mouse){}
