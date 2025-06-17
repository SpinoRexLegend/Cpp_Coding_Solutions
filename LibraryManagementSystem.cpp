#include<iostream>
#include<vector>
using namespace std;

class Book
{
    private:
        int bookId;
        string bookName;
        string author;
        int publishYear;
        bool isIssued;
    public:
        Book(int bookId, string bookName, string author, int publishYear)
        {
            this->bookId = bookId;
            this->bookName = bookName;
            this->author = author;
            this->publishYear = publishYear;
            isIssued = false;
        }
        
        void getDetails()
        {
            cout<<"Book Name: "<<bookName<<endl;
            cout<<"Author: "<<author<<endl;
            cout<<"Publish Year: "<<publishYear<<endl;
            cout<<"Is the book Issued: "<<isIssued<<endl;
        }
        string getName();
        string getAuthor();
        bool getStatus();
        int getId();
        
        void issueBook()
        {
            isIssued = true;
        }
        void returnBook()
        {
            isIssued = false;
        }
};
string Book::getName()
{
    return bookName;
}
string Book::getAuthor()
{
    return author;
}
bool Book::getStatus()
{
    return isIssued;
}
int Book::getId()
{
    return bookId;
}

class Library
{
    private:
        vector<Book*> books;
    public:
        void addBook(Book* book)
        {
            books.push_back(book);
        }
        void showBook()
        {
            for(auto book: books)
                book->getDetails();
        }
        void issueBook(int id)
        {
            for(auto book: books)
            {
                if(book->getId() == id)
                {
                    if(!book->getStatus())
                    {
                        book->issueBook();
                        cout<<"Succesfully Issued"<<endl;
                    }
                    else cout<<"Book already issued"<<endl;
                    return;
                }
            }
        }
        void returnBook(int id)
        {
            for(auto book: books)
            {
                if(book->getId() == id)
                {
                    if(book->getStatus())
                    {
                        book->returnBook();
                        cout<<"Returned Succesfully"<<endl;
                    }
                    else cout<<"Book already returned"<<endl;
                    return;
                }
            }
        }
};

int main()
{
    Library lib;
    int n;
    cout<<"Enter how many book you wanna enter: "<<endl;
    cin>>n;
    string bookName;
    string author;
    int publishYear;
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter book name, author and year of publish"<<endl;
        cin>>bookName>>author>>publishYear;
        
        lib.addBook(new Book(i, bookName, author, publishYear));
    }
    
    int choice, id;
    do
    {
        cout<<"Menu\n"<<"Press 1 to issue book\n"<<"Press 2 to return book\n"<<"Press 3 to add book\n"<<"Press 4 to display book details\n"<<"Press 0 to quit\n"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Book id"<<endl;
                cin>> id;
                lib.issueBook(id);
                break;
            case 2:
                cout<<"Enter Book id"<<endl;
                cin>> id;
                lib.returnBook(id);
                break;
            case 3: 
                cout<<"Enter book id, book name, author and year of publish"<<endl;
                cin>>id>>bookName>>author>>publishYear;
                lib.addBook(new Book(id, bookName, author, publishYear));
                break;
            case 4:
                lib.showBook();
                break;
            case 0:
                return 0;
        }
    }while(choice != 0);
    return 1;
}
