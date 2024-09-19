#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::vector;

vector <vector <char> > board = {{'_','_','_'},{'_','_','_'},{'_','_','_'}};

void drawBoard();

int main() {
    drawBoard();
}

void drawBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ' ' << board[i][j]; // Draws X or O or _
            if (j < 2) { // Checks to draw line between icons and not after
                cout << " |";
            }
        }
        cout << endl;
    }
}

// Personal Notes
/*
 - Make sure to include <vector> and std::vector or using std::vector.
 - 2D Vectors are generated using vector<vector<type>> var = {{},{},{}};
*/

