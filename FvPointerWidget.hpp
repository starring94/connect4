#ifndef FVPOINTERWIDGET_HPP_INCLUDED
#define FVPOINTERWIDGET_HPP_INCLUDED

#include "BaseButtonWidget.hpp"

typedef void(*FVPointer)(window*);

class FvPointerWidget: public BaseButtonWidget {
protected:
    FVPointer m_pointer;
public:
    FvPointerWidget(window* parent, int x, int y, int width, int height, std::string text, bool p_isStorable, bool p_isPressedDown, FVPointer pointer);
    virtual void handleWidgetAction();
    FVPointer getPointer();
    void setPointer(FVPointer pointer);
};

#endif // FVPOINTERWIDGET_HPP_INCLUDED
