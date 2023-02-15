#pragma once
#include <iostream>
#include "Vuelo.h"
#include "General.h"
#include "Reservation.h"

using namespace std::chrono;


// Inicio clase

class Cliente {
private:
  bool isLoggedIn;
  int totalKm;
  


public:


int id;
string name;
int phone;
string email;
bool hasCoupon;
  // constructor
  Cliente() {}
  Cliente(int id, string name, int phone, string email)
      : id(id), name(name), phone(phone), email(email), isLoggedIn(false) {}
      



  // getters
  int getID()const {
    return id;
  }
  string getName() const { return name; }
  int getPhone() const { return phone; }
  string getEmail() const { return email; }

  // setters
  void setID(int id){this->id=id;}
  void setName(string name) { this->name = name; }
  void setPhone(int phone) { this->phone = phone; }
  void setEmail(string email) { this->email = email; }

  // login y logout de cliente, futuro

  bool login(string email, int phone) {
    if (this->email == email && this->phone == phone) {
      isLoggedIn = true;
      cout << "Login successful" << endl;
      return true;
    } else {
      cout << "Incorrect email or phone number, please try again." << endl;
      return false;
    }
  }

  void logout() {
    isLoggedIn = false;
    cout << "Logout successful" << endl;
  }




//menu para usuario regsitrado
void displayClientMenu() {
    int menuSelection = 0;
    while (menuSelection != 4) {
      cout << "1. Serach for a flight" << endl;
      cout << "2. Make Flight Reservation" << endl;
      cout << "3. Cancel Reservation" << endl;
      cout << "Enter your selection: ";
      cin >> menuSelection;

      //If another value is typed
      if (cin.fail()) {
        cout << "Invalid input, please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }

      switch (menuSelection) {

      case 1:
        searchFlights("origin");
        break;

      case 2:
        makeReservation();
        break;

      case 3:
        cancelReservation();
        
        break;
      }
    }
  }

//searchFlight
vector<Vuelo> flights = {
    Vuelo(200, "Boeing 123", 1, "Available", "2023-07-11", "New York", "London", 150, 50000),
    Vuelo(250, "Air A380", 2, "Available", "2023-03-21", "London", "Paris", 200, 5000),
    Vuelo(150, "Boeing 777", 3, "Available", "2023-05-01", "Paris", "New York", 100, 4000),
};

void searchFlights(string origin) {
    cout << "Enter origin city: ";
    cin >> origin;

    cout << "\nAvailable flights:\n";
    bool found = false;
    for (int i = 0; i < flights.size(); i++) {
        Vuelo v = flights[i];
        if (v.getOrigin() == origin) {
            found = true;
            cout << "Flight number: " << v.getFlightNumber() << endl;
            cout << "Destination: " << v.getDestination() << endl;
            cout << "Date: " << v.getDate() << endl;
            cout << "Distance: " <<v.getTotalKm() << "Km." << endl;
            cout << "Availability: " << v.getAvailability() << endl;
            cout << "Price: $" << v.getPrice() << endl;
            cout << "Seats: " << v.getSeats() << endl;
            cout << "-----------------------------------\n";
           
        }
    }
    if (!found) {
        cout << "No flights found with the specified origin.\n";
    }
}

//makeReservation
void makeReservation() {
    int flightNumber, numPassengers;
    cout << "Enter flight number: ";
    cin >> flightNumber;
    cout << "Enter number of passengers: ";
    cin >> numPassengers;

    // Find the flight
    int flightIndex = -1;
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].getFlightNumber() == flightNumber) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        cout << "Flight not found." << endl;
        return;
    }

    // Reserve seats
    Vuelo flight = flights[flightIndex];
    if (numPassengers > flight.getSeats()) {
        cout << "Not enough seats available." << endl;
        return;
    }

    flight.setSeats(flight.getSeats() - numPassengers);
    flights[flightIndex] = flight;

    // Ask for names of each passenger
    vector<string> passengerNames;
    for (int i = 0; i < numPassengers; i++) {
        string passengerName;
        cout << "Enter name of passenger " << i + 1 << ": ";
        cin >> passengerName;
        passengerNames.push_back(passengerName);
        cout << "Reservation made successfully for passenger: " << passengerName << endl;
    }
    cout << "Number of seats assigned: " << numPassengers << endl;

    // Calculate and display the total price for the total number of passengers
    int seatPrice = flight.getPrice();
    int totalPrice = numPassengers * seatPrice;
    cout << "Total price for " << numPassengers << " passengers: $" << totalPrice << endl;
  

    cout << "-----------------------------------\n";    
    cout << "Details of the reservation: " << endl;
    cout << "Flight number: " << flight.getFlightNumber() << endl;
    cout << "Origin: " << flight.getOrigin() <<endl;
    cout << "Destination: " << flight.getDestination() << endl;
    cout << "Distance: " << flight.getTotalKm() <<endl;
    cout << "Number of passengers: " << numPassengers << endl;
    cout << "Passenger names: ";
    for (int i = 0; i < passengerNames.size(); i++) {
        cout << passengerNames[i];
        if (i < passengerNames.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Total price: $" << totalPrice << endl;
    cout << "-----------------------------------\n"; 
    cout << "Do you want to proceed and pay?" << endl;
  
      //payment code here
  int option;
cout << "Enter 1 to pay or 2 to cancel: ";
cin >> option;
if (option == 1) {
    if (flight.getTotalKm() >= 50000) {
        int discount = totalPrice * 0.4;
        totalPrice -= discount;
        cout << "Congratulations you have more than 50,000km you now have a disccount of: $" << discount << endl;
        cout << "Amount to pay after discount: $" << totalPrice << endl;
    }
  //.txt
    cout << "Payment received. Thank you for booking with us." << endl;
  ofstream file("PaymentHistory.txt", ios::app);
    file << "Payment made for the reservation of flight with flight number: " << flight.getFlightNumber() 
         << " for the amount of $" << totalPrice << endl;
    file.close();
} else if (option == 2) {
    cout << "Reservation cancelled." << endl;
    return;
} else {
    cout << "Invalid option. Reservation cancelled." << endl;
    return;
}
}


//cancel reservation
vector<int> reservations = {1, 2, 3};
void cancelReservation() {
    int flightNumber;
    cout << "Enter the flight number to cancel the reservation: ";
    cin >> flightNumber;
    
    bool reservationFound = false;
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i] == flightNumber) {
            reservations.erase(reservations.begin() + i);
            cout << "Reservation for flight " << flightNumber << " has been cancelled." << endl;
            reservationFound = true;
            break;
        }
    }

    if (!reservationFound) {
        cout << "No reservation found for flight " << flightNumber << "." << endl;
    }
}




//destructor
~Cliente(){}


};//Final clase 
