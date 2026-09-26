#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==================== Room ====================

class Room
{
protected:
    int roomNumber;
    double basePrice;
    bool isAvailable;

public:
    Room(int rn, double bp)
    {
        roomNumber = rn;
        basePrice = bp;
        isAvailable = true;
    }

    int getroomNumber()
    {
        return roomNumber;
    }

    double getbasePrice()
    {
        return basePrice;
    }

    bool getisAvailable()
    {
        return isAvailable;
    }

    void setisAvailable(bool value)
    {
        isAvailable = value;
    }

    virtual double getPricePerNight() = 0;

    virtual string getType() = 0;

    virtual ~Room() {}
};

// ==================== Standard Room ====================

class StandardRoom : public Room
{
public:
    StandardRoom(int rn, double bp) : Room(rn, bp) {}

    double getPricePerNight() override
    {
        return basePrice * 2.2;
    }

    string getType() override
    {
        return "Standard";
    }
};

// ==================== Deluxe Room ====================

class DeluxeRoom : public Room
{
public:
    DeluxeRoom(int rn, double bp) : Room(rn, bp) {}

    double getPricePerNight() override
    {
        return basePrice * 1.5;
    }

    string getType() override
    {
        return "Deluxe";
    }
};

// ==================== Suite Room ====================

class SuiteRoom : public Room
{
public:
    SuiteRoom(int rn, double bp) : Room(rn, bp) {}

    double getPricePerNight() override
    {
        return basePrice;
    }

    string getType() override
    {
        return "Suite";
    }
};

// ==================== Guest ====================

class Guest
{
private:
    int id;
    string name;
    string phone;

public:
    Guest(int i, string n, string p)
    {
        id = i;
        name = n;
        phone = p;
    }

    int getid()
    {
        return id;
    }

    string getname()
    {
        return name;
    }

    string getphone()
    {
        return phone;
    }
};

// ==================== Booking ====================

class Booking
{
private:
    int bookingid;
    Guest* guest;
    Room* room;
    int numberOfNights;

public:
    Booking(int bi, Guest* g, Room* r, int nights)
    {
        bookingid = bi;
        guest = g;
        room = r;
        numberOfNights = nights;
    }

    double getTotalPrice()
    {
        return numberOfNights * room->getPricePerNight();
    }

    void displayBookingInfo()
    {
        cout << "Booking ID: " << bookingid << endl;
        cout << "Guest Name: " << guest->getname() << endl;
        cout << "Room Number: " << room->getroomNumber() << endl;
        cout << "Room Type: " << room->getType() << endl;
        cout << "Number Of Nights: " << numberOfNights << endl;
        cout << "Total Price: " << getTotalPrice() << endl;
    }
};

// ==================== Hotel ====================

class Hotel
{
private:
    vector<Room*> rooms;
    vector<Guest*> guests;
    vector<Booking*> bookings;

public:

    // ---------- Add Room ----------

    void addRoom()
    {
        int type;
        int roomNumber;
        double basePrice;

        cout << "\n========== ADD ROOM ==========\n";

        cout << "1. Standard Room\n";
        cout << "2. Deluxe Room\n";
        cout << "3. Suite Room\n";

        cout << "Enter room type: ";
        cin >> type;

        cout << "Enter room number: ";
        cin >> roomNumber;

        cout << "Enter base price: ";
        cin >> basePrice;

        Room* room = nullptr;

        if (type == 1)
        {
            room = new StandardRoom(roomNumber, basePrice);
        }
        else if (type == 2)
        {
            room = new DeluxeRoom(roomNumber, basePrice);
        }
        else if (type == 3)
        {
            room = new SuiteRoom(roomNumber, basePrice);
        }
        else
        {
            cout << "Invalid room type.\n";
            return;
        }

        rooms.push_back(room);

        cout << "Room added successfully.\n";
    }

    // ---------- Add Guest ----------

    void addGuest()
    {
        int id;
        string name;
        string phone;

        cout << "\n========== ADD GUEST ==========\n";

        cout << "Enter Guest ID: ";
        cin >> id;

        cout << "Enter Guest Name: ";
        cin >> name;

        cout << "Enter Phone: ";
        cin >> phone;

        Guest* guest = new Guest(id, name, phone);

        guests.push_back(guest);

        cout << "Guest added successfully.\n";
    }

    // ---------- Show Rooms ----------

    void showAllRooms()
    {
        cout << "\n========== ALL ROOMS ==========\n";

        if (rooms.empty())
        {
            cout << "No rooms available.\n";
            return;
        }

        for (Room* room : rooms)
        {
            cout << "Room Number: "
                 << room->getroomNumber() << endl;

            cout << "Room Type: "
                 << room->getType() << endl;

            cout << "Price Per Night: "
                 << room->getPricePerNight() << endl;

            cout << "Available: "
                 << (room->getisAvailable() ? "Yes" : "No")
                 << endl;

            cout << "------------------------\n";
        }
    }

    // ---------- Show Guests ----------

    void showAllGuests()
    {
        cout << "\n========== ALL GUESTS ==========\n";

        if (guests.empty())
        {
            cout << "No guests available.\n";
            return;
        }

        for (Guest* guest : guests)
        {
            cout << "ID: " << guest->getid() << endl;
            cout << "Name: " << guest->getname() << endl;
            cout << "Phone: " << guest->getphone() << endl;

            cout << "------------------------\n";
        }
    }

    // ---------- Find Guest ----------

    Guest* findGuest(int id)
    {
        for (Guest* guest : guests)
        {
            if (guest->getid() == id)
            {
                return guest;
            }
        }

        return nullptr;
    }

    // ---------- Find Room ----------

    Room* findRoom(int roomNumber)
    {
        for (Room* room : rooms)
        {
            if (room->getroomNumber() == roomNumber)
            {
                return room;
            }
        }

        return nullptr;
    }

    // ---------- Create Booking ----------

    void createBooking()
    {
        int bookingID;
        int guestID;
        int roomNumber;
        int nights;

        cout << "\n========== CREATE BOOKING ==========\n";

        cout << "Enter Booking ID: ";
        cin >> bookingID;

        cout << "Enter Guest ID: ";
        cin >> guestID;

        Guest* guest = findGuest(guestID);

        if (guest == nullptr)
        {
            cout << "Guest not found.\n";
            return;
        }

        cout << "Enter Room Number: ";
        cin >> roomNumber;

        Room* room = findRoom(roomNumber);

        if (room == nullptr)
        {
            cout << "Room not found.\n";
            return;
        }

        if (!room->getisAvailable())
        {
            cout << "Room is not available.\n";
            return;
        }

        cout << "Enter Number Of Nights: ";
        cin >> nights;

        Booking* booking =
            new Booking(bookingID, guest, room, nights);

        bookings.push_back(booking);

        room->setisAvailable(false);

        cout << "Booking created successfully.\n";
    }

    // ---------- Show Bookings ----------

    void showAllBookings()
    {
        cout << "\n========== ALL BOOKINGS ==========\n";

        if (bookings.empty())
        {
            cout << "No bookings available.\n";
            return;
        }

        for (Booking* booking : bookings)
        {
            booking->displayBookingInfo();

            cout << "------------------------\n";
        }
    }
};

// ==================== Main ====================

int main()
{
    Hotel hotel;

    int choice;

    do
    {
        cout << "\n";
        cout << "========== HOTEL MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Room\n";
        cout << "2. Add Guest\n";
        cout << "3. Show All Rooms\n";
        cout << "4. Show All Guests\n";
        cout << "5. Create Booking\n";
        cout << "6. Show All Bookings\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            hotel.addRoom();
            break;

        case 2:
            hotel.addGuest();
            break;

        case 3:
            hotel.showAllRooms();
            break;

        case 4:
            hotel.showAllGuests();
            break;

        case 5:
            hotel.createBooking();
            break;

        case 6:
            hotel.showAllBookings();
            break;

        case 7:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
