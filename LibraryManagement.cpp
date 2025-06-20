#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Library {
public:
    Library() {
        cout << "Library Constructor\n\n";
    }
    virtual void display() = 0;
};

class DVD {
    int minutes;
public:
    DVD(int minutes = 0) {
        cout << "DVD Constructor\n\n";
        this->minutes = minutes;
    }
    void setminutes(int x) {
        minutes = x;
    }
    int getminutes() {
        return minutes;
    }
    void display() {
        cout << "Minutes of DVD : " << minutes << endl;
    }
};

class Magazines {
private:
    int issueNumber;
    int year;
    int* arr;
    int size;
public:
    Magazines() {
        cout << "Magazine Constructor\n\n";
        issueNumber = 0;
        year = 0;
        size = 0;
        arr = NULL;
    }
    ~Magazines() {
        delete[] arr;
    }
    void setIssueNumber(int x) {
        issueNumber = x;
    }
    int getIssueNumber() {
        return issueNumber;
    }
    void setYear(int y) {
        year = y;
    }
    int getYear() {
        return year;
    }
    void add() {
        int* newarr = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newarr[i] = arr[i];
        }
        cout << "Add Magazine Issue Number: ";
        while (!(cin >> newarr[size])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number: ";
        }
        delete[] arr;
        arr = newarr;
        size++;
    }
    void display() {
        cout << "Magazine Issue Number : " << issueNumber << endl;
        cout << "Magazine Year : " << year << endl;
    }
};

class Books {
private:
    int pages;
    string author;
    string bookName;
    string* arr;
    int size;
public:
    Books(int pages = 0, string author = "N/A", string bookName = "N/A", int size = 0) {
        cout << "Books Constructor\n\n";
        this->pages = pages;
        this->author = author;
        this->bookName = bookName;
        this->size = size;
        arr = NULL;
    }
    ~Books() {
        delete[] arr;
    }
    void setpages(int x) {
        pages = x;
    }
    int getpages() {
        return pages;
    }
    void setbookName(string x) {
        bookName = x;
    }
    string getbookName() {
        return bookName;
    }
    void setAuthor(string y) {
        author = y;
    }
    string getAuthor() {
        return author;
    }
    void add() {
        string* newarr = new string[size + 1];
        for (int i = 0; i < size; i++) {
            newarr[i] = arr[i];
        }
        cout << "Add a book title: ";
        cin.ignore();
        getline(cin, newarr[size]);
        delete[] arr;
        arr = newarr;
        size++;
    }
    void display() {
        cout << "Book Name : " << bookName << endl;
        cout << "Pages     : " << pages << endl;
        cout << "Author    : " << author << endl << endl;
    }
    void search(int index) {
        if (index >= 0 && index < size) {
            cout << "Book at index " << index << ": " << arr[index] << endl;
        } else {
            cout << "Invalid index.\n";
        }
    }
};

class Items : public Library {
public:
    Items() {
        cout << "Items Constructor\n" << endl;
    }
    Books Obj;
    DVD Obj2;
    Magazines Obj3;

    void display() override {
        cout << "\n--- Displaying All Items ---\n";
        Obj.display();
        Obj2.display();
        Obj3.display();
        cout << "----------------------------\n";
    }
};

int getValidatedInt(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number: ";
    }
    return value;
}

int main() {
    Items obj;
    int input;

    do {
        cout << "\n========= Library Menu =========\n";
        cout << "1. Set Book Info\n";
        cout << "2. Set DVD Info\n";
        cout << "3. Set Magazine Info\n";
        cout << "4. View Book Info\n";
        cout << "5. View DVD Info\n";
        cout << "6. View Magazine Info\n";
        cout << "7. Add Book Title\n";
        cout << "8. Search Book Title\n";
        cout << "9. Add Magazine Issue\n";
        cout << "0. Exit\n";
        input = getValidatedInt("Choose an option: ");

        switch (input) {
        case 1: {
            string name, author;
            cout << "Enter Book Name: ";
            cin.ignore();
            getline(cin, name);
            obj.Obj.setbookName(name);

            cout << "Enter Author Name: ";
            getline(cin, author);
            obj.Obj.setAuthor(author);

            int pages = getValidatedInt("Enter Number of Pages: ");
            obj.Obj.setpages(pages);
            break;
        }
        case 2: {
            int min = getValidatedInt("Enter DVD Duration (minutes): ");
            obj.Obj2.setminutes(min);
            break;
        }
        case 3: {
            int year = getValidatedInt("Enter Magazine Year: ");
            obj.Obj3.setYear(year);
            int issue = getValidatedInt("Enter Issue Number: ");
            obj.Obj3.setIssueNumber(issue);
            break;
        }
        case 4:
            obj.Obj.display();
            break;
        case 5:
            obj.Obj2.display();
            break;
        case 6:
            obj.Obj3.display();
            break;
        case 7:
            obj.Obj.add();
            break;
        case 8: {
            int index = getValidatedInt("Enter Book Index to Search: ");
            obj.Obj.search(index);
            break;
        }
        case 9:
            obj.Obj3.add();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Option!\n";
        }
    } while (input != 0);

    return 0;
}

