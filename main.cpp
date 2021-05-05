#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "graphics.hpp"
#include "window.hpp"
#include "GlobalSettings.hpp"
#include "BasicWidget.hpp"
#include "SelectWidget.hpp"
#include "NumberWidget.hpp"
#include "CheckboxWidget.hpp"
#include "RadioWidget.hpp"
#include "StaticTextWidget.hpp"
#include "DynamicTextWidget.hpp"
#include "BaseButtonWidget.hpp"
#include "FunctorButtonWidget.hpp"
#include "C4PieceWidget.hpp"
#include "C4BoardPartWidget.hpp"
#include "C4BoardRowWidget.hpp"
#include "C4BoardWidget.hpp"

const int X = 800;
const int Y = 800;

using namespace std;
using namespace genv;

class MainWindow : public window {
protected:
    SelectWidget* s1;
    SelectWidget* s2;
    SelectWidget* s3;
    SelectWidget* s4;
    SelectWidget* s5;
    NumberWidget* n1;
    NumberWidget* n2;
    CheckboxWidget* c1;
    RadioWidget* r1;
    DynamicTextWidget* d1;
    FunctorButtonWidget* b1;
    FunctorButtonWidget* b2;
    FunctorButtonWidget* b3;
    FunctorButtonWidget* b4;
    FunctorButtonWidget* b5;
    C4PieceWidget* c4_1;
    C4BoardPartWidget* c4bp_1;
    C4BoardRowWidget* c4br_1;
    C4BoardWidget* c4b_1;
    StaticTextWidget* st1;
public:
    MainWindow(): window(X, Y, 40) {
        srand(time(NULL));
        //b3 = new FunctorButtonWidget(this, 375, 500, 35, 35, "->", false, false, [&]() {
        //    removeElements(s4->getElements(), s4, s5);
        //});
        //b4 = new FunctorButtonWidget(this, 425, 500, 35, 35, "<-", false, false, [&]() {
        //    removeElements(s5->getElements(), s5, s4);
        //});
        //s1 = new SelectWidget(this, 10, 10, 200, { "teszt1", "teszt2", "teszt3", "tessssssssssssssssssszt" }, 0, 10);
        //s2 = new SelectWidget(this, 220, 10, 150, { "teszt1", "teszt2", "teszt3", "teszt4", "teszt5", "teszt6", "teszt7", "teszt8", "teszt9", "teszt10", "teszt11" }, 1, 5);
        //s3 = new SelectWidget(this, 390, 10, 130, { "tessssssssssszt", "teszt1", "teszt2", "teszt3", "teszt4" }, 4, 2);
        //s4 = new SelectWidget(this, 200, 500, 150, { "a", "b", "c", "d", "e", "p" }, 0, 5);
        //s5 = new SelectWidget(this, 500, 500, 150, { "f", "g", "h", "i", "j" }, 0, 5);
        //n1 = new NumberWidget(this, 10, 400, 150, -5000, 5000, -2147483646);
        //n2 = new NumberWidget(this, 170, 400, 150, -32767, 32768, 15);
        //c1 = new CheckboxWidget(this, 400, 400, 25, "Teszt", true);
        //r1 = new RadioWidget(this, 400, 650, 25, "Test", false);
        //d1 = new DynamicTextWidget(this, 100, 90, 200, 30, "Teszt");
        //b1 = new FunctorButtonWidget(this, 200, 200, 240, 50, "Dinamikus szöveg frissítése", false, false, [&]() { d1->setText("Megváltozott szöveg"); });
        //b2 = new FunctorButtonWidget(this, 200, 300, 240, 50, "Kiemelés be-ki kapcsolása", false, false, [&]() { GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS = !GlobalSettings::HIGHLIGHT_SELECTED_WIDGETS; });
        b5 = new FunctorButtonWidget(this, 200, 400, 240, 50, "Cikk mozgatása", false, false, [&] {
            //c4br_1->addNewPiece();
        });
        //c4_1 = new C4PieceWidget(this, 500, 100-5, 255, 0, 0);
        //c4bp_1 = new C4BoardPartWidget(this, 400, 100, 15);
        //c4br_1 = new C4BoardRowWidget(this, 500, 100, 6, 15);
        st1 = new StaticTextWidget(this, 20, 20, X-20, Y-20, "text");
        c4b_1 = new C4BoardWidget(this, 200, 100, 7, 6, 30);
    }

    void removeElements(vector<string> ele, SelectWidget*& thisOne, SelectWidget*& otherOne) {
        if(thisOne->getElements().size() > 0) {
            string ori_value = thisOne->getElements()[thisOne->getSelected()];
            thisOne->removeElementFromList(thisOne->getSelected());
            thisOne->setSelectedValue((thisOne->getElements().size() > 0) ? thisOne->getElements().size()-1 : 0);
            otherOne->addToElements(ori_value);
        }
    }
};

int main()
{
    MainWindow* main = new MainWindow;
    main->drawWidgets();
    main->event_loop();
    return 0;
}
