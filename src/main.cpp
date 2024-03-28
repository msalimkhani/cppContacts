#include "../libs/lib.h"
#include "../libs/contacts.h"
#include "../libs/console.h"
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