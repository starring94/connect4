#include "mouse.hpp"

Mouse::Mouse() : _x(0), _y(0) {}

Mouse::Mouse(int x, int y) : _x(x), _y(y) {}

int Mouse::getX() {
    return _x;
}

int Mouse::getY() {
    return _y;
}

void Mouse::setX(int value) {
    _x = value;
}

void Mouse::setY(int value) {
    _y = value;
}

void Mouse::setValue(int x, int y) {
    _x = x;
    _y = y;
}
