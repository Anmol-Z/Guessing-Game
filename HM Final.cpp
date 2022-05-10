// OOP TRY 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>

using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); // font size
void fontsize(int a, int b) {                 //font size
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

class Game
{
	string name; //for introduction of player
	char letter; //letter entry in guessing word
	string word; //orignal random word
	char level;
	string feedback;
public:
	int num_of_wrong_guesses = 0;
	const int MAX_TRIES = 5;
	Game()
	{
		name = "";
		letter = ' ';
		word = "";
		level = 0;
		feedback = "";
	}

	char check(char opt) //function to check the options if they are correct
	{
		if (opt == '1' || opt == '2' || opt == '3' || opt == '4' || opt == '5' || opt == '6')
			return opt;
		else
		{
			cout << "\nWrong Input! Re-enter your Choice :>  : ";
			cin >> opt;
			check(opt);
		}
	}

	int letterFill(char guess, string secretword, string& guessword) //function to fill in the unknown word 
	{
		int i;
		int matches = 0;
		int len = secretword.length();
		for (i = 0; i < len; i++)
		{
			// Did we already match this letter in a previous guess?
			if (guess == guessword[i]) //unknown
				return 0;
			// Is the guess in the secret word?
			if (guess == secretword[i]) //hyphen is removed by word 
			{
				guessword[i] = guess;
				matches++; //characters matched
			}
		}
		return matches;
	}
	void Details() { //to get the name of user
		cout << "\nWelcome to the Guessing Maze!! Please enter your Name to continue: ";
		getline(cin, name);
	}
	char Lev() {
		// Asking user for level to begin with
		int i = 1;
		cout << "\nHello " << name << ", \nPlease Select the level of difficulty: \nPress( E-Easy, A-Average, H-Hard ):" << endl;
		while (i == 1) {

			cin >> level;
			if (level == 'e' || level == 'E' || level == 'h' || level == 'H' || level == 'a' || level == 'A')
			{
				i = 2;
			}
			else
				cout << "WRONG INPUT! Enter Again\n";
		}
		return level;
	}
	string easy() {
		char opt;
		//easy strings stored inside an array
		cout << "Select from the category: \n (1) Country \n (2) Desi Food \n (3) Vehicle \n (4) Comic Character \n (5) Movie \n (6) Currency " << endl;
		cin >> opt;
		opt = check(opt); // to check 
		if (opt == '1')
		{
			string easy[] = { "india", "japan", "nepal", "china", "qatar" };
			int n = rand() % 5; //system ka function stores int number in it.
			word = easy[n];
			return word;
		}
		else if (opt == '2')
		{
			string easy[] = { "kheer","biryani", "daal", "qeema", "saag" };
			int n = rand() % 5;
			word = easy[n];
			return word;
		}
		else if (opt == '3')
		{
			string easy[] = { "mehran", "alto", "mira", "cultus", "fx" };
			int n = rand() % 5;
			word = easy[n];
			return word;
		}
		else if (opt == '4')
		{
			string easy[] = { "vision", "falcon", "aquaman", "ironman", "antman" };
			int n = rand() % 5;
			word = easy[n];
			return word;
		}
		else if (opt == '5')
		{
			string easy[] = { "fargo", "madman", "maniac", "slash", "scream" };
			int n = rand() % 5;
			word = easy[n];
			return word;
		}
		else if (opt == '6')
		{
			string easy[] = { "dinar", "dollar", "pound", "rupee", "colon" };
			int n = rand() % 5;
			word = easy[n];
			return word;
		}
	}
	string average() {
		char opt;
		//easy strings stored inside an array
		cout << "Select from the category: \n (1) Country \n (2) Desi Food \n (3) Vehicle \n (4)a Comic Character \n (5) Movie \n (6) Currency " << endl;
		cin >> opt;
		opt = check(opt);
		if (opt == '1')
		{
			string average[] = { "madagascar", "azerbaijan", "kyrgyzstan" };
			int n = rand() % 3; //system ka function stores int number in it.
			word = average[n];
			return word;
		}
		else if (opt == '2')
		{
			string average[] = { "nihari", "karahi", "panipuri", "chargha", "paye" };
			int n = rand() % 5; //system ka function stores int number in it.
			word = average[n];
			return word;
		}
		else if (opt == '3')
		{
			string average[] = { "parado", "yaris", "santro", "cherade", "hiroof" };
			int n = rand() % 5; //system ka function stores int number in it.
			word = average[n];
			return word;
		}
		else if (opt == '4')
		{
			string average[] = { "hawkeye", "shangchi", "catwoman", "spiderman", "superman" };
			int n = rand() % 5;
			word = average[n];
			return word;
		}
		else if (opt == '5')
		{
			string average[] = { "hideaway", "twitches", "wishcraft", "jumanji", "skyfall" };
			int n = rand() % 5;
			word = average[n];
			return word;
		}
		else if (opt == '6')
		{
			string average[] = { "shilling", "sterling", "somoni", "bolivar", "manat" };
			int n = rand() % 5;
			word = average[n];
			return word;
		}
	}
	string hard() {
		char opt;
		//to see what category does the user want
		cout << "Select from the category: \n (1) Country \n (2) Desi Food \n (3) Vehicle \n (4) Comic Character \n (5) Movie \n (6) Currency " << endl;
		cin >> opt;
		opt = check(opt); // check recieved opt which it would check if matches the provided options.
		int i = 1;
		if (opt == '1')
		{
			string hard[] = { "turkmenistan", "frenchguiana", "newcaledonia" };
			int n = rand() % 3; //system ka function stores int number in it.
			word = hard[n];
			return word;
		}
		else if (opt == '2')
		{
			string hard[] = { "khichri", "murghcholay", "bihariboti", "panjeeri", "mutanjanpulao" };
			int n = rand() % 5;
			word = hard[n];
			return word;
		}
		else if (opt == '3')
		{
			string hard[] = { "protonsaga", "alsvin", "lancer", "tundra", "miata" };
			int n = rand() % 5;
			word = hard[n];
			return word;
		}
		else if (opt == '4')
		{
			string hard[] = { "captainmarvel", "doctorstrange", "blackpanther", "daredevil", "scarletwitch" };
			int n = rand() % 5;
			word = hard[n];
			return word;
		}
		else if (opt == '5')
		{
			string hard[] = { "divergent", "maleficent", "dreamchild", "amusement", "deliverance" };
			int n = rand() % 5;
			word = hard[n];
			return word;
		}
		else if (opt == '6')
		{
			string hard[] = { "kwacha", "hryvnia", "paanga", "zloty", "guarani" };
			int n = rand() % 5;
			word = hard[n];
			return word;
		}

	}
	string unk() {
		//call the function here for guessing game
		// Initialize the secret word with the - character.

		string unknown(word.length(), '-');
		return unknown;
	}

	char Call(string unknown) {
		cout << "\n\nEach letter is represented by a hyphen.";
		cout << "\n\nYou have to type only one letter in one try.";
		cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
		cout << "\n________________";
		// Loop until the guesses are used up
		num_of_wrong_guesses = 0;
		while (num_of_wrong_guesses < MAX_TRIES)
		{
			cout << "\n\n" << unknown;
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct,
				// otherwise increment the number of wrong guesses.
			system("cls");
			if (letterFill(letter, word, unknown) == 0)
			{
				num_of_wrong_guesses++;
				if ((MAX_TRIES - num_of_wrong_guesses) > 1) {
					cout << endl << "Uh oh!! You missed a chance." << endl;
					cout << "You have " << MAX_TRIES - num_of_wrong_guesses << " guesses left" << endl;
				}
				else if ((MAX_TRIES - num_of_wrong_guesses) == 1) {
					cout << endl << "Uh oh!! You missed a chance." << endl;
					cout << "This is going to be your last chance!!" << endl;
				}
				else {
					system("COLOR 40");
					Draw(5);
					cout << "\nYOU WASTED YOUR TRIES! SAD :(" << endl;
					cout << "\nYOU LOSE." << endl;
					cout << "THE WORD WAS: " << word << endl;
					bool play = PlaySound(TEXT("Anmol.wav"), NULL, SND_SYNC); //disappointed sound effect for fun

				}
			}
			else
			{
				if (word == unknown) // Check if user guessed the word.
				{

					cout << "\n" << word << "\n\nYOU WON!" << endl;
					bool play = PlaySound(TEXT("Maani.wav"), NULL, SND_SYNC); //cheered sound for fun
					num_of_wrong_guesses = MAX_TRIES;
				}
				else {
					cout << endl << "LETTER FOUND!\n" << endl;
					cout << "You have " << MAX_TRIES - num_of_wrong_guesses << " guesses left" << endl;

				}
			}
			if (num_of_wrong_guesses != MAX_TRIES)
				Draw(num_of_wrong_guesses); //hangs a man 

		}
		return 'E';
	}
	void Draw(int tries)
	{
		if (tries == 0)
		{
			cout << " ______" << endl;
			cout << " |         " << endl;
			cout << " |         " << endl;
			cout << " |         " << endl;
			cout << " |         " << endl;
			cout << " |_" << endl;
		}
		if (tries == 1)
		{
			cout << " ______" << endl;
			cout << " |        |" << endl;
			cout << " |         " << endl;
			cout << " |         " << endl;
			cout << " |         " << endl;
			cout << " |_" << endl;
		}
		else if (tries == 2)
		{
			cout << " ______" << endl;
			cout << " |        |" << endl;
			cout << " |        O " << endl;
			cout << " |         " << endl;
			cout << " |         " << endl;
			cout << " |_" << endl;
		}

		else if (tries == 3)
		{
			cout << " ______" << endl;
			cout << " |         |" << endl;
			cout << " |       \\ O /" << endl;
			cout << " |         " << endl;
			cout << " |         " << endl;
			cout << " |_" << endl;
		}
		else if (tries == 4)
		{
			cout << " ______" << endl;
			cout << " |         |" << endl;
			cout << " |       \\ O /" << endl;
			cout << " |         |" << endl;
			cout << " |         " << endl;
			cout << " |_" << endl;
		}

		else if (tries == 5)
		{
			cout << " ______" << endl;
			cout << " |         |" << endl;
			cout << " |       \\ O /" << endl;
			cout << " |         |" << endl;
			cout << " |        / \\ " << endl;
			cout << " |_" << endl;
		}

	}
	void Feedback()
	{
		cout << "Dear " << name << ", \nPlease give us your valued feedback regarding this game: ";
		cin.ignore();
		getline(cin, feedback);
		ofstream FeedbackFile("E:\\feedback.txt");
		FeedbackFile << "Player's Name: " << name << endl;
		FeedbackFile << "Player's Feedback: " << feedback;
		FeedbackFile.close();
	}

	//cin.get();

};

int main() {
	system("COLOR 06");
	fontsize(30, 30);
	Game player1;
	char play = 'Y';
	srand(time(0));   //for playing with comps internal watch
	player1.Details();
	while (play == 'Y' || play == 'y')
	{
		char l = player1.Lev();
		if (l == 'E' || l == 'e') {
			string y = player1.easy();
			string word = player1.unk();
			char x = player1.Call(word);
		}
		else if (l == 'A' || l == 'a') {
			string y = player1.average();
			string word = player1.unk();
			char x = player1.Call(word);
		}
		else if (l == 'H' || l == 'h') {
			string y = player1.hard();
			string word = player1.unk();
			char x = player1.Call(word);

		}
		system("pause");
		system("COLOR 06");
		system("cls");
		cout << "Do you want to Play again?(y/n) " << endl;
		cin >> play;
		if (play == 'y' || play == 'Y')
			system("cls");
	}
	system("COLOR 70");
	system("cls");
	player1.Feedback();


}