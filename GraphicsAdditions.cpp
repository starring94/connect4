#include "GraphicsAdditions.hpp"

using namespace genv;

GAElement::GAElement(int r, int g, int b) : _r(r), _g(g), _b(b)
{
}

void GAElement::operator () (canvas& out) {
    out.set_color(_r, _g, _b);
}

Box::Box(int x, int y, int width, int height, int r, int g, int b) : GAElement(r, g, b), _x(x), _y(y), _w(width), _h(height)
{
}

void Box::operator () (canvas& out) {
    GAElement::operator()(out);
    out.move_point(_x-out.x(), _y-out.y());
    out.call_with_rel(&canvas::draw_box, _w, _h);
}

Text::Text(int x, int y, const std::string& text, int r, int g, int b) : GAElement(r, g, b), _x(x), _y(y), _text(text)
{
}

Text::Text(int x, int y, char c, int r, int g, int b) : GAElement(r, g, b), _x(x), _y(y), _text(1, c)
{
}

void Text::operator () (canvas& out) {
    GAElement::operator()(out);
    out.move_point(_x-out.x(), _y-out.y());
    out.draw_text(_text);
}

Line::Line(int x, int y, int line_x, int line_y, int r, int g, int b) : GAElement(r, g, b), _x(x), _y(y), _lx(line_x), _ly(line_y)
{
}

void Line::operator () (canvas& out) {
    GAElement::operator()(out);
    out.move_point(_x-out.x(), _y-out.y());
    out.call_with_rel(&canvas::draw_line, _lx, _ly);
}

LineFromTo::LineFromTo(int fx, int fy, int tx, int ty, int r, int g, int b) : GAElement(r, g, b), _fx(fx), _fy(fy), _tx(tx), _ty(ty)
{
}

void LineFromTo::operator () (canvas& out) {
    GAElement::operator()(out);
    out.move_point(_fx-out.x(), _fy-out.y());
    out.draw_line(_tx-out.x(), _ty-out.y());
}

Dot::Dot(int x, int y, int r, int g, int b) : GAElement(r, g, b), _x(x), _y(y)
{
}

void Dot::operator () (canvas& out) {
    GAElement::operator()(out);
    out.move_point(_x-out.x(), _y-out.y());
    out.draw_dot();
}
