#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    bool running = true;
    srand((unsigned)time(NULL));

    int random = 1 + (rand() % 100);
    int guess;

    while (running)
    {
        cout << "Guess a number between 1 and 100." << endl;
        cin >> guess;
        if (guess == random) {
            running = false;
            cout << "Well done, you found the number! It was: " << guess << endl;
        } else if (guess > random) {
            cout << "You're guess was too high" << endl;
        } else {
            cout << "You're guess was too low" << endl;
        }
    }

    return 1;
}