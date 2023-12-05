#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Display a welcome message to the game
    cout << "**************************************" << endl;
    cout << "* Welcome to the Guessing Game!       *" << endl;
    cout << "**************************************" << endl;

    // Ask the player to choose the difficulty level
    cout << "Choose your difficulty level:" << endl;
    cout << "Easy (E), Medium (M), or Hard (H)" << endl;

    // Store the difficulty level chosen by the player
    char difficulty;
    cin >> difficulty;
    cout << "The chosen difficulty is: " << difficulty << endl;

    // Determine the maximum number of attempts based on the difficulty level
    int number_of_attempts;
    if (difficulty == 'E')
    {
        number_of_attempts = 15;
    }
    else if (difficulty == 'M')
    {
        number_of_attempts = 10;
    }
    else
    {
        number_of_attempts = 5;
    }

    // Generate a random number between 0 and 99 to be the secret number
    srand(time(NULL));
    const int SECRET_NUMBER = rand() % 100;

    // Initialize variables for game control
    bool not_guessed = true;
    int attempts = 0;
    double points = 1000.0;

    // Start a loop representing the player's attempts
    for (attempts = 1; attempts <= number_of_attempts; attempts++)
    {
        // Ask the player to make a guess
        int guess;
        cout << "Attempt " << attempts << endl;
        cout << "What's your guess? ";
        cin >> guess;

        // Calculate points lost based on the difference between the guess and the secret number
        double points_lost = abs(guess - SECRET_NUMBER) / 2.0;
        points -= points_lost;

        // Display the value of the player's guess
        cout << "Your guess is: " << guess << endl;

        // Check if the guess is equal, greater, or less than the secret number
        bool correct = guess == SECRET_NUMBER;
        bool greater = guess > SECRET_NUMBER;

        // Display feedback messages to the player
        if (correct)
        {
            cout << "Congratulations! You guessed the secret number!" << endl;
            not_guessed = false;
            break;
        }
        else if (greater)
        {
            cout << "Your guess was greater than the secret number!" << endl;
        }
        else
        {
            cout << "Your guess was less than the secret number!" << endl;
        }
    }

    // Display end-of-game message and result
    cout << "Game over!" << endl;
    if (not_guessed)
    {
        cout << "You lost! Try again!" << endl;
    }
    else
    {
        cout << "You guessed the secret number in " << attempts << " attempts" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Your score was " << points << " points." << endl;
    }
}
