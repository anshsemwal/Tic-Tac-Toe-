#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

void displayBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

int main() {
    int move;
    char player = 'X';
    displayBoard();
    
    for (int i = 0; i < 9; i++) {
        cout << "Player " << player << ", enter your move: ";
        cin >> move;
        board[(move-1)/3][(move-1)%3] = player;
        displayBoard();
        if (checkWin()) {
            cout << "Player " << player << " wins!\n";
            return 0;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    cout << "It's a tie!\n";
    return 0;
}
