#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <filesystem>
using namespace std;

//Function Prototypes
void displayWelcomeMenu(); //function woreks
void displayMainMenu();
void createTicket();
void viewTicket();
void updateTicket();

int main()
{
    cout << "Hello world!" << endl;
    int welcomeChoice = 0;

    // OUTER LOOP: Keep the program running until the user quits.

    do
    {
        //implementing the function
        displayWelcomeMenu();

        //cin.ignore functions discard any inccorrect inputs
        //I wrote continue so it can clear the incorrect input and
        //run the login menu again. 
        //cin>>welcome choice was impletemnted inside the if statement for clearer choice

        if (!(cin >> welcomeChoice))
        {
            cout << "sorry!,invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (welcomeChoice == 1)
        {
            string account;
            string password;
            bool loggedOn = false;
            int numOfAttempts = 0;

            // LOGIN LOOP: Allow up to 3 attempts.
            do
            {
                //let's put a login screen here
                cout << "\n===== LOGIN SCREEN =====\n";

                cout << "Username: ";
                cin >> account;

                cout << "Password: ";
                cin >> password;

                if (account == "admin" && password == "pass")
                {
                    loggedOn = true;
                    cout << "\nLogin successful! Welcome, "
                        << account << "!\n";
                }
                else
                {
                    numOfAttempts++;
                    cout << "\nIncorrect username or password.\n";
                    cout << "Attempts remaining: "
                        << 3 - numOfAttempts << endl;
                }

            } while (!loggedOn && numOfAttempts < 3);

            if (!loggedOn)
            {
                cout << "\nMaximum login attempts reached.\n";
                cout << "Returning to login menu...\n";
            }
            else
            {
                int choice = 0;

                // MAIN MENU LOOP
                do
                {
                
                    displayMainMenu();

                    if (!(cin >> choice))
                    {
                        cout << "Invalid input! Enter a number.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }

                    switch (choice)
                    {
                       
                    case 1:
                    {

                        createTicket();
                        break;
                        }
               
                    case 2:
                    {

                        //display viewTickets function
                       
                        viewTicket();
                        break;
                    }

                
                    case 3:
                    {

                        //added sepperator for now, so it'll keep the t ickets readable.
                        //The varialbe newValue is used to store updated infomratin.

                        string ticketName;
                        string fileName;
                        string ticketTitle;
                        string ticketHolder;
                        string ticketDate;
                        string description;
                        string separator;
                        string newValue;
                        int updateChoice = 0;

                        cout << "\n===== UPDATE A TICKET =====\n";

                        cin.ignore(
                            numeric_limits<streamsize>::max(), '\n');

                        cout << "Enter ticket name: ";
                        getline(cin, ticketName);

                        fileName = ticketName + ".txt";

                        // Read the existing ticket.
                        ifstream inputFile(fileName);

                        if (!inputFile.is_open())
                        {
                            cout << "Ticket not found!\n";
                            break;
                        }

                        getline(inputFile, ticketTitle);
                        getline(inputFile, ticketHolder);
                        getline(inputFile, ticketDate);
                        getline(inputFile, description);
                        getline(inputFile, separator);

                        if (!inputFile)
                        {
                            cout << "Error: Ticket file is incomplete.\n";
                            inputFile.close();
                            break;
                        }

                        inputFile.close();

                        cout << "\n1. Update Description\n";
                        cout << "2. Update Ticket Holder\n";
                        cout << "3. Cancel\n";
                        cout << "Enter choice: ";

                        if (!(cin >> updateChoice))
                        {
                            cout << "Invalid input!\n";
                            cin.clear();
                            cin.ignore(
                                numeric_limits<streamsize>::max(), '\n');
                            break;
                        }

                        if (updateChoice == 3)
                        {
                            cout << "Update cancelled.\n";
                            break;
                        }

                        if (updateChoice != 1 && updateChoice != 2)
                        {
                            cout << "Invalid choice.\n";
                            break;
                        }

                        cin.ignore(
                            numeric_limits<streamsize>::max(), '\n');

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

                        // Rewrite ticket with updated information.
                        ofstream outputFile(fileName);

                        if (!outputFile.is_open())
                        {
                            cout << "Error: Could not update ticket.\n";
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
                            cout << "Error: Ticket may not "
                                << "have saved correctly.\n";
                        }
                        else
                        {
                            cout << "\nTicket updated successfully!\n";
                        }

                        break;
                    }

                    // ================================
                    // CASE 4: LOGOUT
                    // ================================
                    case 4:
                    {
                        cout << "\nLogging out...\n";
                        cout << "Returning to login screen...\n";
                        break;
                    }

                    default:
                    {
                        cout << "Invalid menu selection!\n";
                        break;
                    }

                    } // End of switch

                } while (choice != 4); // End of main menu loop

                loggedOn = false; // User is now logged out.
            }
        }
        else if (welcomeChoice != 2)
        {
            cout << "Invalid selection! Try again.\n";
        }

    } while (welcomeChoice != 2); // End of welcome loop

    cout << "\n Thank you for using Sabbath Ticketing System!\n";
    cout << "Program will be terminated.\n";

    return 0;
}


//Function definition 

void displayWelcomeMenu()
{

    cout << "\n====================================\n";
    cout << "     SABBATH TICKETING SYSTEM\n";
    cout << "====================================\n";
    cout << "1. Login (Username and Password)\n";
    cout << "2. Quit Program\n";
    cout << "Enter choice: ";


}

void displayMainMenu()
{

    cout << "\n====================================\n";
    cout << "            MAIN MENU\n";
    cout << "====================================\n";
    cout << "1. Create a Ticket\n";
    cout << "2. View Existing Ticket\n";
    cout << "3. Update a Ticket\n";
    cout << "4. Logout\n";
    cout << "Enter choice: ";
}

void createTicket()
{

    //Let's impplement create a ticket function here
    string ticketHolder;
    string ticketName;
    string ticketDate;
    string description;

    cout << "\n===== CREATE A TICKET =====\n";

    cin.ignore(
        numeric_limits<streamsize>::max(), '\n');

    cout << "Ticket Holder: ";
    getline(cin, ticketHolder);

    cout << "Ticket Name: ";
    getline(cin, ticketName);

    cout << "Date of Ticket (MM/DD/YYYY): ";
    getline(cin, ticketDate);

    cout << "Description: ";
    getline(cin, description);

    // Prevent empty or invalid filenames.
    if (ticketName.empty() ||
        ticketName.find_first_of(
            "\\/:*?\"<>|") != string::npos ||
        ticketName == "." ||
        ticketName == ".." ||
        ticketName.back() == '.' ||
        ticketName.back() == ' ')
    {
        cout << "Invalid ticket name.\n";
        return;
    }

    // Generate filename from ticket name.
    string fileName = ticketName + ".txt";

    // Prevent overwriting existing tickets.
    if (filesystem::exists(fileName))
    {
        cout << "\nA ticket with this name "
            << "already exists!\n";
        cout << "Please choose another name.\n";
        return;
    }

    // Create ticket file.
    ofstream ticketFile(fileName);

    if (ticketFile.is_open())
    {
        ticketFile << "Ticket: No 01: "
            << ticketName << '\n';

        ticketFile << "Ticket Holder: "
            << ticketHolder << '\n';

        ticketFile << "Date: "
            << ticketDate << '\n';

        ticketFile << "Description: "
            << description << '\n';

        ticketFile << "------------------------\n";

        ticketFile.close();

        if (ticketFile.fail())
        {
            cout << "Error saving ticket.\n";
        }
        else
        {
            cout << "\nTicket saved successfully!\n";
            cout << "Filename: "
                << fileName << endl;
            cout << "Ticket saved at: "
                << filesystem::absolute(fileName)
                << endl;
        }
    }
    else
    {
        cout << "Error: Could not create ticket.\n";
    }


}

void viewTicket()
{

    string ticketName;
    string fileName;
    string line;

    cout << "\n===== VIEW EXISTING TICKET =====\n";

    cin.ignore(
        numeric_limits<streamsize>::max(), '\n');

    cout << "Enter ticket name: ";
    getline(cin, ticketName);

    fileName = ticketName + ".txt";

    // Open file for reading only.
    ifstream ticketFile(fileName);

    if (ticketFile.is_open())
    {
        cout << "\n===== TICKET CONTENTS =====\n";

        while (getline(ticketFile, line))
        {
            cout << line << endl;
        }

        ticketFile.close();

        cout << "\nEnd of ticket.\n";
    }
    else
    {
        cout << "Ticket not found or "
            << "cannot be opened!\n";
    }


}

void updateTicket()
{

    //added sepperator for now, so it'll keep the t ickets readable.
                        //The varialbe newValue is used to store updated infomratin.

    string ticketName;
    string fileName;
    string ticketTitle;
    string ticketHolder;
    string ticketDate;
    string description;
    string separator;
    string newValue;
    int updateChoice;

    cout << "\n===== UPDATE A TICKET =====\n";

    cin.ignore(
        numeric_limits<streamsize>::max(), '\n');

    cout << "Enter ticket name: ";
    getline(cin, ticketName);

    fileName = ticketName + ".txt";

    // Read the existing ticket.
    ifstream inputFile(fileName);

    //validates if the ticket has been found or not
    if (!inputFile.is_open())
    {
        cout << "Ticket not found!\n";
        return;
    }

    //IF FILE was found then extract every data from file
    getline(inputFile, ticketTitle);
    getline(inputFile, ticketHolder);
    getline(inputFile, ticketDate);
    getline(inputFile, description);
    getline(inputFile, separator);

    //If ticket is corrupted
    if (!inputFile)
    {
        cout << "Error: Ticket file is incomplete.\n";
        inputFile.close();
        return;
    }

    //Close the file, dont need to leave it open to update
    inputFile.close();


    cout << "\n1. Update Description\n";
    cout << "2. Update Ticket Holder\n";
    cout << "3. Cancel\n";
    cout << "Enter choice: ";

    //If a user inputs the wrong data type, trigger this response

    if (!(cin >> updateChoice))
    {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(
            numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (updateChoice == 3)
    {
        cout << "Update cancelled.\n";
        return;
    }

    //If user inputs an number that's not 1 or 2
    if (updateChoice != 1 && updateChoice != 2)
    {
        cout << "Invalid choice.\n";
        return;
    }

    cin.ignore(
        numeric_limits<streamsize>::max(), '\n');
    //IF user picks one then this code will follow

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

    // Overwrites the ticket with updated information.
    ofstream outputFile(fileName);

    if (!outputFile.is_open())
    {
        cout << "Error: Could not update ticket.\n";
        return;
    }

    outputFile << ticketTitle << '\n';
    outputFile << ticketHolder << '\n';
    outputFile << ticketDate << '\n';
    outputFile << description << '\n';
    outputFile << separator << '\n';

    outputFile.close();

    if (outputFile.fail())
    {
        cout << "Error: Ticket may not "
            << "have saved correctly.\n";
    }
    else
    {
        cout << "\nTicket updated successfully!\n";
    }

    break;
}


}