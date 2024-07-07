#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void registerUser() {
    fstream userFile;
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    userFile.open("users.txt", ios::app);
    userFile << username << " " << password << endl;
    userFile.close();
    cout << "User registered successfully.\n";
}

bool login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream userFile("users.txt");
    string fileUsername, filePassword;

    while (userFile >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            userFile.close();
            return true;
        }
    }
    userFile.close();
    return false;
}

class Library {
public:
    int sn;
    char title[100];
    char author_name[50];

    Library() {
        sn = 0;
        strcpy(title, "");
        strcpy(author_name, "");
    }
};

void addBook(Library lib[], int &count) {
    if (count >= 100) {
        cout << "Library is full. Cannot add more books.\n";
        return;
    }
    cout << "Enter serial number: ";
    cin >> lib[count].sn;


    cout << "Enter book title: ";
    cin.getline(lib[count].title, 100);
    cout << "Enter author name: ";
    cin.getline(lib[count].author_name, 50);
    count++;
    cout << "Book added successfully.\n";
}

void viewBooks(Library lib[], int count) {
    if (count == 0) {
        cout << "No books available.\n";
        return;
    }
    cout << "Book List:\n";
    for (int i = 0; i < count; i++) {
        cout << "Serial Number: " << lib[i].sn << ", Title: " << lib[i].title
             << ", Author: " << lib[i].author_name << "\n";
    }
}

void returnBook(Library lib[], int count) {
    int sn;
    cout << "Enter serial number of the book to return: ";
    cin >> sn;
    for (int i = 0; i < count; i++) {
        if (lib[i].sn == sn) {
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not exist.\n";
}

void deleteBook(Library lib[], int &count) {
    int sn;
    cout << "Enter serial number of the book to delete: ";
    cin >> sn;
    for (int i = 0; i < count; i++) {
        if (lib[i].sn == sn) {
            for (int j = i; j < count - 1; j++) {
                lib[j] = lib[j + 1];
            }
            count--;
            cout << "Book deleted successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

int main() {
    Library lib[100];
    int choice = 0;
    int count = 0;

    cout << "Library Management System\n";
    cout << "1. Register\n";
    cout << "2. login\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        if (!login()) {
            cout << "Invalid login credentials.\n";
            return 0;
        }
    } else if (choice == 2) {
        registerUser();
        return 0;
    } else {
        cout << "Invalid choice. Exiting...\n";
        return 0;
    }

    while (choice != 5) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book " << endl;
        cout << "2. View Books" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Delete Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(lib, count);
                break;
            case 2:
                viewBooks(lib, count);
                break;
            case 3:
                returnBook(lib, count);
                break;
            case 4:
                deleteBook(lib, count);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
