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

// Contact functions
void processContact();

// ========== Main Function ==========
int main ()
{
    int choice;

    do
    {
        cout << "\nQR Code Content Assistant\n";
        cout << "1. URL\n";
        cout << "2. Text\n";
        cout << "3. Contact Information\n";
        cout << "4. Exit\n";

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
        else if (choice == 3)
        {
            processContact();
        }
        else if (choice == 4)
        {
            cout << "Exiting the program.\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}