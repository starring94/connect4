#ifndef GRAPHICSADDITIONS_HPP_INCLUDED
#define GRAPHICSADDITIONS_HPP_INCLUDED

#include "graphics.hpp"

using namespace genv;

class GAElement {
    int _r;
    int _g;
    int _b;
public:
    GAElement(int r, int g, int b);

    virtual void operator () (canvas& out);
};

class Box : public GAElement {
protected:
    int _x;
    int _y;
    int _w;
    int _h;
public:
    Box(int x, int y, int width, int height, int r, int g, int b);

    void operator () (canvas& out);
};

class Text : public GAElement {
protected:
    int _x;
    int _y;
    std::string _text;
public:
    Text(int x, int y, const std::string& text, int r, int g, int b);
    Text(int x, int y, char c, int r, int g, int b);

    void operator () (canvas& out);
};

class Line : public GAElement {
protected:
    int _x;
    int _y;
    int _lx;
    int _ly;
public:
    Line(int x, int y, int line_x, int line_y, int r, int g, int b);

    void operator () (canvas& out);
};

class LineFromTo : public GAElement {
protected:
    int _fx;
    int _fy;
    int _tx;
    int _ty;
public:
    LineFromTo(int fx, int fy, int tx, int ty, int r, int g, int b);

    void operator () (canvas& out);
};

class Dot: public GAElement {
protected:
    int _x;
    int _y;
public:
    Dot(int x, int y, int r, int g, int b);

    void operator () (canvas& out);
};

#endif // GRAPHICSADDITIONS_HPP_INCLUDED
