#include <iostream>
using namespace std;

class book {
private:
    string title;
    string name;
    string author;
    string genre;

public:
    void add_book_details() {
        cout << "ENTER THE FOLLOWING DETAILS OF THE BOOK:" << endl;
        cout << "TITLE/SUBJECT: ";
        cin >> title;
        cout << "AUTHOR: ";
        cin >> author;
        cout << "GENRE: ";
        cin >> genre;
        cout << "BOOK NAME: ";
        cin >> name;
    }

    void display_book_details() {
        cout << "BOOK DETAILS:" << endl;
        cout << "TITLE/SUBJECT: " << title << endl;
        cout << "AUTHOR: " << author << endl;
        cout << "GENRE: " << genre << endl;
        cout << "BOOK NAME: " << name << endl;
    }
};

class library {
private:
    int current_books;
    int user_input;
    book* books;

public:
    library() {
        current_books = 10; // Initial number of books
        cout << "WELCOME TO THE LIBRARY MANAGEMENT PORTAL" << endl;
        cout << "NUMBER OF BOOKS IN THE LIBRARY: " << current_books << endl;
        cout << "ENTER THE NUMBER OF BOOKS YOU WANT TO ADD TO THE LIBRARY: ";
        cin >> user_input;

        // Dynamically allocate memory for the array of books
        books = new book[user_input];
    }

    ~library() {
        // Deallocate memory for the array of books
        delete[] books;
    }

    void add_books() {
        for (int i = 0; i < user_input; ++i) {
            cout << "Adding Book " << i + 1 << ":" << endl;
            books[i].add_book_details();
        }
    }

    void display_books() {
        for (int i = 0; i < user_input; ++i) {
            cout << "Displaying Book " << i + 1 << " Details:" << endl;
            books[i].display_book_details();
        }
    }
};

int main() {
    int choice;
    do {
        library obj;
        obj.add_books();
        obj.display_books();

        cout << "DO YOU WANT TO ADD MORE BOOKS? (1 for Yes, 0 for No): ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}
