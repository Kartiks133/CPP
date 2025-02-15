#include <iostream>
using namespace std;

#define N 8


bool safe(int row, int col, int board[N][N]) {
    // same column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

\
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << "- ";
        }
        cout << endl;
    }
}

int main() {
    int board[N][N] = {0}; 
    int colPositions[N];

    cout << "Enter the column position (0-7) for each row:" << endl;

    for (int i = 0; i < N; i++) {
        int col;
        bool valid = false;

        
        while (!valid) {
            cout << "Enter the column position for row " << i + 1 << ": ";
            cin >> col;

            if (col < 0 || col >= N) {
                cout << "Invalid position! Column should be between 0 and 7. Try again." << endl;
            } 
            else if (safe(i, col, board)) {
                board[i][col] = 1;
                colPositions[i] = col;
                valid = true;
            } 
            else {
                cout << "Invalid placement! Queen at row " << i + 1 << " is attacking another queen. Try again." << endl;
            }
        }
    }

    cout << "\nBravo! you didn't let the queens kill each other \n";
    printBoard(board);

    return 0;
}
