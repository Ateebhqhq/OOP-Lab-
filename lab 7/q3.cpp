#include <iostream>
#include <string>

using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    string price;
    string date;
    string destination;

public:
    Ticket(int id, string name, string p, string d, string dest) : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << endl;
    }

    virtual void cancel() {
        cout << "Ticket canceled for " << passengerName << endl;
    }

    virtual void displayTicketInfo() const {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger: " << passengerName << endl;
        cout << "Price: " << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket {
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, string p, string d, string dest, string airline, string flight, string seat): Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, string p, string d, string dest, string train, string coach, string time)
        : Ticket(id, name, p, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}

    void reserve() override {
        cout << "Train ticket reserved with auto-assigned seat" << endl;
    }

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Train Number: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure Time: " << departureTime << endl;
    }
};

class BusTicket : public Ticket {
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, string p, string d, string dest, string company, int seat) : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        cout << "Bus ticket canceled with last-minute refund option " << endl;
    }

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Bus Company: " << busCompany << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, string p, string d, string dest, string artist, string v, string seat) : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(seat) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket ft(1, "Alice", "$500", "2025-05-10", "New York", "Delta Airlines", "DL123", "Business");
    TrainTicket tt(20, "Bob", "$100", "2025-06-15", "Los Angeles", "Amtrak 456", "Sleeper", "09:00 AM");
    BusTicket bt(4, "Charlie", "$50", "2025-07-20", "Chicago", "Greyhound", 12);
    ConcertTicket ct(9, "David", "$200", "2025-08-30", "Las Vegas", "Taylor Swift", "Stadium X", "VIP");

    ft.displayTicketInfo();
    cout << endl;
    tt.displayTicketInfo();
    cout << endl;
    bt.displayTicketInfo();
    cout << endl;
    ct.displayTicketInfo();
    cout << endl;

    return 0;
}