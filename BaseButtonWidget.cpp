#include "BaseButtonWidget.hpp"
#include "Constants.hpp"
#include "GlobalSettings.hpp"
#include "GraphicsAdditions.hpp"
#include <string>

using namespace std;
using namespace genv;
using namespace Constants;

BaseButtonWidget::BaseButtonWidget() : BasicWidget(), m_isStorable(false), m_isPressedDown(false), m_text("Base Button")
{
}

BaseButtonWidget::BaseButtonWidget(window* parent, int x, int y, int width, int height, string text, bool p_isStorable, bool p_isPressedDown): BasicWidget(parent, x, y, width, height), m_isStorable(p_isStorable), m_isPressedDown(p_isPressedDown), m_text(text)
{
}

string BaseButtonWidget::getValues() {
    return BasicWidget::getValues() + ";isStorable=" + to_string(m_isStorable) + ";isPressedDown=" + to_string(m_isPressedDown) + ";text=" + m_text;
}

void BaseButtonWidget::drawWidget() {
    int colors[3] = { 255, 255, 255 };
    int btncolors[3] = { 120, 120, 120 };
    if(GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS && isSelected) {
        colors[1] = 0;
        colors[2] = 0;
    } else {
        colors[1] = 255;
        colors[2] = 255;
    }
    if(m_isPressedDown) {
        btncolors[0] = 250;
        btncolors[1] = 180;
        btncolors[2] = 180;
    } else {
        btncolors[0] = 120;
        btncolors[1] = 120;
        btncolors[2] = 120;
    }
    gout << Box(_x, _y, _width, _height, colors[0], colors[1], colors[2]);
    gout << Box(_x+BOX_BORDER, _y+BOX_BORDER, _width-BOX_BORDER*2, _height-BOX_BORDER*2, btncolors[0], btncolors[1], btncolors[2]);
    gout << Text(_x+BOX_BORDER+(_width/2-gout.twidth(m_text)/2-2), _y+_height/1.75+2, m_text, colors[0], colors[1], colors[2]);
}

void BaseButtonWidget::handleWidgetEvent(event event){
    if(event.type == ev_mouse) {
        Mouse mouse(event.pos_x, event.pos_y);
        handleWidgetButtonClick(event.button, mouse);
    }
}

void BaseButtonWidget::handleWidgetButtonClick(int button, Mouse &mouse) {
    if(m_isStorable) {
        if(button == btn_left && isSelected) {
            m_isPressedDown = !m_isPressedDown;
        }
        if(button == -btn_left && m_isPressedDown && isSelected) {
            handleWidgetAction();
        }
    } else {
        if(button == btn_left && isSelected) {
            m_isPressedDown = true;
        }
        if(button == -btn_left && m_isPressedDown && isSelected) {
            handleWidgetAction();
        }
        if(button == -btn_left || !isSelected) {
            m_isPressedDown = false;
        }
    }
}

bool BaseButtonWidget::isStorable() {
    return m_isStorable;
}

bool BaseButtonWidget::isPressedDown() {
    return m_isPressedDown;
}

string BaseButtonWidget::getText() {
    return m_text;
}

void BaseButtonWidget::setStorable(bool value) {
    m_isStorable = value;
}

void BaseButtonWidget::toggledPressedDown() {
    m_isPressedDown = !m_isPressedDown;
}

void BaseButtonWidget::setText(string text) {
    m_text = text;
}
