#include "SelectWidget.hpp"
#include "GraphicsAdditions.hpp"
#include "GlobalSettings.hpp"
#include "Constants.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace genv;
using namespace std;
using namespace Constants;

SelectWidget::SelectWidget() : BasicWidget(), _elements(vector<string>()), _selected(0), _scrollTop(0), _isOpened(false), _maxNumberOfParts(5)
{
}

SelectWidget::SelectWidget(window* parent, int x, int y, int width) : BasicWidget(parent, x, y, width, 30), _elements(vector<string>()), _selected(0), _scrollTop(0), _isOpened(false), _maxNumberOfParts(5)
{
}

SelectWidget::SelectWidget(window* parent, int x, int y, int width, vector<string> elements, int selected, int maxNumberOfParts) : BasicWidget(parent, x, y, width, 30), _elements(elements), _selected(selected), _scrollTop(0), _isOpened(false), _maxNumberOfParts(maxNumberOfParts)
{
}

bool SelectWidget::isMouseInside(Mouse &mouse) {
    if(_isOpened) {
        return (mouse.getX() > _x && mouse.getY() > _y && (mouse.getX() < _x+_width || mouse.getX() < _x+_width-40) && (mouse.getY() < _y+_height || _x+_height+_maxNumberOfParts*_height));
    } else return mouse.getX() > _x && mouse.getY() > _y && mouse.getX() < _x+_width && mouse.getY() < _y+_height;
}

int SelectWidget::isMouseInsidePart(Mouse &mouse, int partId) {
    if(!_isOpened) return -1;
    return mouse.getX() > _x && mouse.getX() < _x+_width-40 && mouse.getY() > _y+_height+partId*_height && mouse.getY() < _y+_height+(partId+1)*_height;
}

int SelectWidget::getPartIdWithMouseInside(Mouse &mouse) {
    if(!_isOpened) return -1;
    if(_scrollTop > (int)_elements.size()) _scrollTop = 0;
    for(int i = _scrollTop; i < (int)_elements.size(); i++) {
        if(mouse.getX() > _x && mouse.getX() < _x+_width-40 && mouse.getY() > _y+_height+(i-_scrollTop)*_height && mouse.getY() < _y+_height+(i-_scrollTop+1)*_height) {
            return i;
        }
    }
    return -1;
}

void SelectWidget::drawWidget() {
    int numOfParts = (_maxNumberOfParts >= (int)_elements.size()) ? (int)_elements.size() : _maxNumberOfParts;
    int height = numOfParts*_height;
    int colors[3] = { 255, 255, 255 };
    if(GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS && isSelected) {
        colors[1] = 0;
        colors[2] = 0;
    } else {
        colors[1] = 255;
        colors[2] = 255;
    }
    gout << Box(_x, _y, _width, _height, colors[0], colors[1], colors[2]);
    gout << Box(_x+2, _y+2, _width-4, _height-4, 0, 0, 0);
    gout << Line(_x+_width-10, _y+10, -10, 10, colors[0], colors[1], colors[2]);
    gout << Line(_x+_width-20, _y+20, -10, -10, colors[0], colors[1], colors[2]);
    gout << Box(_x+_width-40, _y, 2, _height, colors[0], colors[1], colors[2]);
    if(_elements.size() > 0) {
        gout << Text(_x+10, _y+_height-_height/3, fitTextInBox(_elements[_selected]), colors[0], colors[1], colors[2]);
        if(_isOpened) {
            gout << Box(_x, _y+_height, _width, height, colors[0], colors[1], colors[2]);
            gout << Box(_x+2, _y+_height+2, _width-4, height-4, 0, 0, 0);
            gout << Box(_x+_width-40, _y+_height, 2, height, colors[0], colors[1], colors[2]);
            for(int i = 0; i < numOfParts; i++) {
                int hEx = (i+1)*_height;
                int colors2[3] = {255, 255, 255};
                if(GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS && isSelected) {
                    colors2[0] = 255;
                    colors2[1] = 0;
                    colors2[2] = 0;
                } else {
                    colors2[0] = 255;
                    colors2[1] = 255;
                    colors2[2] = 255;
                }
                int bgColors[3] = {0, 0, 0};
                if(isMouseInsidePart(_mouse, i)) {
                    if(GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS && isSelected) {
                        colors2[0] = 255;
                        colors2[1] = 0;
                        colors2[2] = 0;
                    } else {
                        colors2[0] = 120;
                        colors2[1] = 120;
                        colors2[2] = 120;
                    }
                    bgColors[0] = 30;
                    bgColors[1] = 30;
                    bgColors[2] = 30;
                }
                gout << Box(_x+2, _y+hEx+2, _width-44, _height-4, bgColors[0], bgColors[1], bgColors[2]);
                gout << Text(_x+10, _y+_height+hEx-_height/3, fitTextInBox(_elements[i+_scrollTop]), colors2[0], colors2[1], colors2[2]);
                if(i < numOfParts-1) {
                    gout << Box(_x, _y+_height+hEx, _width-40, 2, colors[0], colors[1], colors[2]);
                }
            }
            if(numOfParts+_scrollTop <= (int)_elements.size()) {
                if(_scrollTop > 0) {
                    gout << Line(_x+_width-10, _y+_height*2-10, -10, -10, colors[0], colors[1], colors[2]);
                    gout << Line(_x+_width-20, _y+_height*2-20, -10, 10, colors[0], colors[1], colors[2]);
                }
                if(numOfParts+_scrollTop < (int)_elements.size()) {
                    gout << Line(_x+_width-10, _y+height+10, -10, 10, colors[0], colors[1], colors[2]);
                    gout << Line(_x+_width-20, _y+height+20, -10, -10, colors[0], colors[1], colors[2]);
                }
            }
        }
    }
}

void SelectWidget::handleWidgetEvent(event event) {
    if(event.type == ev_mouse) {
        handleWidgetButtonClick(event.button, _mouse);
    }
}

void SelectWidget::handleWidgetButtonClick(int button, Mouse &mouse) {
    if(isMouseInside(mouse)) {
        if(button == btn_left) {
            if(getPartIdWithMouseInside(mouse) != -1) {
                _selected = getPartIdWithMouseInside(mouse);
            }
            toggleOpen();
        }
        if(button == BUTTON_WHEELDOWN) {
            _scrollTop = (_scrollTop+_maxNumberOfParts == (int)_elements.size()) ? _scrollTop: (_scrollTop+_maxNumberOfParts > (int)_elements.size()) ? _scrollTop : _scrollTop+1;
        }
        if(button == BUTTON_WHEELUP) {
            _scrollTop = (_scrollTop == 0) ? _scrollTop: _scrollTop-1;
        }
    }
}

string SelectWidget::getValues() {
    return BasicWidget::getValues() +
            "\nelements_len=INT("  + to_string((int)_elements.size()) +
            ")\nselectedNumber=INT(" + to_string(_selected) +
            ")\nscrollTop=INT(" + to_string(_scrollTop) +
            ")\nisOpened=BOOLEAN(" + ((_isOpened) ? "TRUE" : "FALSE") +
            ")\nmaxNumberOfParts=INT(" + to_string(_maxNumberOfParts) +
            ")\n";
}

int SelectWidget::getSelected() {
    return _selected;
}

vector<string> SelectWidget::getElements()
{
    return _elements;
}

void SelectWidget::addToElements(string element) {
    _elements.push_back(element);
}

void SelectWidget::addListToElements(vector<string> ele) {
    for(size_t i = 0; i < ele.size(); i++) {
        _elements.push_back(ele[i]);
    }
}

void SelectWidget::removeElementFromList(int position) {
    _elements.erase(_elements.begin()+position);
}

void SelectWidget::toggleOpen() {
    _isOpened = !_isOpened;
}

void SelectWidget::setSelectedValue(int val) {
    _selected = val;
}

string SelectWidget::fitTextInBox(string text, int num) {
    string outText = text;
    if(10+gout.twidth(text)+gout.twidth("...") > _width-44) {
        outText = fitTextInBox(outText.substr(0, outText.size()-1), num+1);
    }
    return (num == 0 && 10+gout.twidth(text)+gout.twidth("...") > _width-44) ? outText.append("...") : outText;
}
