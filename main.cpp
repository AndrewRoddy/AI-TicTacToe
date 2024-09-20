#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::vector;

void drawBoard();
void makeMove(char player);
void printCoords(int move);

vector <vector <char> > board = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int main() {
    char player; int move; bool running;
    player = 'X';
    running = true;
    while (running = true){
        drawBoard();
        makeMove(player);
        player = (player == 'X') ? 'O' : 'X'; // If X make O if O make X
    }
}

// Draws a TicTacToe board
void drawBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ' ' << board[i][j]; // Draws X or O or _
            if (j < 2) {cout << " |";} // Draws vertical lines
        }
        if (i < 2) { // Draws Horizontal lines
            cout << endl << "-- - - - --" << endl;
        }
    }
}

void makeMove(char player){
    while(true){
        int move;
        cout << endl << "Player " << player << " turn: ";
        cin >> move;
        int col = (int) ((move-1)/3);
        int row = (move-1) % 3;
        if (move >= 1 && move <= 9){
            if(board[col][row] == 'X' || board[col][row] == 'O'){
                drawBoard();
                cout << endl << "You can't move there!" << endl;
            } else {
                board[col][row] = player;
                return;
            }
        } else {
            drawBoard();
            cout << endl << "You can't move there!" << endl;
        }
    }
}

void printCoords(int move){
    cout << '(' << (int) ((move-1)/3); // X Coordinate
    cout << ',';
    cout << (move-1) % 3 << ')'; // Y Coordinate
}

// Personal Notes
/*
 - Make sure to include <vector> and std::vector or using std::vector.
 - 2D Vectors are generated using vector<vector<type>> var = {{},{},{}};
*/

