#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main ()
{
    srand(time(0));   // Generating random numbers

    int random = rand() % 100;   
    bool check = false;
    int guess = 0;

    // Loop will run until user guesses the correct number
    while(guess != random) {
        cout << "Enter number between 0-100:";
        cin >> guess;

        if (guess == random) {
            check = true;
        }
        else if(guess > random) {
            cout << "Guess is too high. Try again!"<<endl;
        }
        else {
            cout << "Guess is too low. Try again!"<<endl;
        }
    }

    if (check == true) {
        cout << "Congratulations!"<<endl;
    }

    return 0;

}