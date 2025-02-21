#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string bookArray[10];      
    string takenBooks[10];  
    int bookCount;            
    int takenCount;         

public:
    Library() : bookCount(0), takenCount(0) {}

    void insertBook(string book) {
        for (int i = 0; i < bookCount; i++) {
            if (bookArray[i] == book) {
                cout << "Book \"" << book << "\" already exists.\n";
                return;
            }
        }
        if (bookCount < 10) {
            bookArray[bookCount++] = book;
            cout << "Inserted book: " << book << endl;
        } else {
            cout << "Library is full!\n";
        }
    }

    void takeBook(string book) {
        if (takenCount >= 10) {
            cout << "Cannot take more books!\n";
            return;
        }
        for (int i = 0; i < bookCount; i++) {
            if (bookArray[i] == book) {
                takenBooks[takenCount++] = book;
                for (int j = i; j < bookCount - 1; j++) {
                    bookArray[j] = bookArray[j + 1];
                }
                bookCount--;
                cout << "Taken book: " << book << endl;
                return;
            }
        }
        cout << "Book \"" << book << "\" not found.\n";
    }

    void giveBackBook(string book) {
        if (bookCount >= 10) {
            cout << "Library is full!\n";
            return;
        }
        for (int i = 0; i < takenCount; i++) {
            if (takenBooks[i] == book) {
                bookArray[bookCount++] = book;
                for (int j = i; j < takenCount - 1; j++) {
                    takenBooks[j] = takenBooks[j + 1];
                }
                takenCount--;
                cout << "Returned book: " << book << endl;
                return;
            }
        }
        cout << "Book \"" << book << "\" was not taken.\n";
    }

    void showBooks() {
        cout << "\nBooks in Library:\n";
        if (bookCount == 0) {
            cout << "No books available.\n";
        } else {
            for (int i = 0; i < bookCount; i++) {
                cout << "- " << bookArray[i] << endl;
            }
        }
    }

    void showTakenBooks() {
        cout << "\nTaken Books:\n";
        if (takenCount == 0) {
            cout << "No books are taken.\n";
        } else {
            for (int i = 0; i < takenCount; i++) {
                cout << "- " << takenBooks[i] << endl;
            }
        }
    }
};

int main() {
    Library hamzasLibrary;
    
    hamzasLibrary.insertBook("C Programming");
    hamzasLibrary.insertBook("Object Oriented Programming");
    hamzasLibrary.insertBook("Algorithms");
    
    hamzasLibrary.showBooks();
    
    hamzasLibrary.takeBook("Data Structures");
    hamzasLibrary.showBooks();
    hamzasLibrary.showTakenBooks();
    
    hamzasLibrary.giveBackBook("Data Structures");
    hamzasLibrary.showBooks();
    hamzasLibrary.showTakenBooks();
    
    return 0;
}

