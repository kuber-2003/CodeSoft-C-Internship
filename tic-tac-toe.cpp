#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check for a win
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Horizontal win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Vertical win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Function to check for a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // The game is not a draw if there are empty cells
            }
        }
    }
    return true; // All cells are filled, it's a draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    cout << "Tic-Tac-Toe Game" << endl;

    while (true) {
        cout << "Current Board:" << endl;
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        } else if (checkDraw(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
    }

    cout << "Game Over." << endl;

    return 0;
}
