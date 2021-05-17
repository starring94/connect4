#include "window.hpp"
#include "C4Board.hpp"

const int X = 800;
const int Y = 800;

using namespace std;

class MainWindow : public window {
protected:
    C4Board* board;
public:
    MainWindow(): window(X, Y, 40) {
        board = new C4Board(this, 190, 200, 7, 6, 30);
    }
};

int main()
{
    MainWindow* main = new MainWindow;
    main->drawWidgets();
    main->event_loop();
    return 0;
}
