#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Book structure
struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
};

// Borrower structure
struct Borrower {
    string name;
    vector<string> borrowedBooks; // Stores ISBNs of borrowed books
};

// Global variables
vector<Book> books;
vector<Borrower> borrowers;

// Function to display the menu
void displayMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book\n";
    cout << "3. Checkout Book\n";
    cout << "4. Return Book\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a book to the database
void addBook() {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter ISBN: ";
    getline(cin, newBook.ISBN);
    newBook.isAvailable = true;

    books.push_back(newBook);
    cout << "Book added successfully!\n";
}

// Function to search for a book
void searchBook() {
    string query;
    cout << "Enter book title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);

    bool found = false;
    for (const auto& book : books) {
        if (book.title == query || book.author == query || book.ISBN == query) {
            cout << "Book Found: \n";
            cout << "Title: " << book.title << "\nAuthor: " << book.author
                 << "\nISBN: " << book.ISBN << "\nStatus: "
                 << (book.isAvailable ? "Available" : "Checked Out") << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No book found with the given query.\n";
    }
}

// Function to checkout a book
void checkoutBook() {
    string ISBN, borrowerName;
    cout << "Enter ISBN of the book to checkout: ";
    cin >> ISBN;

    for (auto& book : books) {
        if (book.ISBN == ISBN) {
            if (!book.isAvailable) {
                cout << "Book is already checked out.\n";
                return;
            }
            cout << "Enter borrower name: ";
            cin.ignore();
            getline(cin, borrowerName);

            // Update book status
            book.isAvailable = false;

            // Add borrower
            for (auto& borrower : borrowers) {
                if (borrower.name == borrowerName) {
                    borrower.borrowedBooks.push_back(ISBN);
                    cout << "Book checked out successfully.\n";
                    return;
                }
            }

            // New borrower
            Borrower newBorrower = {borrowerName, {ISBN}};
            borrowers.push_back(newBorrower);
            cout << "Book checked out successfully.\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

// Function to return a book
void returnBook() {
    string ISBN, borrowerName;
    cout << "Enter ISBN of the book to return: ";
    cin >> ISBN;
    cout << "Enter borrower name: ";
    cin.ignore();
    getline(cin, borrowerName);

    for (auto& borrower : borrowers) {
        if (borrower.name == borrowerName) {
            auto it = find(borrower.borrowedBooks.begin(), borrower.borrowedBooks.end(), ISBN);
            if (it != borrower.borrowedBooks.end()) {
                borrower.borrowedBooks.erase(it);

                // Update book status
                for (auto& book : books) {
                    if (book.ISBN == ISBN) {
                        book.isAvailable = true;
                        cout << "Book returned successfully.\n";
                        return;
                    }
                }
            }
        }
    }

    cout << "Return failed. Check ISBN or borrower name.\n";
}

// Main function
int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "Exiting Library Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

