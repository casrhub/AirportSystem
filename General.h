#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "Cliente.h"
using namespace std;

class General {
 public:
  map<int, Cliente*> registeredClients;

  void registerClient() {
    int id;

    cout << "Enter Client ID: ";
    cin >> id;

    if (registeredClients.count(id)) {
      cout << "User with ID " << id << " is already registered." << endl;
      return;
    }

    Cliente *client = new Cliente();
    client->setID(id);

    cout << "Enter Client Name: ";
    cin >> client->name;

    cout << "Enter Email: ";
    cin >> client->email;

    cout << "Enter Phone Number: ";
    cin >> client->phone;

    registeredClients[id] = client;
    cout << "\nClient registered successfully" << endl;
  }

  void loginClient() {
    int id;

    cout << "Enter Client ID: ";
    cin >> id;

    if (!registeredClients.count(id)) {
      cout << "User with ID " << id << " is not registered." << endl;
      return;
      
    }

    Cliente *client = registeredClients[id];
    client->displayClientMenu();

    cout << "\nClient Information: " << endl;
    cout << "ID: " << client->getID() << endl;
    cout << "Name: " << client->getName() << endl;
    cout << "Email: " << client->getEmail() << endl;
    cout << "Telephone: " << client->getPhone() << endl;
  }

  void displayClients() {
    cout << "\nRegistered Clients: " << endl;
    for (const auto &client : registeredClients) {
      cout << "ID" << client.second->getID() << endl;
      cout << "Name: " << client.second->getName() << endl;
      cout << "Email: " << client.second->getEmail() << endl;
      cout << "Telephone: " << client.second->getPhone() << endl;
      cout << "____________________" << endl;
      }
    }

  void removeClient() {
  int id;
  cout << "Enter the client ID to remove: ";
  cin >> id;
  if (registeredClients.count(id)) {
    registeredClients.erase(id);
    cout << "Client removed successfully" << endl;
  } else {
    cout << "Client with ID " << id << " not found" << endl;
  }
}

void saveClients() {
      ofstream file("registeredClients.txt");
      for (auto const &client : registeredClients) {
        file << "ID: " << client.first << ", Name: " << client.second->getName() << endl;
      }
      file.close();
    }

//destructor
~General(){}

};
