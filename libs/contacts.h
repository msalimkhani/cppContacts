#include "../libs/shared.h"

#ifndef CONTACTS_H
#define CONTACTS_H
typedef struct _contacts
{
    string f_name;
    string l_name;
    int phone = 0;
} Contact;
Contact *l_Contacts = NULL;
#endif