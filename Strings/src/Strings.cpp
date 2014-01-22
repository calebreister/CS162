#include "Strings.h"

int main()
{
	cout << "STRING MODE" << endl;
	stringDemo();
	cout << "CSTRING MODE" << endl;
	cstringDemo();
	return 0;
}

void stringDemo()
{
	string MyName = "Caleb Reister";
	string UserGuess;
	string UserGuessBarb; //barb short for barbarian

	//prompt for user to guess name of author
	cout << "Guess what my name is: ";
	getline(cin, UserGuess);

	//tell the user if their guess was correct
	cout << "You chose: ";
	if ( UserGuess == MyName )
		cout << "wisely";
	else
		cout << "poorly";

	//remove vowels from the user's guess
	cout << endl << "You entered: " << UserGuess << endl;
	cout << "Without vowels, that is: " << RmVowels(UserGuess) << endl;

	//append "the Barbarian"
	UserGuessBarb = UserGuess + " the Barbarian";
	cout << "In less civilized times (such as the times CS162 class has "
	     "recreated very accurately), you might be known as: "
	     << UserGuessBarb;
	//not meant as an insult, intended for personal comic relief
	cout << endl << endl;
}

void cstringDemo()
{
	//declare c-strings
	char MyName[] = "Caleb Reister";
	const int UserGuessSize = 100;
	char UserGuess[UserGuessSize];
	char UserGuessRmV[UserGuessSize]; //removed vowel version
	char UserGuessBarb[UserGuessSize + strlen(" the Barbarian")];

	//Prompt user to guess name
	cout << "Guess what my name is: ";
	cin.get(UserGuess, UserGuessSize - 1);

	//check if user was right
	cout << "You chose: ";
	if ( strcmp(UserGuess, MyName) == false )
		cout << "wisely";
	else
		cout << "poorly";
	cout << endl;

	//remove vowels from the guess
	cout << "You entered: " << UserGuess << endl;
	RmVowels(UserGuess, UserGuessRmV, UserGuessSize);
	cout << "Without vowels, that would be: " << UserGuessRmV << endl;

	//append " the Barbarian"
	strcpy(UserGuessBarb, UserGuess);
	strcat(UserGuessBarb, " the Barbarian");
	cout << "In less civilized times (such as the times CS162 class has "
	     "recreated very accurately), you might be known as: "
	     << UserGuessBarb;
	//not meant as an insult, intended for personal comic relief
	cout << endl << endl;
}

string RmVowels(string input)
{
	string output = "";
	for ( unsigned int index = 0; index < input.size(); index++ )
	{
		switch (input[index])
		{
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'u':
				break;
			default:
				output += input[index];
				break;
		}
	}
	return output;
}

void RmVowels(const char input[], char output[], int size)
{
	int OutIndex = 0;
	for ( int index = 0; index < size; index++ )
	{
		switch (input[index])
		{
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'u':
				break;
			default:
				output[OutIndex] = input[index];
				OutIndex++;
				break;
		}
	}
}
