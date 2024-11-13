#ifndef REG_ROOM_H
#define REG_ROOM_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Room
{
private:
    string room_name;
    int occupancy;
    int floor;
    bool self_contained;

public:
    double price;
    bool available;

    Room() : occupancy(0), floor(0), self_contained(false), price(0.0), available(true) {}

    Room(string name, int _occupancy, int _floor, bool containment, double _price, bool _available)
        : room_name(name), occupancy(_occupancy), floor(_floor), self_contained(containment), price(_price), available(_available) {}

    void set_attributes(string r_name, int num, int r_floor, bool r_containment, double r_price, bool r_available);
    void get_room_details() const;
    string get_room_name() const;
    bool check_if_available() const;
    void make_available();
    void book_room();

    void saveRoom(ofstream &outfile) const
    {
        outfile << room_name << " " << occupancy << " " << floor << " " << self_contained << " " << price << " " << available << endl;
    }

    void loadRoom(ifstream &infile)
    {
        infile >> room_name >> occupancy >> floor >> self_contained >> price >> available;
    }
};

#endif