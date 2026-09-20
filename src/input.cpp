#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void generateQR(string content);

// ========== Clear Screen ==========
void clearScreen()
{
    system("cls");
}

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

    do
    {
        cout << "\nEnter URL: ";
        getline(cin, url);

        if (!validateURL(url))
        {
            cout << "\n*********************** Error ************************\n";
            cout << "\nInvalid URL.\n";
            cout << "URL must start with 'http://' or 'https://'.\n";
            cout << "\n------------------------------------------------------\n";
        }

    } while (!validateURL(url));

    cout << "\nValid URL.\n";
    cout << "Content: " << url << endl;
    generateQR(url);

    cout << "\nPress Enter to continue...";
    cin.get();

    clearScreen();
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

    do
    {
        cout << "\nEnter text: ";
        getline(cin, text);

        if (!validateText(text))
        {
            cout << "\n*********************** Error ************************\n";
            cout << "\nInvalid text.\n";
            cout << "Text cannot be empty.\n";
            cout << "\n------------------------------------------------------\n";
        }

    } while (!validateText(text));

    cout << "\nValid text.\n";
    cout << "Content: " << text << endl;
    generateQR(text);

    cout << "\nPress Enter to continue...";
    cin.get();

    clearScreen();
}

// ========== Contact Processing ==========
// Contact Information Store
struct contactInfo{
    string name;
    string phone;
    string email;
};

// Validate Contact Input
bool validateContact(contactInfo *contact){

    bool valid = true;
    bool firstError = true;

    // Empty field check
    if (contact->name.empty() || contact->phone.empty() || contact->email.empty()) 
    {
        if (firstError)
        {
            cout << "\n*********************** Error ************************\n\n";
            firstError = false;
        }

        cout << "All information are required." << endl;
        valid = false;
    }

    // Check name
    if (!contact->name.empty())
    {
        bool hasLetter = false;

        for (char c : contact->name)
        {
            if (isalpha(c))
            {
                hasLetter = true;
            }
            else if (!isspace(c))
            {
                if (firstError)
                {
                    cout << "\n*********************** Error ************************\n\n";
                    firstError = false;
                }

                cout << "Name only contains letters and spaces." << endl;
                valid = false;
                break;
            }
        }

        // Check if name contains at least one letter
        if (hasLetter == false)
        {
            if (firstError)
            {
                cout << "\n*********************** Error ************************\n\n";
                firstError = false;
            }

            cout << "Name must contain at least one letter." << endl;
            valid = false;
        }
    }

    // Check phone number
    if (!contact->phone.empty())
    {
        for (char c : contact->phone)
        {
            if (!isdigit(c))
            {
                if (firstError)
                {
                    cout << "\n*********************** Error ************************\n\n";
                    firstError = false;
                }

                cout << "Phone number only contains digits." << endl;
                valid = false;
                break;
            }
        }
    }

    // Check email
    if (!contact->email.empty())
    {
        if (contact->email.find('@') == string::npos || contact->email.find(".com") == string::npos)
        {
            if (firstError)
            {
                cout << "\n*********************** Error ************************\n\n";
                firstError = false;
            }

            cout << "Invalid email address." << endl;
            valid = false;
        }
    }

    return valid;
}

// Display Contact Info
void displayContact(contactInfo *contact){
    cout << "\n---------- CONTACT INFORMATION -----------" << endl;
    cout << "Name: " << contact->name << endl;
    cout << "Phone Number: " << contact->phone << endl;
    cout << "Email: " << contact->email << endl;
}

// Input Contact Info Function
void processContact()
{
    contactInfo contact;
    bool valid;

    do
    {
        cout << "\n-------------- ENTER CONTACT INFORMATION -------------\n" << endl;

        cout << "Enter name          : ";
        getline(cin, contact.name);

        cout << "Enter phone number  : ";
        getline(cin, contact.phone);

        cout << "Enter email address : ";
        getline(cin, contact.email);

        valid = validateContact(&contact);

        if (!valid)
        {
            cout << "\nInvalid contact information." << endl;
            cout << "Please enter the information again." << endl;
        }

    } while (!valid);

    cout << "\nValid contact information." << endl;
    displayContact(&contact);
    generateQR(contact.name + "|" + contact.phone + "|" + contact.email);

    cout << "\nPress Enter to continue...";
    cin.get();

    clearScreen();
}