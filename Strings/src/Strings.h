/*
PROGRAM: Strings
AUTHOR: Caleb Reister
DATE: 2014-01-11
DEV ENV: Eclipse CDT Linux AMD64
DESCRIPTION: A program for experimenting with the string and cstring datatypes
	● Part 1 has you do some activities using c-strings (null terminated array of chars)
	● Part 2 has you redo those activities using the C++ string datatype in place of the Cstring
	(char array) (Part 2 is easier, you might want to do it first)
 */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*========================================
FUNCTION: stringDemo
DESCRIPTION: see EOF
RETURN VALUES:
	Vowelless string
	Prints some data
*/
void stringDemo();

/*========================================
FUNCTION: cstringDemo
DESCRIPTION: see EOF
PARAMETERS:
	OutputString[] (O) - a cstring, vowelless
RETURN VALUES:
	Output array passed by reference
	Prints some data
*/
void cstringDemo(char OutputString[], int size);

/*========================================
FUNCTION: RmVowels
DESCRIPTION: removes vowels from a string or cstring
PARAMETERS:
	input - the input string
	input[] - input cstring
	output[] - output cstring
	size - the array size of the cstring
RETURN VALUES:
	string type: string without vowels
	cstring: output array, input with vowels removed
*/
string RmVowels(string input);
void RmVowels(const char input[], char output[], int size);

/*
- Declare a variable that holds your name (first last) and initialize it to your name.
- Prompt the user to guess your name (first last)
- Display a message saying whether or not the entered name matches your name
- Output the entered name
- Pass the entered name to a function (named removeVowels) which then returns a copy
	of the string with all the vowels removed (without destroying the original string)
	■ For the C-string version, you’ll need to get the vowelless string back by reference
		(you can’t “return” arrays)
	■ For the string datatype version, you can return the vowelless string.
	■ both functions should be named removeVowels (example of function
		overloading), which works because the argument list is different
	■ Note: when working with c-strings (character arrays), you’ll probably have
		to copy the non-vowel characters one by one, I don’t think any of the str
- functions (aside from strlen) will help.
- Print the vowelless string (which was obtained from the function)
- Concatenate the entered name with the text “ the Barbarian”, storing the result into well
	named variable, and then print this out.
*/
