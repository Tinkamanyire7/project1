#ifndef REG_BOOKING_H
#define REG_BOOKING_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Booking
{
private:
    string roomName;

public:
    int booking_Id;
    Booking() : booking_Id(0), roomName("") {}
    Booking(int bookingid, string r_name) : booking_Id(bookingid), roomName(r_name) {}

    void setBookingId(int b_Id);
    int getBookingId() const;
    void set_room_name(string _room_name);
    string get_room_name() const;

    void saveBooking(ofstream &outfile) const
    {
        outfile << booking_Id << " " << roomName << endl;
    }

    void loadBooking(ifstream &infile)
    {
        infile >> booking_Id >> roomName;
    }
};

#endif