// triplex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
using namespace std;

void PrintInstruction(long long Difficulty)
{
    //the intro message
    cout << "U r a secret agent trying to break into a level " << Difficulty << " " << "highly protected facility...\n" << endl;
    cout << "U must enter the right codes to enter or the alarm will alert everyone\n" << endl;
}

bool PlayGame(long long Difficulty)
{
    PrintInstruction(Difficulty);
    //The Real numbers
    long long CodeA = rand() % Difficulty + Difficulty; 
    long long CodeB = rand() % Difficulty + Difficulty;
    long long CodeC = rand() % Difficulty + Difficulty;
    long long Sum = CodeA + CodeB + CodeC;
    long long Product = CodeA * CodeB * CodeC;
    
    cout << "there are 3 numbers in the code\n";
    cout << "sum" << " " << Sum << endl << "product" << " " << Product;

    //Your Guess
    long long PlayerGuess1, Playerguess2, Playerguess3;
    cin >> PlayerGuess1 >> Playerguess2 >> Playerguess3;
    cout << "You Entered" << " " << PlayerGuess1 << " " << Playerguess2 << "  " << Playerguess3;
    long long GuessSum = PlayerGuess1 + Playerguess2 + Playerguess3;
    long long GuessProduct = PlayerGuess1 * Playerguess2 * Playerguess3;
    cout << "Your Sum" << " " << GuessSum << " " << "Your Product" << " " << GuessProduct << endl;

    //Check
    if (Sum == GuessSum && Product == GuessProduct) {
        cout << "You Win\n";
        return true;
    }
    else {
        cout << "You Lose\n " << "Retry Again";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    long long LevelDifficulty = 1;
    const long long MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //loop until game ends
    {
        bool LevelComplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();

        if (LevelComplete) 
        {
            LevelDifficulty++;
        }
        
    }
    cout << "Congrats On Finishing The Game U R Awesome . Now Get The F Outta Here";
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
