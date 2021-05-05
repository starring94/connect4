#include "C4BoardWidget.hpp"
#include "C4BoardRowWidget.hpp"
#include "GraphicsAdditions.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

C4BoardWidget::C4BoardWidget(window* parent, int x, int y, int numberOfRows, int numberOfColumns, int partSize): BasicWidget(parent, x, y, partSize*2*numberOfRows, numberOfColumns*partSize*2), m_numberOfRows(numberOfRows), m_numberOfColumns(numberOfColumns), m_partSize(partSize)
{
    for(int i = 0; i < numberOfRows; i++) {
        m_boardRows.push_back(new C4BoardRowWidget(parent, x+i*partSize*2, y, numberOfColumns, partSize, i));
    }
}

void C4BoardWidget::handleWidgetEvent(event event){}
bool C4BoardWidget::isMouseInside(Mouse &mouse) { return false; }
void C4BoardWidget::drawWidget(){}
string C4BoardWidget::getValues() { return ""; }
