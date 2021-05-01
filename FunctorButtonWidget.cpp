#include "FunctorButtonWidget.hpp"
#include <functional>

using namespace std;

FunctorButtonWidget::FunctorButtonWidget(window* parent, int x, int y, int width, int height, string text, bool p_isStorable, bool p_isPressedDown, function<void()> functor): BaseButtonWidget(parent, x, y, width, height, text, p_isStorable, p_isPressedDown), m_functor(functor)
{
}

void FunctorButtonWidget::handleWidgetAction() {
    m_functor();
}

function<void()> FunctorButtonWidget::getFunctor() {
    return m_functor;
}

void FunctorButtonWidget::setFunctor(function<void()> funct) {
    m_functor = funct;
}
