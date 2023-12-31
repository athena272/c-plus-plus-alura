#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Global variables
string secret_word;         // The secret word to be guessed
map<char, bool> guessed;    // A map to track guessed letters
vector<char> wrong_guesses; // A vector to store incorrect guesses

// Function to check if a guessed letter exists in the secret word
bool letter_exists(char guess)
{
    for (char letter : secret_word)
    {
        if (guess == letter)
        {
            return true;
        }
    }
    return false;
}

// Function to check if there are letters in the secret word that haven't been guessed
bool not_guessed()
{
    for (char letter : secret_word)
    {
        if (!guessed[letter])
        {
            return true;
        }
    }
    return false;
}

// Function to check if the maximum number of incorrect guesses has been reached
bool not_hanged()
{
    return wrong_guesses.size() < 5;
}

// Function to print the game header
void print_header()
{
    cout << "*********************" << endl;
    cout << "*** Hangman Game ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

// Function to print the incorrect guesses
void print_errors()
{
    cout << "Wrong guesses: ";
    for (char letter : wrong_guesses)
    {
        cout << letter << " ";
    }
    cout << endl;
}

// Function to print the current state of the word with guessed letters
void print_word()
{
    for (char letter : secret_word)
    {
        if (guessed[letter])
        {
            cout << letter << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to process a user's guess
void guess()
{
    cout << "Your guess: ";
    char user_guess;
    cin >> user_guess;

    guessed[user_guess] = true;

    if (letter_exists(user_guess))
    {
        cout << "You got it! Your guess is in the word." << endl;
    }
    else
    {
        cout << "You missed! Your guess is not in the word." << endl;
        wrong_guesses.push_back(user_guess);
    }
    cout << endl;
}

// Function to read words from a file
vector<string> read_file()
{
    ifstream file;
    file.open("words.txt");

    if (file.is_open())
    {
        int number_of_words;
        file >> number_of_words;

        vector<string> words_from_file;

        for (int i = 0; i < number_of_words; i++)
        {
            string word_read;
            file >> word_read;
            words_from_file.push_back(word_read);
        }

        file.close();
        return words_from_file;
    }
    else
    {
        cout << "Could not access the word bank." << endl;
        exit(0);
    }
}

// Function to randomly choose a word from the file
void draw_word()
{
    vector<string> words = read_file();

    srand(time(NULL));
    int randomly_chosen_index = rand() % words.size();

    secret_word = words[randomly_chosen_index];
}

// Function to save a new list of words to the file
void save_file(vector<string> new_list)
{
    ofstream file;
    file.open("words.txt");
    if (file.is_open())
    {
        file << new_list.size() << endl;

        for (string word : new_list)
        {
            file << word << endl;
        }
        file.close();
    }
    else
    {
        cout << "Could not access the word bank." << endl;
        exit(0);
    }
}

// Function to add a new word to the file
void add_word()
{
    cout << "Enter the new word, using uppercase letters." << endl;
    string new_word;
    cin >> new_word;

    vector<string> word_list = read_file();
    word_list.push_back(new_word);

    save_file(word_list);
}

// Main function
int main()
{
    print_header();

    read_file();
    draw_word();

    // Game loop
    while (not_guessed() && not_hanged())
    {
        print_errors();
        print_word();
        guess();
    }

    // Game over
    cout << "Game over!" << endl;
    cout << "The secret word was: " << secret_word << endl;
    if (not_guessed())
    {
        cout << "You lost! Try again!" << endl;
    }
    else
    {
        cout << "Congratulations! You guessed the secret word!" << endl;

        cout << "Do you want to add a new word to the bank? (Y/N) ";
        char response;
        cin >> response;
        if (response == 'Y')
        {
            add_word();
        }
    }

    return 0;
}
