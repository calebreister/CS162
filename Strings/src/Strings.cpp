#include <Strings.h>

int main()
{
	string mode;
	bool error = true;
	while (error)//error checking loop
	{
		cout << "Run in mode: [string, cstring]" << endl
				<< ">>> ";
		getline(cin, mode);
		if (mode == "string")
		{
			stringDemo();
			error = false;
		}
		else if (mode == "cstring")
		{
			cstringDemo();
			error = false;
		}
		else cout << "Invalid input... try again." << endl;
	}
	return 0;
}

void stringDemo()
{

}

void cstringDemo(char OutputString[], int size)
{

}
