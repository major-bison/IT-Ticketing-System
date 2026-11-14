#include<iostream>
using namespace std;

int main()
{
	cout << "Hello world" << endl;
	cout << "Welcome to Sabbath Ticketing System!!" << endl;

	string account;
	string password;
	bool loggedOn = false;
	int numOfAttempts = 0;
	//Enables users to prompt for login credentials with 5 attempts
	do
	{
		cout << "Please Enter Your account name " << endl;
		cin >> account;
		cout << "Please Enter your password: " << endl;

		if (account == "admin" && password == "pass")
		{
			loggedOn = true;
		}
		else
		{
			cout << "Wrong Credentials!" << endl;
			cout << "Try again,please" << endl;

			numOfAttempts++;
		}
		//stops the while loop and goes into the main menu interface
	} while (!loggedOn && numOfAttempts <= 3);

	if (numOfAttempts > 3)
		cout << "this program will now exist" << endl;

	//Main menu interface

	//testing gitub
	return 0;
}