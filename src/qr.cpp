#include <iostream>
#include <string>

using namespace std;

// QR Pattern Generator
void generateQR(string content){

    cout << "\n------------ QR Code Pattern -------------\n" << endl;

    // Size of the QR code pattern (21x21)
    int size = 21; 

    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            
            // Generate fixed finder-like patterns
            bool black = false;

            // Top-left pattern
            if (row < 7 && col < 7){
                if (row == 0 || row == 6 || col == 0 || col == 6 || (row >= 2 && row <= 4 && col >= 2 && col <= 4))
                {
                    black = true;
                }
            }

            // Top-right pattern
            else if (row < 7 && col >= size - 7){
                int c = col - (size - 7);

                if (row == 0 || row == 6 || c == 0 || c == 6 || (row >= 2 && row <= 4 && c >= 2 && c <= 4))
                {
                    black = true;
                }
            }

            // Bottom-left pattern
            else if (row >= size - 7 && col < 7){
                int r = row - (size - 7);

                if (r == 0 || r == 6 || col == 0 || col == 6 || (r >= 2 && r <= 4 && col >= 2 && col <= 4))
                {
                    black = true;
                }
            }

            // Generate simple data pattern
            else{
                if (!content.empty())
                {
                    int index = (row * size + col) % content.length();

                    if ((content[index] + row + col) % 2 == 0)
                    {
                        black = true;
                    }
                }
            }

            if (black)
            {
                cout << "##";
            }
            else
            {
                cout << "..";
            }
        }

        cout << endl;
    }

    cout << "\nNote: This is a simplified QR-like pattern." << endl;
    cout << "It is NOT a real scannable QR code." << endl;
    cout << "-------------------------------------------" << endl;
}