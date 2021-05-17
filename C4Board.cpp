#include "C4Board.hpp"
#include "C4BoardWidget.hpp"
#include <string>

using namespace std;
using namespace genv;

C4Board::C4Board(window* parent, int x, int y, int numberOfRows, int numberOfColumns, int partSize): m_board(Matrix(numberOfRows, numberOfColumns)), m_xPosition(x), m_yPosition(y), m_numberOfRows(numberOfRows), m_numberOfColumns(numberOfColumns), m_partSize(partSize), m_currentPlayer(0), m_numberOfMoves(0), m_playerOneWins(0), m_playerTwoWins(0), m_playerTies(0), m_isWin(false)
{
    m_widget = new C4BoardWidget(parent, x, y, numberOfRows, numberOfColumns, partSize, this);
    m_resetButton = new FunctorButtonWidget(parent, 10, 10, 100, 50, "Új játék", false, false, [&](){ resetGame(); });
    m_winText = new StaticTextWidget(parent, 120, 40, 200, 50, "");
    m_winList = new StaticTextWidget(parent, 10, 80, 200, 100, "1. játékos: 0\n2. játékos: 0\nDöntetlen: 0");
    for(int i = 0; i < m_numberOfRows; i++) {
        for(int j = 0; j < m_numberOfColumns; j++) {
            m_board.set(i, j, 9);
        }
    }
}

void C4Board::resetGame() {
    m_widget = new C4BoardWidget(m_widget->getParent(), m_xPosition, m_yPosition, m_numberOfRows, m_numberOfColumns, m_partSize, this);
    m_winText->setText("");
    m_currentPlayer = 0;
    m_isWin = false;
    for(int i = 0; i < m_numberOfRows; i++) {
        for(int j = 0; j < m_numberOfColumns; j++) {
            m_board.set(i, j, 9);
        }
    }
}

void C4Board::handleButtonClick(int row, int column) {
    if(!m_isWin) {
        m_board.set(row, column, m_currentPlayer);
        m_currentPlayer = (m_currentPlayer == 0) ? 1 : 0;
        int winnerID = handleWinCondition();
        if(winnerID == 0) {
            m_isWin = true;
            m_playerOneWins++;
            m_winText->setText("Elsõ játékos nyert!");
            m_winList->setText(("1. játékos: " + to_string(m_playerOneWins) + "\n2. játékos: " + to_string(m_playerTwoWins) + "\nDöntetlen: " + to_string(m_playerTies)));
        }
        if(winnerID == 1) {
            m_isWin = true;
            m_playerTwoWins++;
            m_winText->setText("Második játékos nyert!");
            m_winList->setText(("1. játékos: " + to_string(m_playerOneWins) + "\n2. játékos: " + to_string(m_playerTwoWins) + "\nDöntetlen: " + to_string(m_playerTies)));
        }
        if(winnerID == -1 && checkTieCondition()) {
            m_isWin = true;
            m_playerTies++;
            m_winText->setText("Ez a játék döntetlen lett!");
            m_winList->setText(("1. játékos: " + to_string(m_playerOneWins) + "\n2. játékos: " + to_string(m_playerTwoWins) + "\nDöntetlen: " + to_string(m_playerTies)));
        }
    }
}

int C4Board::handleWinCondition() {
    for(int j = 0; j < m_numberOfColumns; j++) {
        for(int i = 0; i < m_numberOfRows; i++) {
            if(checkHorizontalWinCondition(0, i, j) || checkVerticalWinCondition(0, i, j) || checkDiagonalWinCondition(0, i, j)) {
                return 0;
            }
            if(checkHorizontalWinCondition(1, i, j) || checkVerticalWinCondition(1, i, j) || checkDiagonalWinCondition(1, i, j)) {
                return 1;
            }
        }
    }
    return -1;
}

bool C4Board::checkTieCondition() {
    int filledPositions = 0;
    for(int j = 0; j < m_numberOfColumns; j++) {
        for(int i = 0; i < m_numberOfRows; i++) {
            if(checkPosition(0, i, j) || checkPosition(1, i, j)) {
                filledPositions++;
            }
        }
    }
    return filledPositions == m_numberOfColumns*m_numberOfRows;
}

bool C4Board::checkPosition(int playerid, int row, int column) {
    if(row < 0 || row >= m_numberOfRows) return false;
    if(column < 0 || column >= m_numberOfColumns) return false;
    return m_board.at(row, column) == playerid;
}

bool C4Board::checkHorizontalWinCondition(int playerid, int row, int column) {
    return (checkPosition(playerid, row,   column) &&
            checkPosition(playerid, row, column+1) &&
            checkPosition(playerid, row, column+2) &&
            checkPosition(playerid, row, column+3));
}

bool C4Board::checkVerticalWinCondition(int playerid, int row, int column) {
    return (checkPosition(playerid, row,   column) &&
            checkPosition(playerid, row+1, column) &&
            checkPosition(playerid, row+2, column) &&
            checkPosition(playerid, row+3, column));
}

bool C4Board::checkDiagonalWinCondition(int playerid, int row, int column) {
    return (checkPosition(playerid, row,     column) &&
            checkPosition(playerid, row+1, column+1) &&
            checkPosition(playerid, row+2, column+2) &&
            checkPosition(playerid, row+3, column+3)) ||
           (checkPosition(playerid, row,     column) &&
            checkPosition(playerid, row-1, column+1) &&
            checkPosition(playerid, row-2, column+2) &&
            checkPosition(playerid, row-3, column+3));
}

int C4Board::getCurrentPlayer() {
    return m_currentPlayer;
}

void C4Board::setCurrentPlayer(int playerid) {
    m_currentPlayer = playerid;
}

bool C4Board::getWinCondition() {
    return m_isWin;
}
