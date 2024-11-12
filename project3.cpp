#include <iostream>
#include <string>
#include <conio.h>
#define MAX_ROOMS 50
#define MAX_BOOKINGS 100
#define PASS_CODE "A1708"
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

class Client
{
private:
    string Name;
    string user_number;

public:
    Client() : Name(""), user_number("") {}
    Client(string name, string reg_no) : Name(name), user_number(reg_no) {}
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
    Client clients[MAX_BOOKINGS];
    int booking_count;
    int n_bookingId;
    int room_count;

    Hostel() : booking_count(0), n_bookingId(1), room_count(0) {}
    void addRoom(string name, const int &occupants, const int &floor, const bool &containment, double _price, bool _available);
    void check_details(string room_name) const;
    void book_room(string room_name);
    void changeroom(int booking_id, string newroom);
};
bool password_checker(string password, char Password[])
{
    int number_of_entries = 1;
    while (password != PASS_CODE && number_of_entries <= 5)
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
    }
    if (password == PASS_CODE)
    {
        return true;
    }
    else
    {
        cout << "Too many Attempts! Try Again Later!" << endl;
        exit(1);
    }
    return false;
}

int main()
{
    Hostel Olympia;
    Hostel Dreamworld;
    string name;
    string PWs = "";

    Olympia.addRoom("Room101", 2, 1, true, 500000, false);
    Olympia.addRoom("Room308", 1, 3, false, 800000, true);
    Olympia.addRoom("Room105", 2, 1, true, 500000, true);
    Olympia.addRoom("Room209", 2, 2, false, 400000, true);
    Olympia.addRoom("Room201", 2, 2, true, 500000, false);
    Olympia.room_count = 5;

    Client clients[5] = {
        Client("Esther", "23/U/0134"),
        Client("Kelly", "23/U/1464"),
        Client("Kisha", "24/U/0164"),
        Client("Kendra", "21/U/1136"),
        Client("Kia", "20/U/0915")};

    cout << "Enter your name: ";
    cin >> name;

    char Password[5] = {};
    cout << "Enter your password: ";
    for (int i = 0; i < 5; i++)
    {
        Password[i] = getch();
        cout << "*";
        PWs += Password[i];
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        if (name == clients[i].getName())
        {
            break;
        }
        else if ((name != clients[i].getName()) && i < 5)
        {
            continue;
        }
        else if ((name != clients[i].getName()) || i >= 5)
        {
            cout << "Incorrect name entered." << endl;
            exit(1);
        }
    }
    if (password_checker(PWs, Password))
    {
        // cout << "Success";
        Client c1;
        c1.setName(name);
        int clientChoice;
        cout << "\nWelcome, " << c1.getName() << "! Please choose an action:\n";
        cout << "1. Book a Room\n2. Get Room Details\n3. Exit\n";
        cout << "Choice: ";
        cin >> clientChoice;
        switch (clientChoice)
        {
        case 1:
        {
            string room_name;
            cout << "Enter room name to book: ";
            cin >> room_name;
            Olympia.book_room(room_name);
            break;
        }
        case 2:
        {
            string room_name;
            cout << "Enter the room whose details you want: ";
            cin >> room_name;
            for (int i = 0; i < Olympia.room_count; i++)
            {
                if (Olympia.rooms[i].get_room_name() == room_name)
                {
                    Olympia.rooms[i].get_room_details();
                }
                else
                {
                    cout << "Invalid room name entered.";
                }
            }
            break;
        }
        case 3:
        {
            exit(1);
        }
        default:
        {
            cout << "Invalid entry";
        }
        }
    }
    else
    {
        cout << "Incorrect password." << endl;
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

void Hostel::addRoom(string name, const int &occupants, const int &floor, const bool &containment, double _price, bool _available)
{
    if (room_count < MAX_ROOMS)
    {
        rooms[room_count++] = Room(name, occupants, floor, containment, _price, _available);
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
            cout << room_name << " has been successfully booked." << endl;
            found = true;
            break;
        }

        else if (rooms[i].get_room_name() == room_name && !(rooms[i].check_if_available()))
        {
            cout << "Sorry, " << room_name << " isn't available at the moment.";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Room " << room_name << " isn't available or doesn't exist." << endl;
    }
}
