#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <limits>
#include "Reg_Hostel.h"
#define PASS_CODE "A1708"
using namespace std;
// Definitions of Hostel class functions
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

void Hostel::register_client()
{
    string name, user_number, phone;
    int booking_id;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter user number: ";
    cin >> user_number;
    cout << "Enter phone number: ";
    cin >> phone;
    cout << "Enter booking ID (1-100): ";
    cin >> booking_id;

    clients[booking_count++] = Client(name, user_number, booking_id);
}

void add_room(Hostel &hostel)
{
    string name;
    int occupancy, floor;
    bool self_contained;
    double price;
    char sc;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter room name: ";
        cin >> name;
        cout << "Enter occupancy: ";
        cin >> occupancy;
        cout << "Enter floor: ";
        cin >> floor;
        cout << "Self-contained (y/n): ";
        cin >> sc;
        self_contained = (sc == 'y' || sc == 'Y');
        cout << "Enter price: ";
        cin >> price;

        hostel.addRoom(name, occupancy, floor, self_contained, price, true);
    }
}

void Hostel::saveClients() const
{
    ofstream outfile("clients.txt");
    for (int i = 0; i < booking_count; i++)
    {
        clients[i].saveClient(outfile);
    }
    outfile.close();
}

void Hostel::loadClients()
{
    ifstream infile("clients.txt");
    if (infile)
    {
        while (!infile.eof() && booking_count < MAX_BOOKINGS)
        {
            clients[booking_count++].loadClient(infile);
        }
        infile.close();
    }
}

void Hostel::saveRooms() const
{
    ofstream outfile("rooms.txt");
    for (int i = 0; i < room_count; i++)
    {
        rooms[i].saveRoom(outfile);
    }
    outfile.close();
}

void Hostel::loadRooms()
{
    ifstream infile("rooms.txt");
    if (infile)
    {
        while (!infile.eof() && room_count < MAX_ROOMS)
        {
            rooms[room_count++].loadRoom(infile);
        }
        infile.close();
    }
}

void main_menu()
{
    cout << "\nWelcome, these are your options. Exit to store data!!" << endl;
    cout << "1. View Rooms\n";
    cout << "2. Add New Room\n";
    cout << "3. Register New Client\n";
    cout << "4. Exit\n";
}
