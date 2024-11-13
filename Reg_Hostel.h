#ifndef REG_HOSTEL_H
#define REG_HOSTEL_H
#include <iostream>
#include <string>
#include "Reg_Booking.h"
#include "Reg_Room.h"
#include "Reg_Client.h"
#define MAX_ROOMS 50
#define MAX_BOOKINGS 100
#define PASS_CODE "A1708"
class Hostel
{
public:
    Room rooms[MAX_ROOMS];
    Client clients[MAX_BOOKINGS];
    int booking_count;
    int n_bookingId;
    int room_count;

    Hostel() : booking_count(0), n_bookingId(1), room_count(0)
    {
        loadRooms();
        loadClients();
    }

    void addRoom(string name, const int &occupants, const int &floor, const bool &containment, double _price, bool _available);
    void check_details(string room_name) const;
    void book_room(string room_name);
    void viewRooms(int room_count);
    void register_client();
    void loadRooms();
    void saveRooms() const;
    void loadClients();
    void saveClients() const;
};

#endif