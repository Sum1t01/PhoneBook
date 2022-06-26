#include <bits/stdc++.h>
#include "PhoneBook.cpp"
#include "country_code.cpp"

using namespace std;

int main()
{
    // remove("directory.dat");

    char y;
    do
    {
        cout << "************Digital PhoneBook************" << endl;
        cout << "Choose a task" << endl;
        cout << "1. Add Contact" << endl
             << "2. Delete Contact" << endl
             << "3. Update Contact" << endl
             << "4. Search Contact" << endl
             << "5. Display Contact" << endl
             << "6. Close" << endl;
        int i;
        cin >> i;
        system("cls");
        switch (i)
        {
        case 1:
            add_directory();
            break;
        case 2:
            delete_entry();
            break;
        case 3:
            update();
            break;
        case 4:
            search();
            break;
        case 5:
            show_directory();
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "Invalid Operation" << endl;
            break;
        }
        cout << "Return to main menu (y/n)?" << endl;
        cin >> y;
        system("cls");
    } while (y == 'y' || y=='Y');
    return 0;
}