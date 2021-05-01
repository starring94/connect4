#include "FvPointerWidget.hpp"

using namespace std;

FvPointerWidget::FvPointerWidget(window* parent, int x, int y, int width, int height, string text, bool p_isStorable, bool p_isPressedDown, FVPointer pointer): BaseButtonWidget(parent, x, y, width, height, text, p_isStorable, p_isPressedDown), m_pointer(pointer)
{
}

void FvPointerWidget::handleWidgetAction() {
    m_pointer(_parent);
}

FVPointer FvPointerWidget::getPointer() {
    return m_pointer;
}

void FvPointerWidget::setPointer(FVPointer pointer) {
    m_pointer = pointer;
}
