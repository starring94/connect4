#include "window.hpp"
#include "BasicWidget.hpp"
#include "graphics.hpp"
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;
using namespace genv;

window::window(int x, int y, int tickTime) : m_windowSizeX(x), m_windowSizeY(y), m_timerTickTime(tickTime)
{
    gout.open(x, y);
    gin.timer(tickTime);
}

void window::drawWidgets() {
    for(BasicWidget* wg : m_widgets) {
        wg->drawWidget();
    }
    gout << refresh;
}

void window::event_loop() {
    event ev;
    int focus = -1;
    int selected = -1;
    while(gin >> ev && ev.keycode != key_escape ) {
        Mouse mouse(ev.pos_x, ev.pos_y);
        gout << move_to(0, 0) << color(0, 0, 0) << box(m_windowSizeX, m_windowSizeY);
        if (ev.type == ev_mouse) {
            auto t = time(nullptr);
            auto tm = *localtime(&t);

            ostringstream oss;
            oss << "info_" << std::put_time(&tm, "%Y-%m-%d %H-%M-%S") << ".txt";
            auto str = oss.str();
            ofstream outFile;
            if(ev.button == btn_right) {
                outFile.open(str);
            }
            for (size_t i=0;i<m_widgets.size();i++) {
                if(ev.pos_x != 0 && ev.pos_y != 0) {
                    m_widgets[i]->setMouseValue(ev.pos_x, ev.pos_y);
                }
                if (m_widgets[i]->isMouseInside(mouse)) {
                    focus = i;
                    if(selected != -1) {
                        m_widgets[selected]->setSelected(false);
                    }
                    selected = i;
                    m_widgets[selected]->setSelected(true);
                }
                if(ev.button == btn_right) {
                    outFile << m_widgets[i]->getValues() << endl;
                }
            }
            if(ev.button == btn_right) {
                outFile.close();
            }
        }
        if(ev.type == ev_key) {
            if(ev.keycode == key_tab) {
                if(selected == -1) {
                    selected = 0;
                    m_widgets[selected]->setSelected(true);
                } else if(selected >= 0 && selected < (int)m_widgets.size()-1) {
                    m_widgets[selected]->setSelected(false);
                    selected++;
                    m_widgets[selected]->setSelected(true);
                } else if(selected == (int)m_widgets.size()-1) {
                    m_widgets[selected]->setSelected(false);
                    selected = 0;
                    m_widgets[selected]->setSelected(true);
                }

            }
        }
        if (focus!=-1) {
            m_widgets[focus]->handleWidgetEvent(ev);
        }
        if(selected != -1) {
            m_widgets[selected]->drawWidget();
        }
        if(focus != -1) {
            m_widgets[focus]->drawWidget();
        }
        drawWidgets();
        //string asd = "" + to_string((ev.pos_x != 0) ? ev.pos_x : 0) + ";" + to_string((ev.pos_y) ? ev.pos_y : 0);
        //gout << move_to(50, 50) << color(255, 255, 255) << text(asd);
    }
}

void window::other_event(string text) {}

void window::addToWidgets(BasicWidget* widget) {
    m_widgets.push_back(widget);
}

void window::addListToWidgets(vector<BasicWidget*> widgets) {
    for(size_t i = 0; i < widgets.size(); i++) {
        m_widgets.push_back(widgets[i]);
    }
}

/*void window::deleteWidget(BasicWidget* widget) {
    for(size_t i = 0; i < m_widgets.size(); i++) {
        if(m_widgets[i] == widget) {
            BasicWidget* temp = m_widgets[i];
            m_widgets.erase(m_widgets.begin()+i);
        }
    }
}*/
