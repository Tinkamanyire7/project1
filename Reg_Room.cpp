#include <iostream>
#include "Reg_Room.h"
using namespace std;
void Room::set_attributes(string r_name, int num, int r_floor, bool r_containment, double r_price, bool r_available)
{
    room_name = r_name;
    occupancy = num;
    floor = r_floor;
    self_contained = r_containment;
    price = r_price;
    available = r_available;
}

void Room::get_room_details() const
{
    cout << "Room: " << room_name << endl
         << "Occupancy: " << occupancy << endl
         << "Floor: " << floor << endl
         << "Room type: " << (self_contained ? "Self Contained" : "Non self-contained") << endl
         << "Room price: " << price << endl
         << "Available: " << (available ? "Yes" : "No") << endl;
}

// Definitions of Room class functions
bool Room::check_if_available() const
{
    return available;
}
string Room::get_room_name() const
{
    return room_name;
}
void Room::make_available()
{
    available = true;
}
void Room::book_room()
{
    available = false;
}
