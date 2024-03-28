#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#define size 20
using namespace std;

struct tell
{
    string f_name;
    string l_name;
    int phone = 0;
} Contacts[size];

void delete_contact()
{
    system("cls");
    int temp, test = 1;
    cout << "Please enter the phone number: ";
    cin >> temp;
    for (int i = 0; i < size && test; i++)
    {
        if (Contacts[i].phone == temp)
        {
            test = 0;
            Contacts[i].phone = 0;
            cout << "Contact deleted." << endl;
        }
    }
    if (test == 1)
        cout << "Contact not found." << endl;
    system("pause");
}

void search_contact()
{
    system("cls");
    int temp, test = 1;
    cout << "Please enter the phone number: ";
    cin >> temp;
    for (int i = 0; i < size && test; i++)
    {
        if (Contacts[i].phone == temp)
        {
            test = 0;
            cout << left << setw(20) << Contacts[i].f_name << setw(20) << Contacts[i].l_name << setw(20) << Contacts[i].phone << endl;
        }
    }
    if (test == 1)
        cout << "Contact not found." << endl;
    system("pause");
}

int search_empty_slot()
{
    for (int i = 0; i < size; i++)
        if (Contacts[i].phone == 0)
            return i;

    return -1;
}

void show_contacts()
{
    system("cls");
    cout << left << setw(20) << "First Name" << setw(20) << "Last Name" << setw(20) << "Phone" << endl;
    cout << "**********" << endl;
    for (int i = 0; i < size; i++)
    {
        if (Contacts[i].phone != 0)
            cout << left << setw(20) << Contacts[i].f_name << setw(20) << Contacts[i].l_name << setw(20) << Contacts[i].phone << endl;
    }
    system("pause");
}

void add_contact(int i)
{
    system("cls");
    cin.ignore();
    cout << "Please enter the first name: ";
    getline(cin, Contacts[i].f_name);

    cout << "Please enter the last name: ";
    getline(cin, Contacts[i].l_name);

    cout << "Please enter the phone number: ";
    cin >> Contacts[i].phone;
}

void edit_contact()
{
    system("cls");
    int temp, test = 1;
    cout << "Please enter the phone number of the contact you want to edit: ";
    cin >> temp;
    for (int i = 0; i < size && test; i++)
    {
        if (Contacts[i].phone == temp)
        {
            test = 0;
            cout << "Contact found. Please update the information:" << endl;
            add_contact(i);
            cout << "Contact updated." << endl;
        }
    }
    if (test == 1)
        cout << "Contact not found." << endl;
    system("pause");
}

int menu()
{
    int choice;
    system("cls");
    cout << "1) Add Contact" << endl;
    cout << "2) Delete Contact" << endl;
    cout << "3) Show Contacts" << endl;
    cout << "4) Search Contact" << endl;
    cout << "5) Edit Contact" << endl;
    cout << "6) Exit" << endl;
    cout << "-------------------------" << endl;
    cout << "Please Select: ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice, empty_slot;
    while (true)
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            empty_slot = search_empty_slot();
            if (empty_slot == -1)
            {
                cout << "The storage is full." << endl;
                system("pause");
            }
            else
                add_contact(empty_slot);
            break;

        case 2:
            delete_contact();
            break;

        case 3:
            show_contacts();
            break;

        case 4:
            search_contact();
            break;

        case 5:
            edit_contact();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            break;
        }
    }

    return 0;
}