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
		cout << "Please Enter Your account name: " << endl;
		cin >> account;
		cout << "Please Enter your password: " << endl;
		cin >> password;

		if (account == "admin" && password == "pass")
		{
			loggedOn = true;
		}
		else
		{
			cout << endl;
			cout << "Wrong Credentials!" << endl;
			cout << "Try again,please" << endl;

			numOfAttempts++;
		}
		//stops the while loop and goes into the main menu interface
	} while (!loggedOn && numOfAttempts < 3);

	if (numOfAttempts >= 3)
		cout << "this program will now exit" << endl;
	//Main menu interface with 4 options

	if (loggedOn)
	{
		cout << endl;
		cout << "Hi, you're inside this menu!" << endl;

		int choice;

		do
		{

			cout << "1. Create a Ticket " << endl;
			cout << "2. View Existing Ticket" << endl;
			cout << "3. Update A Ticket" << endl;
			cout << "4. Exit" << endl;
			cin >> choice;

			switch (choice)
			{

			}





			
		} while (choice = !4);

		cout << "You have exit the program" << endl;
	}

	//Main menu interface with 4 options
	//Create a ticket, view a ticket, update a ticket, Quit


	//testing gitub
	return 0;
}