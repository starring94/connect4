#ifndef C4BOARD_HPP_INCLUDED
#define C4BOARD_HPP_INCLUDED

#include "Matrix.hpp"
#include "C4BoardWidget.hpp"
#include "FunctorButtonWidget.hpp"
#include "StaticTextWidget.hpp"

class C4BoardWidget;

class C4Board {
protected:
    Matrix m_board;
    C4BoardWidget* m_widget;
    FunctorButtonWidget* m_resetButton;
    StaticTextWidget* m_winText;
    StaticTextWidget* m_winList;
    int m_xPosition;
    int m_yPosition;
    int m_numberOfRows;
    int m_numberOfColumns;
    int m_partSize;
    int m_currentPlayer;
    int m_numberOfMoves;
    int m_playerOneWins;
    int m_playerTwoWins;
    int m_playerTies;
    bool m_isWin;
public:
    C4Board(window* parent, int x, int y, int numberOfRows, int numberOfColumns, int partSize);
    void resetGame();
    void handleButtonClick(int row, int column);
    int handleWinCondition();
    bool checkTieCondition();
    bool checkPosition(int playerid, int row, int column);
    bool checkHorizontalWinCondition(int playerid, int row, int column);
    bool checkVerticalWinCondition(int playerid, int row, int column);
    bool checkDiagonalWinCondition(int playerid, int row, int column);
    int getCurrentPlayer();
    void setCurrentPlayer(int playerid);
    bool getWinCondition();
};

#endif // C4BOARD_HPP_INCLUDED
