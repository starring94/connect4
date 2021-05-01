#ifndef MOUSE_HPP_INCLUDED
#define MOUSE_HPP_INCLUDED

class Mouse {
protected:
    int _x, _y;
public:
    Mouse();
    Mouse(int x, int y);

    int getX();
    int getY();
    void setX(int value);
    void setY(int value);
    void setValue(int x, int y);
};

#endif // MOUSE_HPP_INCLUDED
