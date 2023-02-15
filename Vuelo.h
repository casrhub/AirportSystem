#pragma once 
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;


class Vuelo{




public:
// variables cálculo de duración de vuelo
chrono::time_point<chrono::system_clock> departureTime;
chrono::time_point<chrono::system_clock> arrivalTime;

int price; 
string airplaneModel;
int flightNumber;
chrono::duration<double> duration;
string availability;
int seats;
string date;
string origin;
string destination;
int totalKm;

//constructor
Vuelo(){}
Vuelo(int price, string airplaneModel, int flightNumber, string availability, string date, string origin,string destination, int seats, int totalKm): departureTime(departureTime), arrivalTime(arrivalTime),price(price), airplaneModel(airplaneModel), flightNumber(flightNumber),duration(duration), availability(availability), seats(seats),date(date), origin(origin), destination(destination), totalKm(totalKm){}

//getters
int getTotalKm() const{
    return totalKm;
  }


chrono::time_point<chrono::system_clock> getArrivalTime() const{
    return arrivalTime;
  }

int getPrice() const{
    return price;
  }

string getAirplaneModel() const{
    return airplaneModel;
  }

int getFlightNumber() const{
    return flightNumber;
  }

chrono::duration<double> getDuration() const{
    return duration;
  }

string getAvailability() const{
    return availability;
  }

int getSeats() const{
return seats;
}

string getDate() const{
return date;
}

string getOrigin() const{
return origin;
}

string getDestination() const{
return destination;
}

//setters
void setTotalKm(int totalKm){
    this->totalKm = totalKm;
}
void setDepartureTime(chrono::time_point<chrono::system_clock> departureTime){
    this->departureTime = departureTime;
}

void setArrivalTime(chrono::time_point<chrono::system_clock> arrivalTime){
    this->arrivalTime = arrivalTime;
}

void setPrice(int price){
    this->price = price;
}

void setAirplaneModel(string airplaneModel){
    this->airplaneModel = airplaneModel;
}

void setFlightNumber(int flightNumber){
    this->flightNumber = flightNumber;
}

void setDuration(chrono::duration<double> duration){
    this->duration = duration;
}

void setAvailability(string availability){
    this->availability = availability;
}

void setSeats(int seats){
    this->seats = seats;
}

void setDate(string date){
    this->date = date;
}

void setOrigin(string origin){
    this->origin = origin;
}

void setDestination(string destination){
    this->destination = destination;
}

//destructor 
~Vuelo(){}


};

