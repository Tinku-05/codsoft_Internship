#include <iostream>
#include <cstdlib>
using namespace std;

class TicTacToe {
public:
    TicTacToe();
    void playGame();

private:
    char Game_Board[3][3];
    char currentPlayer;

    // Function declarations
    void drawBoard();
    void makeMove(int move);
    void switchPlayer();
    bool winChecker();
    bool gameOver();
    void validateInput(int &move);
};

// Constructor
TicTacToe::TicTacToe() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Game_Board[i][j] = '1' + (i * 3 + j);
        }
    }
    currentPlayer = 'X';
}

// Function to play the game
void TicTacToe::playGame() {
    char winner;
    int move;

    drawBoard();
    while (!winChecker()) {
        cout << "Enter a number from 1 to 9, " << currentPlayer << ", it's your turn: ";
        cin >> move;
        validateInput(move);
        makeMove(move);
        system("cls");
        drawBoard();
        if (gameOver()) {
            cout << "This game is a tie.\n";
            exit(0);
        }
    }

    winner = (currentPlayer == 'X') ? 'O' : 'X';
    cout << "Congratulations, " << winner << "! You have won the game.\n";
}

// Function to draw the board
void TicTacToe::drawBoard() {
    cout << "   |   |   " << endl;
    cout << " " << Game_Board[0][0] << " | " << Game_Board[0][1] << " | " << Game_Board[0][2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << Game_Board[1][0] << " | " << Game_Board[1][1] << " | " << Game_Board[1][2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << Game_Board[2][0] << " | " << Game_Board[2][1] << " | " << Game_Board[2][2] << " " << endl;
    cout << "   |   |   " << endl;
}

// Function to make a move
void TicTacToe::makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (Game_Board[row][col] == 'X' || Game_Board[row][col] == 'O') {
        cout << "Invalid Move!!! This place is already taken." << endl;
    }
    else {
        Game_Board[row][col] = currentPlayer;
        switchPlayer();
    }
}

// Function to switch players
void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check if there is a winner
bool TicTacToe::winChecker() {
    for (int i = 0; i < 3; i++) {
        if (Game_Board[i][0] == Game_Board[i][1] && Game_Board[i][1] == Game_Board[i][2]) {
            return true;
        }
        if (Game_Board[0][i] == Game_Board[1][i] && Game_Board[1][i] == Game_Board[2][i]) {
            return true;
        }
    }

    if (Game_Board[0][0] == Game_Board[1][1] && Game_Board[1][1] == Game_Board[2][2]) {
        return true;
    }
    if (Game_Board[0][2] == Game_Board[1][1] && Game_Board[1][1] == Game_Board[2][0]) {
        return true;
    }

    return false;
}

// Function to check if the game is over
bool TicTacToe::gameOver() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Game_Board[i][j] != 'X' && Game_Board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to validate input
void TicTacToe::validateInput(int &move) {
    while (move < 1 || move > 9) {
        cout << "Invalid input! Enter a number from 1 to 9: ";
        cin >> move;
    }
}

// Main function
int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}