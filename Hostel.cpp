#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <limits>
#include "Hostel.h"
#define PASS_CODE "A1708"
using namespace std;
void Hostel::addRoom(string name, const int &occupants, const int &floor, const bool &containment, double _price, bool _available)
{
    if (room_count < MAX_ROOMS)
    {
        rooms[room_count++] = Room(name, occupants, floor, containment, _price, _available);
    }
    else
    {
        cout << "Maximum room limit reached. Cannot add more rooms." << endl;
    }
}

void Hostel::check_details(string room_name) const
{
    bool found = false;
    for (int i = 0; i < room_count; i++)
    {
        if (rooms[i].get_room_name() == room_name)
        {
            rooms[i].get_room_details();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Room " << room_name << " not found." << endl;
    }
}

void Hostel::book_room(string room_name)
{
    bool found = false;
    for (int i = 0; i < room_count; i++)
    {
        if (rooms[i].get_room_name() == room_name && rooms[i].check_if_available())
        {
            rooms[i].book_room();
            cout << room_name << " has been successfully booked." << endl;
            found = true;
            break;
        }

        else if (rooms[i].get_room_name() == room_name && !(rooms[i].check_if_available()))
        {
            cout << "Sorry, " << room_name << " isn't available at the moment." << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Room " << room_name << " isn't available or doesn't exist." << endl;
    }
}
void Hostel::viewRooms(int room_count)
{
    cout << "+-----------------+-----------------+" << endl;
    cout << "| " << left << setw(15) << "Rooms" << " |  " << setw(15) << "Prices" << "|" << endl;
    cout << "+-----------------+-----------------+" << endl;
    for (int i = 0; i < room_count; i++)
    {
        cout << "| " << left << setw(15) << rooms[i].get_room_name() << " |  " << setw(15) << rooms[i].price << "|" << endl;
        cout << "+-----------------+-----------------+" << endl;
    }
    cout << endl;
}

// User Main  Menu
void main_menu()
{
    cout << "\nWelcome Students!!" << endl;
    cout << "1.Login\n";
    cout << "2.Exit\n";
}

bool password_checker(string password, char Password[])
{
    int number_of_entries = 1;
    while (password != PASS_CODE && number_of_entries <= 5)
    {
        password = "";
        cout << "Re-Enter Password: ";
        for (int i = 0; i < 5; i++)
        {
            Password[i] = getch();
            cout << "*";
            password += Password[i];
        }
        cout << endl;
        number_of_entries++;
    }
    if (password == PASS_CODE)
    {
        return true;
    }
    else
    {
        cout << "Too many Attempts! Try Again Later!" << endl;
        exit(1);
    }
    return false;
}