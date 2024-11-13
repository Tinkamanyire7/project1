#include <iostream>
#include <conio.h>
#include <limits>
#include "Room.h"
#include "Booking.h"
#include "Client.h"
#include "Hostel.h"

using namespace std;
bool password_checker(string password, char Password[]);
void main_menu();
int main()
{
    Hostel Olympia;
    Hostel Dreamworld;
    string reg_no;
    string PWs = "";
    int choice;
    string name;

    Olympia.addRoom("Room101", 2, 1, true, 500000, false);
    Olympia.addRoom("Room308", 1, 3, false, 800000, true);
    Olympia.addRoom("Room105", 2, 1, true, 500000, true);
    Olympia.addRoom("Room209", 2, 2, false, 400000, true);
    Olympia.addRoom("Room201", 2, 2, true, 500000, false);
    Olympia.room_count = 5;

    Client clients[5] = {
        Client("Esther", "23/U/0134", 1098),
        Client("Kelly", "23/U/1464", 2016),
        Client("Kisha", "24/U/0164", 5567),
        Client("Kendra", "21/U/1136", 2149),
        Client("Kia", "20/U/0915", 4239)};

    while (1)
    {
        main_menu();

        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1)
        {

            cout << "Welcome, these are the availbale rooms." << endl;
            Olympia.viewRooms(Olympia.room_count);

        start:

            Client c1;
            cout << "Enter your name: ";
            cin >> name;
            c1.setName(name);

            cout << "Enter your registration number: ";
            cin >> reg_no;

            bool found = false;

            for (int i = 0; i < 5; i++)
            {
                if (reg_no == clients[i].getUser_number())
                {
                    found = true;
                    break; // Exit the loop as soon as a match is found
                }
            }
            if (found)
            {
                char Password[5] = {};
                cout << "Enter your password: ";
                for (int i = 0; i < 5; i++)
                {
                    Password[i] = getch();
                    cout << "*";
                    PWs += Password[i];
                }
                cout << endl;

                if (password_checker(PWs, Password))
                {
                options:
                    c1.setUser_number(reg_no);
                    int clientChoice;
                    cout << "\nWelcome, " << c1.getName() << "! Please choose an action:\n";
                    cout << "1. Book a Room\n2. Get Room Details\n3. Exit\n";
                    cout << "Choice: ";
                    cin >> clientChoice;
                    switch (clientChoice)
                    {
                    case 1:
                    {
                        string room_name;
                        int booking_id;

                        // Loop until valid input is entered
                        while (true)
                        {
                            try
                            {
                                // Prompt for room name and booking ID
                                cout << "Enter room name to book: ";
                                cin >> room_name;
                                cout << "Enter your booking id: ";
                                cin >> booking_id;

                                // Check for invalid input
                                if (!cin)
                                {
                                    throw string("Invalid input detected. Please enter a valid room name and booking ID.");
                                }

                                // Validate booking ID
                                bool b_found = false;
                                for (int i = 0; i < 5; i++)
                                {
                                    if (booking_id == clients[i].getClientbookingId())
                                    {
                                        b_found = true;
                                        break;
                                    }
                                }

                                // Check if booking ID is valid
                                if (b_found)
                                {
                                    Olympia.book_room(room_name);
                                    break; // Exit the loop once booking is successful
                                }
                                else
                                {
                                    cout << "Booking ID is unidentified." << endl;
                                }
                            }
                            catch (const string &e)
                            {
                                // Handle invalid input
                                cout << e << endl;

                                // Clear error flags and ignore remaining input to reset cin
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                        break;
                    }

                    case 2:
                    {
                        string room_name;
                        cout << "Enter the room whose details you want: ";
                        cin >> room_name;
                        bool room_found = false;
                        for (int i = 0; i < Olympia.room_count; i++)
                        {
                            if (Olympia.rooms[i].get_room_name() == room_name)
                            {
                                Olympia.rooms[i].get_room_details();
                                room_found == true;
                                cout << endl;
                                break;
                            }
                        }
                        if (!room_found)
                        {
                            cout << "Invalid room name entered." << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "Thank you for your time." << endl;
                        exit(1);
                    }
                    default:
                    {
                        cout << "Invalid entry" << endl;
                    }
                    }
                    goto options;
                }
                else
                {
                    cout << "Incorrect password." << endl;
                    goto start;
                }
            }
            else
            {
                cout << "Incorrect name entered." << endl;
                goto start;
            }
        }
        else
        {
            cout << "Closing Program" << endl;
            exit(1);
        }
    }

    return 0;
}
