#include <iostream>
#include <string>
#include <iomanip>
#if __has_include("<conio.h>")
#include <conio.h>
#endif
#define SIZE 20
/**
 * Error Codes:
*/
#define EXT_ERR_COLOR_INVALID 1

using namespace std;
typedef struct _contacts
{
    string f_name;
    string l_name;
    int phone = 0;
} Contact;
Contact *l_Contacts = NULL;
typedef enum {Default ,Black, Red, Green} Color;

void delete_contact();
void search_contact();
int search_empty_slot();
void show_contacts();
void add_contact(int i);
void edit_contact();
int menu();
void allocateContacts();
void freeContacts();
void printMessage(string msg, Color color, int newLine);
string parseColor(Color color);
int main()
{
    allocateContacts();
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
    freeContacts();
    return 0;
}

void allocateContacts()
{
    if (l_Contacts == NULL)
    {
        l_Contacts = (Contact *) malloc(sizeof(Contact) * SIZE);
    }
    
}
void freeContacts()
{
    free(l_Contacts);
}
void delete_contact()
{
    system("clear");
    int temp, test = 1;
    cout << "Please enter the phone number: ";
    cin >> temp;
    for (int i = 0; i < SIZE && test; i++)
    {
        if (l_Contacts[i].phone == temp)
        {
            test = 0;
            l_Contacts[i].phone = 0;
            printMessage("Contact deleted.", Green, 1);
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
    Contact contact;
    system("cls");
    cin.ignore();
    cout << "Please enter the first name: ";
    //scanf("%s", contact->f_name);
    getline(cin, contact.f_name);

    cout << "Please enter the last name: ";
    getline(cin, contact.l_name);

    cout << "Please enter the phone number: ";
    cin >> contact.phone;
    l_Contacts[i] = contact;
    //free(contact);
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
    system("clear");
    cout << endl;
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
string parseColor(Color color)
{
    switch (color)
    {
    case Default:
        return "[0m";
    case Black:
        return "[30m";
    case Red:
        return "[31m";
    case Green:
        return "[32m";
    default:
        fprintf(stderr, "Couldn't parse Color Code!\n");
        exit(EXT_ERR_COLOR_INVALID);
    }
}
void printMessage(string msg, Color color, int newLine)
{
    if(!color)
    {
        cerr << "\033" << parseColor(Red) << "error: printMessage: Except Color Code Arg.\033" << parseColor(Default) << endl;
    }
    if(newLine == 1)
    {
        cout << "\033" << parseColor(color) << msg << "\033" << parseColor(Default) << endl;
    }
    cout << "\033" << parseColor(color) << msg << "\033" << parseColor(Default);
}