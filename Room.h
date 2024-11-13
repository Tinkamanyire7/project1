#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
using namespace std;
class Room
{
private:
    string room_name;
    int occupancy; // A room can accommodate one(single) or two people(double)
    int floor;
    bool self_contained;

public:
    Room() : occupancy(0), floor(0), self_contained(false), price(0.0), available(true) {}
    Room(string name, int _occupancy, int _floor, bool containment, double _price, bool _available)
        : room_name(name), occupancy(_occupancy), floor(_floor), self_contained(containment), price(_price), available(_available) {}

    double price;
    bool available;
    void set_attributes(string r_name, int num, int r_floor, bool r_containment, double r_price, bool r_available);
    void get_room_details() const;
    string get_room_name() const;
    bool check_if_available() const;
    void make_available();
    void book_room();
};
#endif