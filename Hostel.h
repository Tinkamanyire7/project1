#ifndef HOSTEL_H
#define HOSTEL_H
#include <iostream>
#include <string>
#include "Booking.h"
#include "Room.h"
#include "Client.h"
#define MAX_ROOMS 50
#define MAX_BOOKINGS 100
#define PASS_CODE "A1708"
class Hostel
{
public:
    Room rooms[MAX_ROOMS];
    Booking bookings[MAX_BOOKINGS];
    Client clients[MAX_BOOKINGS];
    int booking_count;
    int n_bookingId;
    int room_count;

    Hostel() : booking_count(0), n_bookingId(1), room_count(0) {}
    void addRoom(string name, const int &occupants, const int &floor, const bool &containment, double _price, bool _available);
    void check_details(string room_name) const;
    void book_room(string room_name);
    void changeroom(int booking_id, string newroom);
    void viewRooms(int room_count);
};
using namespace std;
#endif