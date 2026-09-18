#include <iostream>
#include <string>

using namespace std;

// ========== Function Prototypes ==========
// URL functions
void processURL();
bool validateURL(string url);

// Text functions
void processText();
bool validateText(string text);

// ========== Main Function ==========
int main ()
{
    int choice;

    cout << "QR Code Content Assistant\n";
    cout << "1. URL\n";
    cout << "2. Text\n";

    cout << "Enter your choice: ";

    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        processURL();
    }
    else if (choice == 2)
    {
        processText();
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    return 0;
}