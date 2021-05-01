#include "MessageButtonWidget.hpp"

using namespace std;

MessageButtonWidget::MessageButtonWidget(window* parent, int x, int y, int width, int height, string text, bool p_isStorable, bool p_isPressedDown, string message): BaseButtonWidget(parent, x, y, width, height, text, p_isStorable, p_isPressedDown), m_id(message)
{
}

void MessageButtonWidget::handleWidgetAction() {
    _parent->other_event(m_id);
}

string MessageButtonWidget::getId() {
    return m_id;
}

void MessageButtonWidget::setId(string val) {
    m_id = val;
}
