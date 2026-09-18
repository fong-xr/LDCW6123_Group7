#include <iostream>
#include <string>

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
void processContact()
{
    cout << "\nContact Information Processing is not implemented yet.\n";
}