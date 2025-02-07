#include <iostream>
#include <limits>  // For numeric_limits
using namespace std;

bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

void displayBoard(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << " " << board[row][col];
            if (col < 2) {
                cout << " |";
            }
        }
        cout << endl;
        
        if (row < 2) {
            cout << "---+---+---" << endl;
        }
    }
}

bool isBoardFull(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, 
                       {' ', ' ', ' '}, 
                       {' ', ' ', ' '}};
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        displayBoard(board);
        cout << "Player " << currentPlayer << " enter row and column (0-2): ";
        
        int row, col;
        if (!(cin >> row >> col)) {
            cout << "Invalid input. Please enter numbers only." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            bool hasWon = checkWin(board, currentPlayer);
            bool isFull = isBoardFull(board);

            if (hasWon) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (isFull) {
                displayBoard(board);
                cout << "Game ended in a draw!" << endl;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again!" << endl;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}