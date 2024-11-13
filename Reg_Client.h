#ifndef REG_CLIENT_H
#define REG_CLIENT_H
#include <iostream>
#include <string>
#include "Reg_Booking.h"
using namespace std;
class Client
{
private:
    string Name;
    string user_number;

public:
    Booking client_booking;
    string phone_number;

    Client() : Name(""), user_number("") {}
    Client(string name, string reg_no, int booking_id) : Name(name), user_number(reg_no)
    {
        client_booking.setBookingId(booking_id);
    }

    void setName(string name);
    string getName() const;
    void setUser_number(string _user_number);
    string getUser_number() const;
    int getClientbookingId();

    void saveClient(ofstream &outfile) const
    {
        outfile << Name << " " << user_number << " " << client_booking.getBookingId() << endl;
    }

    void loadClient(ifstream &infile)
    {
        int booking_id;
        infile >> Name >> user_number >> booking_id;
        client_booking.setBookingId(booking_id);
    }
};
#endif