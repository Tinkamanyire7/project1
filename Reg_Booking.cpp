#include <iostream>
#include "Reg_Booking.h"
using namespace std;
// Definitions of Booking class functions
void Booking::setBookingId(int b_Id)
{
    booking_Id = b_Id;
}
int Booking::getBookingId() const
{
    return booking_Id;
}
void Booking::set_room_name(string _room_name)
{
    roomName = _room_name;
}
string Booking::get_room_name() const
{
    return roomName;
}