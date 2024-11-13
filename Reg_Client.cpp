#include <iostream>
#include "Reg_Client.h"
// Definitions of Client class functions
void Client::setName(string name)
{
    Name = name;
}
string Client::getName() const
{
    return Name;
}
void Client::setUser_number(string _user_number)
{
    user_number = _user_number;
}
string Client::getUser_number() const
{
    return user_number;
}
int Client::getClientbookingId()
{
    return (client_booking.getBookingId());
}
