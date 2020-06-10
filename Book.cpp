#include <iostream>
#include "Book.h"
#include <string>
#include <cstring>

using namespace std;
    Book :: Book()
    {
        setCountPage(0);
    }
    Book :: Book(const string *name, const string *author, const int &countPage)
    {
        this -> name = *(name);
        this -> author = *(author);
        this -> countPage = countPage;
    }

    Book :: Book (const Book &otherBook)
    {
        this -> name = otherBook.name;
        this -> author = otherBook.author;
        this -> countPage = otherBook.countPage;
    }
    void Book :: print()
    {   cout << "Name: " << name << "\nAuthor: " << author << "\nCount of pages: " << countPage << endl;    }

    void Book :: setName(const string *name)
    {   this -> name = *(name);  }

    void Book :: setAuthor(const string *author)
    {   this -> author = *(author);  }

    void Book :: setCountPage(const int &countPage)
    {   this -> countPage = countPage;  }

    string Book :: getName()
    {
        return name;
    }

    string Book :: getAuthor()
    {
        return author;
    }

   int Book :: getCountPage()
    {
        return countPage;
    }
