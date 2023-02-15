#pragma once
#include <iostream>
#include <map>
#include "General.h"
#include "Cliente.h"
#include "Vuelo.h"
#include "Reservation.h"
using namespace std;

int main() {
  int selection = 0;
  General general;
  

  //Menú principal  
  while (selection != 4) {
    cout << "1. Register a Client" << endl;
    cout << "2. Login as a Client" << endl;
    cout << "3. Display Registered Clients" << endl;
    cout << "4. Remove a Client" << endl;
    cout << "Enter your selection: ";
    cin >> selection;

    switch (selection) {
    case 1:
      general.registerClient();
      general.saveClients();
      break;
    case 2:
      general.loginClient();
      general.saveClients();
      break;
    case 3:
      general.displayClients();
      general.saveClients();
      break;
    case 4:
      general.removeClient();
      general.saveClients();
      break;
    }
  }

  return 0;
}



