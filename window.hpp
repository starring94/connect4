#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <vector>
#include <string>

using namespace std;

class BasicWidget;

class window
{
protected:
    int m_windowSizeX;
    int m_windowSizeY;
    vector<BasicWidget*> m_widgets;
    int m_timerTickTime;
public:
    window(int x, int y, int tickTime = 40);
    void drawWidgets();
    void event_loop();
    virtual void other_event(std::string text);
    void addToWidgets(BasicWidget* widget);
    void addListToWidgets(vector<BasicWidget*> widgets);
    //void deleteWidget(BasicWidget* widget);
};

#endif // WINDOW_HPP_INCLUDED
