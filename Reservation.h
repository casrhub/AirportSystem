#pragma once
#include <iostream>
using namespace std;

class Reservation{


public: 

int reservationId;
int flightNumber;
Reservation(){}
Reservation(int reservationId, int flightNumber): reservationId(reservationId), flightNumber(flightNumber){}

int getReservationId() const{
    return reservationId;
  }

int getFlightNumber() const{
    return flightNumber;
  }

void setFlightNumber(int flightNumber){
    this->flightNumber = flightNumber;
}

//destructor
~Reservation(){}

};

