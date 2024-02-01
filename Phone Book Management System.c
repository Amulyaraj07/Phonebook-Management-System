#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to hold contact information
struct Contact {
    char name[50];
    char phone[20];
};

//Function to add a new contact
void add_contact() {
    struct Contact contact;
    FILE *file = fopen("phonebook.txt", "a");

    //Get contact information from user
    printf("\nEnter name: ");
    scanf("%s", contact.name);
    printf("Enter phone number: ");
    scanf("%s", contact.phone);

    //Write contact information to file
    fprintf(file, "%s %s\n", contact.name, contact.phone);
    fclose(file);
    printf("\nContact added successfully!\n");
}

//Function to view all contacts
void view_contacts() {
    struct Contact contact;
    FILE *file = fopen("phonebook.txt", "r");
    printf("\nList of contacts:\n");
    while (fscanf(file, "%s %s", contact.name, contact.phone) != EOF) {
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }
    fclose(file);
}

//Function to edit a contact
void edit_contact() {
    struct Contact contact;
    FILE *file = fopen("phonebook.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char name[50], new_phone[20];
    int found = 0;

    printf("\nEnter the name of the contact you want to edit: ");
    scanf("%s", name);

    while (fscanf(file, "%s %s", contact.name, contact.phone) != EOF) {
        if (strcmp(name, contact.name) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", new_phone);
            fprintf(temp, "%s %s\n", contact.name, new_phone);
            found = 1;
        } else {
            fprintf(temp, "%s %s\n", contact.name, contact.phone);
        }
    }
    fclose(file);
    fclose(temp);

    //Replace the original file with the updated file
    remove("phonebook.txt");
    rename("temp.txt", "phonebook.txt");

    if (found) {
        printf("\nContact updated successfully!\n");
    } else {
        printf("\nContact not found!\n");
    }
}

//Function to search for a contact
void search_contact() {
    struct Contact contact;
    FILE *file = fopen("phonebook.txt", "r");
    char name[50];
    int found = 0;

    printf("\nEnter the name of the contact you want to search for: ");
    scanf("%s", name);

    while (fscanf(file, "%s %s", contact.name, contact.phone) != EOF) {
        if (strcmp(name, contact.name) == 0) {
            printf("\nName: %s, Phone: %s\n", contact.name, contact.phone);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("\nContact not found!\n");
    }
}

//Function to delete a contact
void delete_contact() {
    struct Contact contact;
    FILE *file = fopen("phonebook.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char name[50];
    int found = 0;

    printf("\nEnter the name of the contact you want to delete: ");
    scanf("%s", name);
    while (fscanf(file, "%s %s", contact.name, contact.phone) != EOF) {
    if (strcmp(name, contact.name) == 0) {
        found = 1;
    } else {
        fprintf(temp, "%s %s\n", contact.name, contact.phone);
    }
}
fclose(file);
fclose(temp);

//Replace the original file with the updated file
remove("phonebook.txt");
rename("temp.txt", "phonebook.txt");

if (found) {
    printf("\nContact deleted successfully!\n");
} else {
    printf("\nContact not found!\n");
}
}

//Main function to display menu and handle user input
int main() {
int choice;
while (1) {
    printf("\nPhonebook Management System\n");
    printf("1. Add contact\n");
    printf("2. View contacts\n");
    printf("3. Edit contact\n");
    printf("4. Search contact\n");
    printf("5. Delete contact\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            view_contacts();
            break;
        case 3:
            edit_contact();
            break;
        case 4:
            search_contact();
            break;
        case 5:
            delete_contact();
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid choice!\n");
            break;
    }
}

return 0;
}
