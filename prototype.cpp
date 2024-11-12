#include <iostream>
#include <string>
#include <conio.h>
#define MAX_ROOMS 50
#define MAX_BOOKINGS 100
#define ADMIN_CODE "A1708"
using namespace std;

class Room
{
private:
    string room_name;
    int occupancy;
    int floor;
    bool self_contained;

public:
    Room() : occupancy(0), floor(0), self_contained(false), price(0.0), available(true) {}
    Room(string name, int _occupancy) : room_name(name), occupancy(_occupancy), floor(0), self_contained(false), price(0.0), available(true) {}

    double price;
    bool available;
    void set_attributes(string r_name, int num, int r_floor, bool r_containment, double r_price, bool r_available);
    void get_room_details() const;
    string get_room_name() const;
    bool check_if_available() const;
    void make_available();
    void book_room();
};

class Client
{
private:
    string Name;
    string user_number;

public:
    Client() : Name(""), user_number("") {}
    string phone_number;
    void setName(string name);
    string getName();
    void setUser_number(string _user_number);
    string getUser_number();
};

class Booking
{
private:
    int booking_Id;
    string roomName;

public:
    Booking() : booking_Id(0), roomName("") {}
    Booking(int bookingid, string r_name) : booking_Id(bookingid), roomName(r_name) {}

    int getBookingId() const;
    void set_room_name(string _room_name);
    string get_room_name() const;
};

class Hostel
{
public:
    Room rooms[MAX_ROOMS];
    Booking bookings[MAX_BOOKINGS];
    int booking_count;
    int n_bookingId;
    int room_count;

    Hostel() : booking_count(0), n_bookingId(1), room_count(0) {}
    void addRoom(string name, const int &occupants);
    void check_details(string room_name) const;
    void book_room(string room_name);
    void changeroom(int booking_id, string newroom);
};

// Password checker for an administrator
void password_checker(string password, char Password[])
{
    int number_of_entries = 1;
    while (password != ADMIN_CODE)
    {
        password = "";
        cout << "Re-Enter Password: ";
        for (int i = 0; i < 5; i++)
        {
            Password[i] = getch();
            cout << "*";
            password += Password[i];
        }
        cout << endl;
        number_of_entries++;
        if (number_of_entries > 3)
        {
            cout << "Too many Attempts! Try Again Later!" << endl;
            exit(1);
        }
    }
}

int main()
{
    Hostel hostel;
    int userType;

    hostel.addRoom("Room101", 2);
    hostel.addRoom("Room102", 1);
    hostel.room_count = 2;

    cout << "Welcome to the Hostel Management System!" << endl;
    cout << "Please select user type: \n1. Administrator\n2. Client\n";
    cin >> userType;

    if (userType == 1)
    {
        string PWs = "";
        char Password[5] = {};
        cout << "Enter Password (ADMIN_CODE of 5 characters):";
        for (int i = 0; i < 5; i++)
        {
            Password[i] = getch();
            cout << "*";
            PWs += Password[i];
        }
        cout << endl;
        password_checker(PWs, Password);
        cout << endl;

        int adminChoice;
        cout << "\nAdministrator Menu:\n1. Allocate Room\n2. Make Room Available\n";
        cin >> adminChoice;

        if (adminChoice == 1)
        {
            string room_name;
            cout << "Enter room name to allocate: ";
            cin >> room_name;
            hostel.book_room(room_name);
        }
        else if (adminChoice == 2)
        {
            string room_name;
            cout << "Enter room name to make available: ";
            cin >> room_name;
            bool found = false;
            for (int i = 0; i < hostel.room_count; ++i)
            {
                if (hostel.rooms[i].get_room_name() == room_name)
                {
                    hostel.rooms[i].make_available();
                    cout << "Room " << room_name << " is now available." << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Room " << room_name << " not found." << endl;
            }
        }
        else
        {
            cout << "Invalid option selected." << endl;
        }
    }
    else if (userType == 2)
    {
        Client client;
        int clientChoice;
        cout << "Enter your name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        client.setName(name);

        cout << "\nWelcome, " << client.getName() << "! Please choose an action:\n";
        cout << "1. Book a Room\n2. Change Room\n3. Leave Room\n4. Get Room Details";
        cin >> clientChoice;

        if (clientChoice == 1)
        {
            string room_name;
            cout << "Enter room name to book: ";
            cin >> room_name;
            hostel.book_room(room_name);
        }
        else if (clientChoice == 2)
        {
            int booking_id;
            string newroom;
            cout << "Enter booking ID to change room: ";
            cin >> booking_id;
            cout << "Enter new room name: ";
            cin >> newroom;
            hostel.changeroom(booking_id, newroom);
        }
        else if (clientChoice == 3)
        {
            int booking_id;
            cout << "Enter booking ID to leave room: ";
            cin >> booking_id;
            bool found = false;
            for (int i = 0; i < hostel.booking_count; ++i)
            {
                if (hostel.bookings[i].getBookingId() == booking_id)
                {
                    string room_name = hostel.bookings[i].get_room_name();
                    for (int j = 0; j < hostel.room_count; ++j)
                    {
                        if (hostel.rooms[j].get_room_name() == room_name)
                        {
                            hostel.rooms[j].make_available();
                            cout << "You have successfully left room " << room_name << "." << endl;
                            found = true;
                            break;
                        }
                    }
                    break;
                }
            }
            if (!found)
            {
                cout << "Booking ID not found." << endl;
            }
        }
        else if (clientChoice == 4)
        {
            string room_name;
            cout << "Enter the room whose details you want: ";
            cin >> room_name;
            for (int i = 0; i < MAX_ROOMS; i++)
            {
                if (hostel.rooms[i].get_room_name() == room_name)
                {
                    hostel.rooms[i].get_room_details();
                }
                else
                {
                    cout << "Invalid room name entered.";
                }
            }
        }
        else
        {
            cout << "Invalid option selected." << endl;
        }
    }
    else
    {
        cout << "Invalid user type selected." << endl;
    }

    return 0;
}

// Definitions of member functions
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

void Client::setName(string name)
{
    Name = name;
}

string Client::getName()
{
    return Name;
}

void Client::setUser_number(string _user_number)
{
    user_number = _user_number;
}

string Client::getUser_number()
{
    return user_number;
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

void Hostel::addRoom(string name, const int &occupants)
{
    if (room_count < MAX_ROOMS)
    {
        rooms[room_count++] = Room(name, occupants);
    }
    else
    {
        cout << "Maximum room limit reached. Cannot add more rooms." << endl;
    }
}

void Hostel::check_details(string room_name) const
{
    bool found = false;
    for (int i = 0; i < room_count; i++)
    {
        if (rooms[i].get_room_name() == room_name)
        {
            rooms[i].get_room_details();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Room " << room_name << " not found." << endl;
    }
}

void Hostel::book_room(string room_name)
{
    bool found = false;
    for (int i = 0; i < room_count; i++)
    {
        if (rooms[i].get_room_name() == room_name && rooms[i].check_if_available())
        {
            rooms[i].book_room();
            if (booking_count < MAX_BOOKINGS)
            {
                bookings[booking_count++] = Booking(n_bookingId++, room_name);
            }
            cout << "Room " << room_name << " has been successfully booked." << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Room " << room_name << " isn't available or doesn't exist." << endl;
    }
}

void Hostel::changeroom(int booking_id, string newroom)
{
    bool bookingFound = false, roomFound = false;
    for (int i = 0; i < booking_count; i++)
    {
        if (bookings[i].getBookingId() == booking_id)
        {
            bookingFound = true;
            for (int j = 0; j < room_count; j++)
            {
                if (rooms[j].get_room_name() == newroom && rooms[j].check_if_available())
                {
                    rooms[j].book_room();
                    rooms[j].make_available();
                    bookings[i].set_room_name(newroom);
                    cout << "Room changed successfully to " << newroom << endl;
                    roomFound = true;
                    break;
                }
            }
            break;
        }
    }
    if (!bookingFound)
    {
        cout << "Booking ID not found." << endl;
    }
    else if (!roomFound)
    {
        cout << "The new room isn't available." << endl;
    }
}
