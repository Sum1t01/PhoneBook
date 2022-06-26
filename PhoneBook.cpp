#include <bits/stdc++.h>

using namespace std;

class contact
{
private:
    char country[20], number[20];

public:
    char first_name[30], last_name[30];

    void fill()
    {
        cout << "Enter First Name: ";
        cin >> first_name;
        cout << "Enter Last Name: ";
        cin >> last_name;
        cout << "Enter Country: ";
        cin >> country;
        cout << "Enter Number: ";
        cin >> number;
    }

    void update()
    {
        cout << "Enter Country: ";
        cin >> country;
        cout << "Enter Number: ";
        cin >> number;
    }

    void show()
    {
        cout << "Name:    " << first_name << " " << last_name << endl
             << "Country: " << country << endl
             << "Number:  " << number << endl
             << endl;
    }
};

static bool comp(const contact &a, const contact &b)
{
    if (strcmp(a.first_name, b.last_name) == 0)
    {
        if (strcmp(a.last_name, b.last_name) < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (strcmp(a.first_name, b.first_name) < 0)
    {
        return true;
    }
    return false;
}

void add_directory()
{
    contact a;
    a.fill();
    vector<contact> contact_sort;
    contact_sort.push_back(a);
    contact b;
    ifstream f("directory.dat", ios::binary | ios::in);
    while (f.read((char *)&b, sizeof(b)))
    {
        contact_sort.push_back(b);
    }

    sort(contact_sort.begin(), contact_sort.end(), comp);
    ofstream t("temp.dat", ios::binary | ios::out);
    for (auto &a : contact_sort)
    {
        t.write((char *)&a, sizeof(a));
    }
    f.close();
    t.close();
    remove("directory.dat");
    rename("temp.dat", "directory.dat");
    cout << "Contact Added Successfully!" << endl;
}

void delete_entry()
{
    cout << "Enter First Name: ";
    char m[30];
    cin >> m;
    contact a;
    ifstream f("directory.dat", ios::binary | ios::in);
    ofstream t("temp.dat", ios::binary | ios::out);
    while (f.read((char *)&a, sizeof(a)))
    {
        if (strcmp(m, a.first_name) == 0)
        {
            continue;
        }
        t.write((char *)&a, sizeof(a));
    }
    f.close();
    t.close();
    remove("directory.dat");
    rename("temp.dat", "directory.dat");
    cout << "Contact Deleted Successfully!" << endl;
}

void update()
{
    cout << "Enter First Name: ";
    char m[30];
    cin >> m;
    contact a;
    ifstream f("directory.dat", ios::binary | ios::in);
    ofstream t("temp.dat", ios::binary | ios::out);
    while (f.read((char *)&a, sizeof(a)))
    {
        if (strcmp(m, a.first_name) == 0)
        {
            a.update();
        }
        t.write((char *)&a, sizeof(a));
    }
    f.close();
    t.close();
    remove("directory.dat");
    rename("temp.dat", "directory.dat");
    cout << "Contact Updated Successfully!" << endl;
}

void search()
{
    cout << "Enter First Name: ";
    char m[30];
    cin >> m;
    contact a;
    bool flag = false;
    ifstream f("directory.dat", ios::binary | ios::in);
    while (f.read((char *)&a, sizeof(a)))
    {
        if (strcmp(m, a.first_name) == 0)
        {
            flag = true;
            a.show();
        }
    }
    f.close();
    if (!flag)
    {
        cout << "Contact Not Found!" << endl;
    }
}

void show_directory()
{
    contact a;
    ifstream f("directory.dat", ios::binary | ios::in);
    cout << "## Contact List ##" << endl;
    while (f.read((char *)&a, sizeof(a)))
    {
        a.show();
    }
    f.close();
}