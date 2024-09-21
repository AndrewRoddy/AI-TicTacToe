#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::vector;

void drawBoard();
void makeMove(char player);
void printCoords(int move);
char winCheck();
bool playAgain();
void reset(char& player, char &winner);

vector <vector <char> > board = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int main() {
    int move;
    bool running = true;
    char player = 'X';
    char winner = '-';
    while (running == true){
        drawBoard();
        makeMove(player);
        winner = winCheck();
        player = (player == 'X') ? 'O' : 'X'; // If X make O if O make X
        if (winner != '-'){
            drawBoard();
            cout << winner << " Wins!!";
            reset(player, winner);
            running = playAgain();
        }
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
    cout << endl << endl;
}

void makeMove(char player){
    int move, col, row;
    while(true){
        cout << "Player " << player << " turn: ";
        cin >> move;
        col = (int) ((move-1)/3);
        row = (move-1) % 3;
        if (move < 1 || move > 9){continue;} // If move not within limit, try again
        if(board[col][row] == 'X' || board[col][row] == 'O'){continue;} // If square taken, try again
        board[col][row] = player; // Make the move
        break;
    }
}

char winCheck(){
    char players[2] = {'X', 'O'};
    for(int q = 0; q < 2; q++){
        for(int i = 0; i < 3; i++){
            if( // Checks for Across and Down
                (board[0][i] == players[q] && board[1][i] == players[q] && board[2][i] == players[q]) ||
                (board[i][0] == players[q] && board[i][1] == players[q] && board[i][2] == players[q])   
            ){return players[q];}
        }
        if( // Checks for Diagnols
            (board[0][0] == players[q] && board[1][1] == players[q] && board[2][2] == players[q]) ||
            (board[0][2] == players[q] && board[1][1] == players[q] && board[2][0] == players[q])
        ){return players[q];}
    }
    
    return '-';
}

bool playAgain(){
    char again;
    while(true){
        cout << "Would you like to play again?\nY: Yes\nN: No\n";
        cin >> again;
        switch (again){
            case 'Y':
            case 'y':
                return true;
            case 'N':
            case 'n':
                return false;
            default:
                cout << "Not a valud response, Try again";
        }
    }
}

void reset(char& player, char &winner){
    board = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    player = 'X';
    winner = '-';
}


void printCoords(int move){
    cout << '(' << (int) ((move-1)/3); // X Coordinate
    cout << ',';
    cout << (move-1) % 3 << ')'; // Y Coordinate
}

