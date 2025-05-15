#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 4;
vector<int> board(N, -1);

bool is_safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool place_queens(int row) {
    if (row == N) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (board[r] == c) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (is_safe(row, col)) {
            board[row] = col;
            res = place_queens(row + 1) || res;
            board[row] = -1; // Backtrack
        }
    }
    return res;
}

void solve_four_queens() {
    if (!place_queens(0)) {
        cout << "Solution does not exist." << endl;
    }
}

int main() {
    solve_four_queens();
    return 0;
}
