#include <iostream>
#include <vector>

using namespace std;

// Function to display the current game board
void displayBoard(vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "\n";
            if (i != 8) cout << "---|---|---\n";
        } else {
            cout << "|";
        }
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(vector<char>& board, char player) {
    // Check rows, columns, and diagonals
    return (board[0] == player && board[1] == player && board[2] == player) ||  // Row 1
           (board[3] == player && board[4] == player && board[5] == player) ||  // Row 2
           (board[6] == player && board[7] == player && board[8] == player) ||  // Row 3
           (board[0] == player && board[3] == player && board[6] == player) ||  // Column 1
           (board[1] == player && board[4] == player && board[7] == player) ||  // Column 2
           (board[2] == player && board[5] == player && board[8] == player) ||  // Column 3
           (board[0] == player && board[4] == player && board[8] == player) ||  // Diagonal 1
           (board[2] == player && board[4] == player && board[6] == player);    // Diagonal 2
}

// Function to check if the board is full (draw)
bool checkDraw(vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

// Main game function
void playGame() {
    vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';  // Player 1 starts as 'X'
    bool gameOver = false;

    while (!gameOver) {
        displayBoard(board);

        // Player's turn
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Validate input
        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Update the board
        board[move - 1] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } 
        // Check for a draw
        else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            gameOver = true;
        } 
        // Switch players
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    // Ask to play again
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        playGame();  // Restart the game
    } else {
        cout << "Thanks for playing!\n";
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    playGame();  // Start the game
    return 0;
}

