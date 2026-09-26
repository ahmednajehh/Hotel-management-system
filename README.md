# Hotel Management System 🏨

A simple console-based Hotel Management System built in **C++**, demonstrating core Object-Oriented Programming (OOP) principles.

## Features

- **Add Room** — record room number, base price, and type (Standard, Deluxe, or Suite)
- **Add Guest** — record ID, name, and phone number
- **Show All Rooms** — view every room, its type, price per night, and availability
- **Show All Guests** — view every registered guest
- **Create Booking** — link a guest to an available room for a number of nights, and mark the room as unavailable
- **Show All Bookings** — view every booking with guest, room, and total price details

## OOP Concepts Used

| Concept | How it's applied |
|---|---|
| **Encapsulation** | Data members (`roomNumber`, `basePrice`, `isAvailable`, etc.) are `protected`/`private`, accessed via getters/setters |
| **Abstraction** | `Room` is an abstract base class with pure virtual functions `getPricePerNight()` and `getType()` |
| **Inheritance** | `StandardRoom`, `DeluxeRoom`, and `SuiteRoom` all inherit from the base class `Room` |
| **Polymorphism** | Each derived room class overrides `getPricePerNight()` and `getType()` with its own pricing logic and label |

## Tech Stack

- **Language:** C++
- **Data Structure:** `std::vector` for dynamic storage of rooms, guests, and bookings
- **Interface:** Console-based menu system

## How to Run

1. Make sure you have a C++ compiler installed (e.g., g++, Code::Blocks, Visual Studio)
2. Compile the file:
   ```bash
   g++ hotel_system.cpp -o hotel_system
   ```
3. Run the executable:
   ```bash
   ./hotel_system
   ```
4. Follow the on-screen menu to add rooms, register guests, create bookings, and view records

## Menu Options

```
1. Add Room
2. Add Guest
3. Show All Rooms
4. Show All Guests
5. Create Booking
6. Show All Bookings
7. Exit
```

## Room Pricing Logic

Each room type applies a different multiplier to the base price entered when the room is added:

| Room Type | Price Per Night |
|---|---|
| Standard | `basePrice * 2.2` |
| Deluxe | `basePrice * 1.5` |
| Suite | `basePrice` |

## Possible Future Improvements

- Use `getline()` to support multi-word guest names
- Save/load data to a file so records persist between runs
- Add input validation (e.g., prevent duplicate room numbers, guest IDs, or booking IDs)
- Add check-in / check-out dates instead of a raw night count
- Add a `cancelBooking()` function that frees the room again
- Properly free allocated memory (rooms, guests, bookings) to avoid memory leaks
- Use a single `vector<Room*>` alongside smart pointers for safer memory management

## Author

Built as a practice project while learning C++ and Object-Oriented Programming.
