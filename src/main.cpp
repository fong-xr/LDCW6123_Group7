#include <iostream>
#include <string>

using namespace std;

void processURL();
bool validateURL(string url);

int main ()
{
    int choice;

    cout << "QR Code Content Assistant\n";
    cout << "1. URL\n";
    cout << "Enter your choice: ";

    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        processURL();
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    return 0;
}