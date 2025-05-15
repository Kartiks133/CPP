#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


double predict(int x) {
    return abs(50 - x);
}

void playGame() {
    cout << "Welcome to the AI-Powered Guess the Number Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << endl;

    srand(static_cast<unsigned>(time(0)));
    int target = rand() % 100 + 1;
    int attempts = 0;

    while (true) {
        int guess;
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail() || guess < 1 || guess > 100) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 100." << endl;
            continue;
        }

        attempts++;
        double prediction = predict(guess);
        int closeness = abs(target - guess);

        if (guess == target) {
            cout << "Congratulations! You guessed it in " << attempts << " attempts." << endl;
            break;
        } else if (closeness <= 5) {
            cout << "Very Close! Keep trying." << endl;
        } else if (guess < target) {
            cout << "Too Low!" << endl;
        } else {
            cout << "Too High!" << endl;
        }
    }
}

int main() {
    playGame();
    return 0;
}
