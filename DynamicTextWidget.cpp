#include "DynamicTextWidget.hpp"
#include "GraphicsAdditions.hpp"
#include "GlobalSettings.hpp"
#include "Constants.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using namespace genv;
using namespace Constants;

DynamicTextWidget::DynamicTextWidget() : StaticTextWidget()
{
}

DynamicTextWidget::DynamicTextWidget(window* parent, int x, int y, int width, int height) : StaticTextWidget(parent, x, y, width, height)
{
}

DynamicTextWidget::DynamicTextWidget(window* parent, int x, int y, int width, int height, string text) : StaticTextWidget(parent, x, y, width, height, text)
{
}

void DynamicTextWidget::drawWidget() {
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
    int getHeight = count(_text.begin(), _text.end(), '\n') == 0 ? -10 : -12*(count(_text.begin(), _text.end(), '\n')+1);
    gout << Text(_x+BOX_BORDER*3, _y+_height+getHeight, _text, colors[0], colors[1], colors[2]);
}

void DynamicTextWidget::handleWidgetEvent(event event) {
    if(event.type == ev_key) {
        if(event.keycode == 65546) {
            isShift = true;
            cout << "shift on" << endl;
        } else if(event.keycode == -65546) {
            isShift = false;
            cout << "shift off" << endl;
        }
        handleWidgetKeyPress(event.keycode);
    }
}

void DynamicTextWidget::handleWidgetKeyPress(int keycode) {
    if((keycode >= 32 && keycode <= 127)) {
        _text += keycode;
        //_width = gout.twidth(_text);
    }
    if(keycode == key_backspace) {
        _text = ((int)_text.size()-1 != 0) ? _text.substr(0, _text.size()-1) : "";
        //_width = ((int)_text.size() != 0) ? gout.twidth(_text) : 20;
    }
    if(keycode == key_enter) {
        _text += '\n';
    }
}
