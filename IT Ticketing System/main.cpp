
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
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

    // Enables users to enter login credentials with 3 attempts.
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
            cout << "Try again, please." << endl;

            numOfAttempts++;
        }

    } while (!loggedOn && numOfAttempts < 3);

    if (!loggedOn)
    {
        cout << "This program will now exit." << endl;
        return 0;
    }

    // Main menu interface with 4 options.
    cout << endl;
    cout << "Hi, you're inside this menu!" << endl;

    int choice = 0;

    do
    {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Create a Ticket" << endl;
        cout << "2. View Existing Ticket" << endl;
        cout << "3. Update A Ticket" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            // ====================================
            // CASE 1: CREATE A TICKET
            // ====================================

        case 1:
        {
            string ticketHolder;
            string ticketName;
            string ticketDate;
            string description;

            cout << "\n===== CREATE A TICKET =====" << endl;

            // Clear the newline left from cin >> choice.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Ticket Holder: ";
            getline(cin, ticketHolder);

            cout << "Ticket Name: ";
            getline(cin, ticketName);

            cout << "Date of Ticket (MM/DD/YYYY): ";
            getline(cin, ticketDate);

            cout << "Description: ";
            getline(cin, description);

            // Generate filename from ticket name.
            string fileName = ticketName + ".txt";

            // Check if a ticket with this filename already exists.
            if (filesystem::exists(fileName))
            {
                cout << "\nA ticket with this name already exists!" << endl;
                cout << "Please choose another ticket name." << endl;
                break;
            }

            // Create a new ticket file.
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

                if (ticketFile.fail())
                {
                    cout << "Error: Could not finish saving ticket." << endl;
                }
                else
                {
                    cout << "\nTicket saved successfully!" << endl;
                    cout << "Filename: " << fileName << endl;
                    cout << "Ticket saved at: "
                        << filesystem::absolute(fileName) << endl;
                }
            }
            else
            {
                cout << "Error: Could not save ticket." << endl;
            }

            break;
        }

        // ====================================
        // CASE 2: VIEW EXISTING TICKET
        // ====================================

        case 2:
        {
            string ticketName;
            string fileName;
            string line;

            cout << "\n===== VIEW EXISTING TICKET =====" << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the ticket name: ";
            getline(cin, ticketName);

            fileName = ticketName + ".txt";

            // Open the file for reading only.
            ifstream ticketFile(fileName);

            if (ticketFile.is_open())
            {
                cout << "\n===== TICKET CONTENTS =====" << endl;

                // Display each line of the ticket.
                while (getline(ticketFile, line))
                {
                    cout << line << endl;
                }

                ticketFile.close();

                cout << "\nEnd of ticket." << endl;
            }
            else
            {
                cout << "Ticket not found or cannot be opened!" << endl;
            }

            break;
        }

        // ====================================
        // CASE 3: UPDATE A TICKET
        // ====================================

        case 3:
        {
            string ticketName;
            string fileName;
            string ticketTitle;
            string ticketHolder;
            string ticketDate;
            string description;
            string separator;
            string newValue;
            int updateChoice;

            cout << "\n===== UPDATE A TICKET =====" << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter ticket name: ";
            getline(cin, ticketName);

            fileName = ticketName + ".txt";

            // Open the existing ticket.
            ifstream inputFile(fileName);

            if (!inputFile.is_open())
            {
                cout << "Ticket not found!" << endl;
                break;
            }

            // Read the existing ticket information.
            getline(inputFile, ticketTitle);
            getline(inputFile, ticketHolder);
            getline(inputFile, ticketDate);
            getline(inputFile, description);
            getline(inputFile, separator);

            if (!inputFile)
            {
                cout << "Error: Ticket file is incomplete." << endl;
                inputFile.close();
                break;
            }

            inputFile.close();

            cout << "\n1. Update Description" << endl;
            cout << "2. Update Ticket Holder" << endl;
            cout << "3. Cancel" << endl;
            cout << "Enter choice: ";

            if (!(cin >> updateChoice))
            {
                cout << "Invalid input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            if (updateChoice == 3)
            {
                cout << "Update cancelled." << endl;
                break;
            }

            if (updateChoice != 1 && updateChoice != 2)
            {
                cout << "Invalid choice." << endl;
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new value: ";
            getline(cin, newValue);

            if (updateChoice == 1)
            {
                description = "Description: " + newValue;
            }
            else
            {
                ticketHolder = "Ticket Holder: " + newValue;
            }

            // Rewrite the file with updated information.
            ofstream outputFile(fileName);

            if (!outputFile.is_open())
            {
                cout << "Error: Could not update ticket." << endl;
                break;
            }

            outputFile << ticketTitle << '\n';
            outputFile << ticketHolder << '\n';
            outputFile << ticketDate << '\n';
            outputFile << description << '\n';
            outputFile << separator << '\n';

            outputFile.close();

            if (outputFile.fail())
            {
                cout << "Error: Ticket may not have saved correctly." << endl;
            }
            else
            {
                cout << "\nTicket updated successfully!" << endl;
            }

            break;
        }

        // ====================================
        // CASE 4: EXIT
        // ====================================

        case 4:
        {
            cout << "\nExiting Sabbath Ticketing System..." << endl;
            break;
        }

        default:
        {
            cout << "Invalid menu selection! Try again." << endl;
            break;
        }

        } // End of switch

    } while (choice != 4); // End of main menu loop

    cout << "You have exited the program." << endl;

    return 0;
}
