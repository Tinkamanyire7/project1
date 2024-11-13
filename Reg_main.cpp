#include <iostream>
#include <limits>
#include "Reg_Hostel.h"
using namespace std;

void add_room(Hostel &hostel);
void main_menu();
int main()
{
    Hostel Olympia;
    string name, PWs = "";
    int choice;

    while (true)
    {
        main_menu();
        cout << "Enter Choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number." << endl;
            continue;
        }

        if (choice == 1)
        {
            cout << "Welcome, these are the available rooms." << endl;
            Olympia.viewRooms(Olympia.room_count);
        }
        else if (choice == 2)
        {
            add_room(Olympia);
        }
        else if (choice == 3)
        {
            Olympia.register_client();
        }
        else if (choice == 4)
        {
            cout << "Closing Program and saving data..." << endl;
            Olympia.saveRooms();
            Olympia.saveClients();
            exit(1);
        }
    }
    return 0;
}