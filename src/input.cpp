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

    do
    {
        cout << "\nEnter URL: ";
        getline(cin, url);

        if (!validateURL(url))
        {
            cout << "\nInvalid URL.\n";
            cout << "URL must start with 'http://' or 'https://'.\n";
        }

    } while (!validateURL(url));

    cout << "\nValid URL.\n";
    cout << "Content: " << url << endl;
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
            cout << "\nInvalid text.\n";
            cout << "Text cannot be empty.\n";
        }

    } while (!validateText(text));

    cout << "\nValid text.\n";
    cout << "Content: " << text << endl;
}

// ========== Contact Processing ==========
void processContact()
{
    cout << "\nContact Information Processing is not implemented yet.\n";
}