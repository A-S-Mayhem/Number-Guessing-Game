// Programmer: Avery Mahan
// Title: Guess The Number

//****************************************************
// Description: Program is a number gussing game for *
// values between 1 and 100. User enters an integer  *
// and depending on if the guess was lower or higher *
// than a randomly generated value, the program      *
// display a message stating guess was less than or  *
// greater than. Program functions user various do   *
// do while loops and if statments to check input.   *              
//****************************************************


// Header files for i/o obejects, psueudo random number gen, as well as several time functions
#include <iostream>
#include <cstdlib>          
#include <ctime> 

// cin/cout abbreviation as well as end line object
using namespace std;

int main()
{
    // Variable declaration for generated and and guessed integer
    int randomNum;
    int guessNum;

    // Variable declaration for counter to track number of guesses
    int counter = 10;

    // Variable declaration for string of text for varying text outputs
    string mockOutput1 = "Nice try! But, no.";
    string mockOutput2 = "Are you even trying to guess?";
    string mockOutput3 = "Maybe in a million years... guess again?";
    string mockOutput4 = "Woah there fella! Last chance, better make it count...";
    string outOfRangeOutput = "C'mon now, enter a number less than the limit";

    // Variable declaration for choice character for replayability
    char choice;

    // Display discription to user
    cout << "WELCOME TO..." << endl;
    cout << "GUESS THE NUMBER!" << endl<<endl;
    cout << "continue to description"<<endl;

    // Wait for user input and clear screen
    system("pause");
    system("CLS");

    // Console screen description
    cout << "In this game, a random number between 1 and 100" << endl
        << "will be generated and you will have to guess it." << endl
        << "After entering an integer value, you will be " << endl
        << "promted on whether or not your value was greater " << endl
        << "than or less than the generated value" << endl << endl
        << "continue to game" << endl;

    // Wait for user input and clear screen
    system("pause");
    system("CLS");

    // Open main "Replay game" loop
    do
    {

        
        // Initialize counter variable to track number of user entries
        counter = 10;

        // Generate random number between 0 and 100
        srand(time(0));
        randomNum = rand() % 100;
        
        
       
        // Opening prompt
        cout << "Guess a number between 1 and 100" << endl;

        // Open loop for when entered value does not match generated value
        do 
        {
            // Open loop to validate user input is within range
            do{ 
            
                do 
                {
                    // Prompt user to enter guess
                    cout << "Guess: ";
                    cin >> guessNum;

                    // Validate user input 
                    if (!cin)
                    {
                        // If validation failes prompt user re-entrry
                        cout << "Enter an integer and nothing else, mmkay?" << endl
                            << "Here's an example: Guess: 7" << endl;

                        // Toss Previous cin
                        cin.clear();
                        cin.ignore(1, '\n');
                        cout << "Guess: ";
                        cin >> guessNum;
                    }
                } while (!cin);
                
                // If range validation fails prompt user re-entry
                if (guessNum > 100)
                {
                    cout << outOfRangeOutput << endl;
                }

            } while (guessNum > 100);

            // Decrement the counter to track number on turns left
            counter--;

            // As long as user has at least one guess remaining...
            if (counter >= 1)
            {
                
                // Display "mocking" outputs for user encouragement
                // Special outputs for when the counter reaches certain
                // values to simulate real world speech 
                if (counter == 7)
                {
                    // Additional ifs to check if user was correct or not
                    if (guessNum != randomNum)
                    {
                        cout << mockOutput1 << endl;
                    }
                }
                else if (counter == 5)
                {
                    if (guessNum != randomNum)
                    {
                        cout << mockOutput2 << endl;
                    }
                }
                else if (counter == 3)
                {
                    if (guessNum != randomNum)
                    {
                        cout << mockOutput3 << endl;
                    }
                }
                else if (counter == 1)
                {
                    if (guessNum != randomNum)
                    {
                        cout << mockOutput4 << endl;
                    }
                }
                
                // State entered value was greater than desired value
                if (guessNum > randomNum)
                {
                    cout << "You guessed too high!" << endl;
                    cout << "Tries left: " << counter << endl;
                }

                // State entered value was less than desired value
                else if (guessNum < randomNum)
                {
                    cout << "You guessed too low!" << endl;
                    cout << "Tries left: " << counter << endl;
                }

            }

            // If user has used all allowed attempts:
            if (counter == 0)
            {
                // Check to see if user guessed correctly on last try
                if (guessNum != randomNum)
                {
                    
                   
                   cout << "  _____ _____ _____ _____    _____ _____ _____  _____ " << endl
                        << " |  __ |  _  |     |   __|  |     |  |  |   __ |  __ |" << endl
                        << " |     |     | | | |   __|  |  |  |  |  |   __ |    -|" << endl
                        << " |_____|__|__|_|_|_|_____|  |_____|\___/ |_____ |__|__|" << endl;
                }
                
                break;
            }

            // Stay in loop until guessed value matches generated value or until game over and break
        } while (guessNum != randomNum);


        // If user guessed the correct value display winning message
        if (guessNum == randomNum)
        {
          cout << endl << endl;
          cout <<" ___ ___ _______ _______      ________ _______ _______ __ " << endl;
          cout <<"|   |   |       |   |   |    |  |  |  |_     _|    |  |  |" << endl;
          cout <<"  \     /|   -   |   |   |    |  |  |  |_|   |_|       |__|" << endl;
          cout <<"  |___| |_______|_______|    |________|_______|__|____|__|" << endl;

            
            
        }

        // Display generated value at the end of each round 
        cout << "The number was: " << randomNum;
        cout << endl << endl << endl;

        // Ask user if they would like to start a new iteration
        cout << "Would you like to play again?" << endl;
        cout << "Enter Y or N: ";
        cin >> choice;
        system("CLS");

        // Loop until input is anything that isn't 'Y' or 'y'
    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for playing!" << endl;
    // End program
    return 0;
}


