#include <iostream>
#include <string>
using namespace std;

#define MAX_ITEMS 100

// ================= ABSTRACT BASE CLASS =================

class LibraryItem
{
    
private:

    string title;
    string author;
    string dueDate;

public:

    // Getters
    
    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    // Setters
    
    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    // Pure Virtual Functions
    
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};


// ================= BOOK CLASS =================

class Book : public LibraryItem
{
    
private:

    string isbn;

public:

    void input()
    {
        string title, author, dueDate;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Due Date: ";
        getline(cin, dueDate);

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        // Exception Handling
        
        if (isbn.length() < 5)
        {
            throw invalid_argument("Invalid ISBN Format!");
        }

        setTitle(title);
        
        setAuthor(author);
        
        setDueDate(dueDate);
    }

    void checkOut() override
    {
        cout << "Book Checked Out Successfully!\n";
    }

    void returnItem() override
    {
        cout << "Book Returned Successfully!\n";
    }

    void displayDetails() override
    {
        cout << "\n===== BOOK DETAILS =====\n";
        
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "ISBN     : " << isbn << endl;
    }
};

// ================= DVD CLASS =================

class DVD : public LibraryItem
{
private:
    int duration;

public:
    void input()
    {
        string title, author, dueDate;

        cin.ignore();

        cout << "Enter DVD Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Due Date: ";
        getline(cin, dueDate);

        cout << "Enter Duration (minutes): ";
        cin >> duration;

        if (duration <= 0)
        {
            throw invalid_argument("Duration must be positive!");
        }

        setTitle(title);
        
        setAuthor(author);
        
        setDueDate(dueDate);
    }

    void checkOut() override
    {
        cout << "DVD Checked Out Successfully!\n";
    }

    void returnItem() override
    {
        cout << "DVD Returned Successfully!\n";
    }

    void displayDetails() override
    {
        cout << "\n===== DVD DETAILS =====\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << duration << " minutes\n";
    }
};

// ================= MAGAZINE CLASS =================

class Magazine : public LibraryItem
{
    
private:

    int issueNumber;

public:

    void input()
    {
        string title, author, dueDate;

        cin.ignore();

        cout << "Enter Magazine Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Due Date: ";
        getline(cin, dueDate);

        cout << "Enter Issue Number: ";
        cin >> issueNumber;

        if (issueNumber <= 0)
        {
            throw invalid_argument("Invalid Issue Number!");
        }

        setTitle(title);
        
        setAuthor(author);
        
        setDueDate(dueDate);
    }

    void checkOut() override
    {
        cout << "Magazine Checked Out Successfully!\n";
    }

    void returnItem() override
    {
        cout << "Magazine Returned Successfully!\n";
    }

    void displayDetails() override
    {
        cout << "\n===== MAGAZINE DETAILS =====\n";
        
        cout << "Title: " << getTitle() << endl;
        
        cout << "Author: " << getAuthor() << endl;
        
        cout << "Due Date: " << getDueDate() << endl;
        
        cout << "Issue Number: " << issueNumber << endl;
    }
    
};


// ================= MAIN =================

int main()
{
    LibraryItem* libraryItems[MAX_ITEMS];

    int totalItems = 0;
    
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
                
            case 1:
            {
                Book* b = new Book();
                b->input();

                libraryItems[totalItems++] = b;

                cout << "Book Added Successfully!\n";
                
                break;
            }

            case 2:
            {
                DVD* d = new DVD();
                d->input();

                libraryItems[totalItems++] = d;

                cout << "DVD Added Successfully!\n";
                
                break;
            }

            case 3:
            {
                Magazine* m = new Magazine();
                m->input();

                libraryItems[totalItems++] = m;

                cout << "Magazine Added Successfully!\n";
                
                break;
            }

            case 4:
            {
                if (totalItems == 0)
                {
                    cout << "No Items Found!\n";
                }
                
                else
                {
                    for (int i = 0; i < totalItems; i++)
                    {
                        libraryItems[i]->displayDetails();
                    }
                }

                break;
            }

            case 5:
            {
                int index;

                cout << "Enter Item Number: ";
                cin >> index;

                if (index < 1 || index > totalItems)
                {
                    throw out_of_range("Invalid Item Number!");
                }

                libraryItems[index - 1]->checkOut();

                break;
            }

            case 6:
            {
                int index;

                cout << "Enter Item Number: ";
                cin >> index;

                if (index < 1 || index > totalItems)
                {
                    throw out_of_range("Invalid Item Number!");
                }

                libraryItems[index - 1]->returnItem();

                break;
            }

            case 7:
            {
                cout << "Exiting System...\n";
                
                break;
            }

            default:
            {
                cout << "Invalid Choice!\n";
            }
            
            }
        }

        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }

    }
    while (choice != 7);

    // Memory Release
    
    for (int i = 0; i < totalItems; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}
