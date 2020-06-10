#include <iostream>
#include "Book.h"
#include <string>
#include <stdlib.h>


using namespace std;


void showMenu()
{
    cout << "\t\t\t***Menu***" << endl;
    cout << "\t0)To select book" << endl;
    cout << "\t1)Set book's name" << endl;
    cout << "\t2)Set book's author" << endl;
    cout << "\t3)Set count of pages in this book" << endl;
    cout << "\t4)Get book's name" << endl;
    cout << "\t5)Get book's author" << endl;
    cout << "\t6)Get count of pages in this book" << endl;
    cout << "\t7)Show all information about book" << endl;
    cout << "\t8)Copy this book" << endl;
    cout << "\t9)Delete this book" << endl;
    cout << "\t10)Add new cars" << endl;
}

void showAllBooks(short countOfBook, Book *Books)
{
    for (short i = 0; i < countOfBook; i++)
    {
        cout << i+1 << ")";
        Books[i].print();
    }
}

int main()
{
    string tmpName, tmpAuthor;
    short var = 0, countOfBook = 1, i = 0, y = 0, addcount = 0;
    int tmpCountPage = 0;
    Book *Books = new Book[1], *tmpBooks;
    while (1)
    {
        cout << "\nSelect book or close program(input 0)\n" << endl;
        showAllBooks(countOfBook, Books);
        cin >> i;
        if (i == 0)
        {
            delete Books;
            return 0;
        }

        while (i != 0)
        {
            showMenu();
            cin >> var;
            switch (var)
            {
                case 0:
                    i = 0;
                    break;
                case 1:
                    cout << "\nEntry name of book:" << endl;
                    cin >> tmpName;
                    Books[i-1].setName(&tmpName);
                    break;
                case 2:
                    cout << "\nEntry author of this book:" << endl;
                    cin >> tmpAuthor;
                    Books[i-1].setAuthor(&tmpAuthor);
                    break;
                case 3:
                    cout << "\nEntry count of page of this book:" << endl;
                    cin >> tmpCountPage;
                    if (tmpCountPage >= 0)
                    {
                        Books[i-1].setCountPage(tmpCountPage);
                    }else{
                        cout << "\nUncorrect count of page input. Repeat." << endl;
                        }
                    break;
                case 4:
                    cout << "\nTaken book's name:\t" << (tmpName = Books[i-1].getName()) << endl;
                    break;
                case 5:
                    cout << "\nTaken book's author:\t" << (tmpAuthor = Books[i-1].getAuthor()) << endl;
                    break;
                case 6:
                    cout << "\nTaken count of pages:\t" << (tmpCountPage = Books[i-1].getCountPage()) << endl;
                    break;
                case 7:
                    Books[i-1].print();
                    break;
                case 8:{
                    countOfBook++;
                    tmpBooks = new Book[countOfBook];
                    for (y = 0; y < countOfBook-1; y++)
                    {
                        tmpBooks[y] = Books[y];
                        delete &(Books[y]);
                    }
                    delete Books;
                    Books = tmpBooks;
                    Book newBook(Books[i-1]);
                    Books[countOfBook-1] = newBook;
                    break;}
                case 9:{
                    Books[i-1] = Books[countOfBook-1];
                    delete &(Books[countOfBook-1]);
                    countOfBook --;
                    tmpBooks = new Book[countOfBook];
                    for (y = 0; y < countOfBook; y++)
                    {
                        tmpBooks[y] = Books[y];
                        delete &(Books[y]);
                    }
                    delete Books;
                    Books = tmpBooks;
                    i = 0;
                    break;}
                case 10:{
                    while (addcount < 1)
                    {
                        cout << "How many book add?" << endl;
                        cin >> addcount;
                    }
                    countOfBook += addcount;
                    tmpBooks = new Book[countOfBook];
                    for (y = 0; y < countOfBook-addcount; y++)
                    {
                        tmpBooks[y] = Books[y];
                    }
                    delete [] Books;
                    Books = tmpBooks;
                    for (; y < countOfBook; y++)
                    {
                        cout << "Entry book's name" << endl;
                        cin >> tmpName;
                        cout << "Entry book's author" << endl;
                        cin >> tmpAuthor;
                        cout << "How many page in book?" << endl;
                        cin >> tmpCountPage;
                        Book newBook(&tmpName, &tmpAuthor, tmpCountPage);
                        Books[y] = newBook;
                    }
                }
            }
        }
    }
}
