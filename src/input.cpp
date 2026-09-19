#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// ========== URL Validation ==========
bool validateURL(string url)
{
    if (url.empty())
    {
        return false;
    }

    if (url.find("http://") == 0)
    {
        return true;
    }

    if (url.find("https://") == 0)
    {
        return true;
    }

    return false;
}

// ========== URL Processing ==========
void processURL()
{
    string url;

    cout << "\nEnter URL: ";
    getline(cin, url);

    if (validateURL(url))
    {
        cout << "Valid URL.\n";
        cout << "Content: " << url << endl;
    }
    else
    {
        cout << "Invalid URL.\n";
        cout << "URL must start with 'http://' or 'https://'.\n";
    }
}

// ========== Text Validation ==========
bool validateText(string text)
{
    if (text.empty())
    {
        return false;
    }

    for (char character : text)
    {
        if (character != ' ' && character != '\t' && character != '\n')
        {
            return true;
        }
    }

    return false;
}

// ========== Text Processing ==========
void processText()
{
    string text;

    cout << "\nEnter text: ";
    getline(cin, text);

    if (validateText(text))
    {
        cout << "Valid text.\n";
        cout << "Content: " << text << endl;
    }
    else
    {
        cout << "Invalid text.\n";
        cout << "Text cannot be empty.\n";
    }
}

// ========== Contact Processing ==========
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

// Display Contact Info
void displayContact(contactInfo contact) {
    cout << "\n===== CONTACT INFORMATION =====" << endl;
    cout << "Name: " << contact.name << endl;
    cout << "Phone Number: " << contact.phone << endl;
    cout << "Email: " << contact.email << endl;
