//	uppercase, and whether it is a vowel

#include <iostream>
//this line includes a part of the standard C++ library, allowing you
//	to output data to the screen and input it through the keyboard

using namespace std;

int main()
{
	char UsrInput;
	cout << "Please enter an ASCII character: ";//part of iostream
	cin >> UsrInput;//another part of iostream
	cout << endl;

	if ((UsrInput >= 'A' && UsrInput <= 'Z') ||
			(UsrInput >= 'a' && UsrInput <= 'z'))//this line continues the
		//if statement
	{
		cout << "The character you entered is a letter." << endl;
		if (UsrInput >= 'A' && UsrInput <= 'Z')
			cout << "The letter you entered is a UPPERCASE." << endl;
		else cout << "The letter you entered is lowercase." << endl;
		switch (UsrInput)
		{//a switch is easier to type and less cluttered here because you only have to name the variable once
			//if you were working with multiple variables, you would need a switch
			case 'A':
			case 'a':
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'O':
			case 'o':
			case 'U':
			case 'u':
				cout << "The letter you entered is a vowel." << endl;
				break;
			default:
				cout << "The letter you entered is NOT a vowel." << endl;
				break;
		}
	}
	else cout << "The character you entered is NOT a letter.";
	//C++ ignores most whitespace, so it is completely valid to
	//	put code on the same line as an else or if statement.
}
