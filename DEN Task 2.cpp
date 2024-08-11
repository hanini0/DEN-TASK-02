#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;

    Contact(string n, string pn) {
        name = n;
        phoneNumber = pn;
    }
};

vector<Contact> contactList;

void addContact() {
    string name, phoneNumber;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    Contact newContact(name, phoneNumber);
    contactList.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts() {
    if (contactList.empty()) {
        cout << "No contacts found." << endl;
    } else {
        cout << "Contact List:" << endl;
        for (int i = 0; i < contactList.size(); i++) {
            cout << "Name: " << contactList[i].name << ", Phone Number: " << contactList[i].phoneNumber << endl;
        }
    }
}

void deleteContact() {
    string name;
    cout << "Enter name of contact to delete: ";
    cin >> name;
    for (int i = 0; i < contactList.size(); i++) {
        if (contactList[i].name == name) {
            contactList.erase(contactList.begin() + i);
            cout << "Contact deleted successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found." << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "Contact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
