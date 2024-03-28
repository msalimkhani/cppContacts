#include "../libs/lib.h"
#include "../libs/contacts.h"



void delete_contact()
{
    system("cls");
    int temp, test = 1;
    cout << "Please enter the phone number: ";
    cin >> temp;
    for (int i = 0; i < SIZE && test; i++)
    {
        if (l_Contacts[i].phone == temp)
        {
            test = 0;
            l_Contacts[i].phone = 0;
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
    for (int i = 0; i < SIZE && test; i++)
    {
        if (l_Contacts[i].phone == temp)
        {
            test = 0;
            cout << left << setw(20) << l_Contacts[i].f_name << setw(20) << l_Contacts[i].l_name << setw(20) << l_Contacts[i].phone << endl;
        }
    }
    if (test == 1)
        cout << "Contact not found." << endl;
    system("pause");
}

int search_empty_slot()
{
    for (int i = 0; i < SIZE; i++)
        if (l_Contacts[i].phone == 0)
            return i;

    return -1;
}

void show_contacts()
{
    system("cls");
    cout << left << setw(20) << "First Name" << setw(20) << "Last Name" << setw(20) << "Phone" << endl;
    cout << "**********" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (l_Contacts[i].phone != 0)
            cout << left << setw(20) << l_Contacts[i].f_name << setw(20) << l_Contacts[i].l_name << setw(20) << l_Contacts[i].phone << endl;
    }
    system("pause");
}

void add_contact(int i)
{
    system("cls");
    cin.ignore();
    cout << "Please enter the first name: ";
    getline(cin, l_Contacts[i].f_name);

    cout << "Please enter the last name: ";
    getline(cin, l_Contacts[i].l_name);

    cout << "Please enter the phone number: ";
    cin >> l_Contacts[i].phone;
}

void edit_contact()
{
    system("cls");
    int temp, test = 1;
    cout << "Please enter the phone number of the contact you want to edit: ";
    cin >> temp;
    for (int i = 0; i < SIZE && test; i++)
    {
        if (l_Contacts[i].phone == temp)
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
