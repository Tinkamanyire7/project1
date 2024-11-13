#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include "Booking.h"
using namespace std;
class Client
{
private:
    string Name;
    string user_number;

public:
    Booking client_booking;
    Client() : Name(""), user_number("") {}
    Client(string name, string reg_no, int booking_id) : Name(name), user_number(reg_no)
    {
        client_booking.setBookingId(booking_id);
    }
    string phone_number;
    void setName(string name);
    string getName() const;
    void setUser_number(string _user_number);
    string getUser_number() const;
    int getClientbookingId();
};
#endif