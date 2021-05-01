#include "StaticTextWidget.hpp"
#include "GraphicsAdditions.hpp"
#include "GlobalSettings.hpp"

using namespace std;
using namespace genv;

StaticTextWidget::StaticTextWidget() : BasicWidget(), _text("")
{
}

StaticTextWidget::StaticTextWidget(window* parent, int x, int y, int width, int height) : BasicWidget(parent, x, y, width, height), _text("")
{
}

StaticTextWidget::StaticTextWidget(window* parent, int x, int y, int width, int height, string text) : BasicWidget(parent, x, y, width, height), _text(text)
{
}

string StaticTextWidget::getValues() {
    return BasicWidget::getValues() + ";text=" + _text;
}

void StaticTextWidget::drawWidget() {
    int colors[3] = { 255, 255, 255 };
    if(GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS && isSelected) {
        colors[1] = 0;
        colors[2] = 0;
    } else {
        colors[1] = 255;
        colors[2] = 255;
    }
    gout << Text(_x, _y, _text, colors[0], colors[1], colors[2]);
}

void StaticTextWidget::handleWidgetEvent(genv::event event) {}

string StaticTextWidget::getText() {
    return _text;
}

void StaticTextWidget::setText(string text) {
    _text = text;
}
