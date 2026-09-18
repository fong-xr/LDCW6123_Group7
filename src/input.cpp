#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Contact Information Store
struct contactInfo {
    string name;
    string phone;
    string email;
};

// Input Contact Info Function
void processContact(contactInfo &contact) {

    cout << "===== ENTER CONTACT INFORMTAION =====" << endl;

    cout << "Enter name: ";
    getline(cin, contact.name);

    cout << "Enter phone number: ";
    getline(cin, contact.phone);

    cout << "Enter email address: ";
    getline(cin, contact.email);
}

// Validate Contact Input
bool validateContact(contactInfo contact){

    // empty field check
    if (contact.name.empty() || contact.phone.empty() || contact.email.empty()) 
    {
        cout << "\nERROR: All information are required." << endl;
        return false;
    }

    // check name
    for (char c : contact.name)
    {
        if(!isalpha(c) && !isspace(c)){
            cout << "\nERROR: Name only contains letters and spaces." << endl;
            return false;
        }
    }

    // phone number
    for (char c : contact.phone)
    {
        if(!isdigit(c)){
            cout << "\nERROR: Phone number only contains digits." << endl;
            return false;
        }
    }

    // check email
    if (contact.email.find('@') == string::npos || contact.email.find(".com") == string::npos) 
    {
        cout << "\nERROR: Invalid email address." << endl;
        return false;
    }

    return true;
}