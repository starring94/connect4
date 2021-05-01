#include "NumberWidget.hpp"
#include "Constants.hpp"
#include "GlobalSettings.hpp"
#include "GraphicsAdditions.hpp"
#include <iostream>
#include <string>

using namespace genv;
using namespace std;
using namespace Constants;

NumberWidget::NumberWidget() : BasicWidget(), _lowerBound(-2147483648), _upperBound(2147483647), _currentNumber(0)
{
}

NumberWidget::NumberWidget(window* parent, int x, int y, int width): BasicWidget(parent, x, y, width, 30), _lowerBound(-2147483648), _upperBound(2147483647), _currentNumber(0)
{
}

NumberWidget::NumberWidget(window* parent, int x, int y, int width, int lowerBound, int upperBound): BasicWidget(parent, x, y, width, 30), _lowerBound(lowerBound), _upperBound(upperBound), _currentNumber(0)
{
    if(_currentNumber < _lowerBound) {
        _currentNumber = _lowerBound;
    } else if(_currentNumber > _upperBound) {
        _currentNumber = _upperBound;
    }
}

NumberWidget::NumberWidget(window* parent, int x, int y, int width, int lowerBound, int upperBound, int startingNumber): BasicWidget(parent, x, y, width, 30), _lowerBound(lowerBound), _upperBound(upperBound), _currentNumber(startingNumber)
{
    if(_currentNumber < _lowerBound) {
        _currentNumber = _lowerBound;
    } else if(_currentNumber > _upperBound) {
        _currentNumber = _upperBound;
    }
}

bool NumberWidget::isMouseInsideChanger(Mouse &mouse, int direction) {
    if(direction == 0) {
        return mouse.getX() > _x+_width-40 && mouse.getX() < _x+_width && mouse.getY() > _y && mouse.getY() < _y+_height/2;
    }
    if(direction == 1) {
        return mouse.getX() > _x+_width-40 && mouse.getX() < _x+_width && mouse.getY()+_height/2 > _y && mouse.getY() < _y+_height;
    }
    return false;
}

string NumberWidget::getValues() {
    return BasicWidget::getValues() +
            "\nlowerBound=INT(" + to_string(_lowerBound) +
            ")\nupperBound=INT(" + to_string(_upperBound) +
            ")\ncurrentNumber=INT(" + to_string(_currentNumber) +
            ")\n";
}

void NumberWidget::drawWidget() {
    int bgColorsTop[3] = {0, 0, 0};
    int bgColorsBottom[3] = {0, 0, 0};
    int colors[3] = { 255, 255, 255 };
    if(GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS && isSelected) {
        colors[1] = 0;
        colors[2] = 0;
    } else {
        colors[1] = 255;
        colors[2] = 255;
    }
    if(isMouseInsideChanger(_mouse, 0)) {
        bgColorsTop[0] = 150;
        bgColorsTop[1] = 150;
        bgColorsTop[2] = 150;
    } else if(isMouseInsideChanger(_mouse, 1)) {
        bgColorsBottom[0] = 150;
        bgColorsBottom[1] = 150;
        bgColorsBottom[2] = 150;
    }
    gout << Box(_x, _y, _width, _height, colors[0], colors[1], colors[2]);
    gout << Box(_x+BOX_BORDER, _y+BOX_BORDER, _width-BOX_BORDER*2, _height-BOX_BORDER*2, 0, 0, 0);
    gout << Box(_x+_width-40, _y, BOX_BORDER, _height, colors[0], colors[1], colors[2]);
    gout << Box(_x+_width-(40-BOX_BORDER), _y+BOX_BORDER, (40-BOX_BORDER*2), _height/2-BOX_BORDER, bgColorsTop[0], bgColorsTop[1], bgColorsTop[2]);
    gout << Line(_x+_width-20, _y+5, -10, 8, colors[0], colors[1], colors[2]);
    gout << Line(_x+_width-20, _y+5, 10, 8, colors[0], colors[1], colors[2]);
    gout << Box(_x+_width-(40-BOX_BORDER), _y+_height/2, (40-BOX_BORDER*2), _height/2-BOX_BORDER, bgColorsBottom[0], bgColorsBottom[1], bgColorsBottom[2]);
    gout << Line(_x+_width-20, _y+_height-5, -10, -8, colors[0], colors[1], colors[2]);
    gout << Line(_x+_width-20, _y+_height-5, 10, -8, colors[0], colors[1], colors[2]);
    gout << Text(_x+_width-40-10-gout.twidth(to_string(_currentNumber)), _y+_height-_height/3, to_string(_currentNumber), colors[0], colors[1], colors[2]);
}

void NumberWidget::handleWidgetEvent(event event) {
    if(event.type == ev_mouse && event.button == btn_left) {
        Mouse mouse(event.pos_x, event.pos_y);
        handleWidgetButtonClick(event.button, mouse);
    }
    if(event.type == ev_key) {
        handleWidgetKeyPress(event.keycode);
    }
    if(_currentNumber < _lowerBound) {
        _currentNumber = _lowerBound;
    } else if(_currentNumber > _upperBound) {
        _currentNumber = _upperBound;
    }
}

void NumberWidget::handleWidgetButtonClick(int button, Mouse &mouse) {
    if(isMouseInsideChanger(mouse, 0)) {
        handleNumberChange();
    } else if(isMouseInsideChanger(mouse, 1)) {
        handleNumberChange(false);
    }
}

void NumberWidget::handleWidgetKeyPress(int keycode) {
    if(isMouseInside(_mouse)) {
        if(keycode == KEYCODE_UP || keycode == key_up) {
            handleNumberChange();
        } else if(keycode == KEYCODE_DOWN || keycode == key_down) {
            handleNumberChange(false);
        } else if(keycode == KEYCODE_PGUP || keycode == key_pgup) {
            handleNumberChange(true, 10);
        } else if(keycode == KEYCODE_PGDN || keycode == key_pgdn) {
            handleNumberChange(false, 10);
        }
    }
}

void NumberWidget::handleNumberChange(bool isGrowing, int number) {
    if(isGrowing) {
        if(_currentNumber+number <= _upperBound) {
            _currentNumber += number;
        } else if(_currentNumber > _upperBound) {
            _currentNumber = _upperBound;
        }
    } else {
        if(_currentNumber-number >= _lowerBound) {
            _currentNumber -= number;
        } else if(_currentNumber < _lowerBound) {
            _currentNumber = _lowerBound;
        }
    }
}
