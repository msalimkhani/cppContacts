#include "../libs/lib.h"

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