#include <iostream>
#include <string>

using namespace std;

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
    }
}
