#include<iostream>
#include<string>
#include<limits>
#include<fstream>
#include <filesystem>
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



			case 1:
			{

				string ticketHolder;
				string ticketName;
				string ticketDate;
				string description;

				cout << "===== CREATE A TICKET =====" << endl;

				// This will clear the newline left from cin >> choice.
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Ticket Holder: ";
				getline(cin, ticketHolder);

				cout << "Ticket Name: ";
				getline(cin, ticketName);


				cout << "Date of Ticket (MM/DD/YYYY): ";
				getline(cin, ticketDate);

				cout << "Description: ";
				getline(cin, description);


				//Thisgenerates filename from the ticket name variable
				string fileName = ticketName + ".txt";

				// Create or append to the ticket file.
				ofstream ticketFile(fileName);

				if (ticketFile.is_open())
				{
					ticketFile << "Ticket: No 01: "
						<< ticketName << endl;

					ticketFile << "Ticket Holder: "
						<< ticketHolder << endl;

					ticketFile << "Date: "
						<< ticketDate << endl;

					ticketFile << "Description: "
						<< description << endl;

					ticketFile << "------------------------" << endl;

					ticketFile.close();

					cout << "\nTicket saved successfully!\n";
					cout << "Filename: " << fileName << endl;
					cout << "Ticket saved at: "
						<< filesystem::absolute(fileName)
						<< endl;


				}

				else
				{
					cout << "Error: Could not save ticket.\n";
				}

				//Here I Can immplete, oncce the ticket gets saved, it will stored
				//but if there's a ticket has the same name, cancel the save, 
				//and prompt the user to ask for another ticket name
				//is there a code syntax where I can store the tickets
			}




			case 2:
				cout << " View Existing Ticket" << endl;
				break;

			case 3:cout << "Update A Ticket" << endl;
				break;


			default:cout << "Wrong choice!" << endl;

			}






		} while (choice = !4);
		//I should add that it would go back to the login screen

		cout << "You have exit the program" << endl;


	}

	//Main menu interface with 4 options
	//Create a ticket, view a ticket, update a ticket, Quit


	//testing gitub
return 0;
}