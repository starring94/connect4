#ifndef FUNCTORBUTTONWIDGET_HPP_INCLUDED
#define FUNCTORBUTTONWIDGET_HPP_INCLUDED

#include "BaseButtonWidget.hpp"
#include <functional>

class FunctorButtonWidget: public BaseButtonWidget {
protected:
    std::function<void()> m_functor;
public:
    FunctorButtonWidget(window* parent, int x, int y, int width, int height, std::string text, bool p_isStorable, bool p_isPressedDown, std::function<void()> functor);
    virtual void handleWidgetAction();
    std::function<void()> getFunctor();
    void setFunctor(std::function<void()> funct);
};

#endif // FUNCTORBUTTONWIDGET_HPP_INCLUDED
