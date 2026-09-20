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

// Clear Screen function
void clearScreen();

// ========== Main Function ==========
int main ()
{
    int choice;

    do
    {
        cout << "\n .▪        ⌈‾‾    ____        _____    .▫";
        cout << "\n                |  _  |     |  __  |             ▸";
        cout << "\n        ▪      |  | |  |   |  |__|  |      . .";
        cout << "\n     .        |  |   |  |  |       |";
        cout << "\n               |  |_|  |   |  ||  |    ▴";
        cout << "\n         .▫     |___ _|    |  | |  |           ▪";
        cout << "\n   ▴               |_|     |__|  |__|     .\n";
        cout << "\n                  Content Assistant    __⌋\n";
        cout << "======================================================";

        cout << "\n         ___           ___\n";
        cout << "        ( 1 ) URL     ( 2 ) Contact Information\n";
        cout << "         ‾‾‾           ‾‾‾\n";
        cout << "                ___            ___\n";
        cout << "               ( 3 ) Text     ( 4 ) Exit\n";
        cout << "                ‾‾‾            ‾‾‾\n";
        cout << "======================================================\n";

        cout << "               Enter your choice : ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\n !!! Invalid choice. Please enter 1, 2, 3, or 4. !!!\n";
            cout << "======================================================\n";

            continue;
        }

        cin.ignore(1000, '\n');

        cout << "======================================================\n";

        if (choice == 1)
        {
            processURL();
        }
        else if (choice == 2)
        {
            processContact();
        }
        else if (choice == 3)
        {
            processText();
        }
        else if (choice == 4)
        {
            cout << "\n                Exiting the program.\n";
            cout << "                ````````````````````\n";
        }
        else
        {
            cout << "\nInvalid choice. Please enter 1, 2, 3, or 4.\n";
        }

    } while (choice != 4);

    return 0;
}