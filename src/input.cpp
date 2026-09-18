#include <iostream>
#include <string>

using namespace std;

// Contact Information Store
struct contactInfo {
    string name;
    string phone;
    string email;
};

// Input Contact Info Function
void inputContact(contactInfo &contact) {

    cout << "===== ENTER CONTACT INFORMTAION =====" << endl;

    cout << "Enter name: ";
    getline(cin, contact.name);

    cout << "Enter phone number: ";
    getline(cin, contact.phone);

    cout << "Enter email address: ";
    getline(cin, contact.email);
}
