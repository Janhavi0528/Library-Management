#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
class book
{
public:
  char *author, *title, *publisher, *about, *name;
  float *cost;
  int *stock;

public:
  book()
  {
    author = new char[20];
    title = new char[20];
    publisher = new char[20];
    cost = new float;
    stock = new int;
    name = new char[20];
  }
  void Inputdata();
  void editdata();
  void Display();
  int search(char[]);
  void Purchase();
};

void book::Inputdata()
{

  cin.ignore();
  cout << "Enter Title Name: ";
  cin.getline(title, 20);
  cout << "Enter Author Name: ";
  cin.getline(author, 20);
  cout << "Enter Price: ";
  cin >> *cost;
  cout << "Enter Stock Position: ";
  cin >> *stock;
}

void book::Display()
{
  cout << "\nTitle Name: " << title;
  cout << "\nAuthor Name: " << author;
  cout << "\nPrice: " << *cost;
  cout << "\nStock Position: " << *stock;
}

int book::search(char tbuy[20])
{
  if (strcmp(tbuy, title) == 0 || strcmp(tbuy, author) == 0)
    return 1;
  else
    return 0;
}

void book::Purchase()
{
  int count;
  cout << "\nEnter Number Of Books to buy: ";
  cin >> count;
  if (count <= *stock)
  {
    cin.ignore();
    cout << "Enter Your Name: ";
    cin.getline(name, 20);
    cout << " " << name << " bought"
         << " " << title << " book successfully. \n";
    *stock = *stock - count;
    cout << "\nAmount: Rs. " << (*cost) * count, cout << "\n";
  }
  else
  {
    cout << "\nRequired Copies not in Stock";
  }
}
class shelf
{
public:
  map<int, pair<string, int>> Bks;
  vector<string> about;
  vector<int> price;
  shelf()
  {

    Bks.insert({1010, {" The Story Of My Experiments With The Truth", 350}});
    Bks.insert({1020, {" The Guide ", 400}});
    Bks.insert({1030, {" A Fine Balance ", 200}});
    Bks.insert({1040, {" Midnight's Children", 190}});
    Bks.insert({1050, {" The Interpreter Of Maladies", 1000}});
    Bks.insert({1060, {" The Daughter's Tale", 2000}});
    Bks.insert({1070, {" Gorgeous Lies ", 300}});
    Bks.insert({1080, {" All the Missing Girls", 450}});
    Bks.insert({1090, {" Himself", 1200}});
    Bks.insert({2000, {" The Beautiful Bureaucrat", 1045}});
  }

public:
  void Mybook();
  void MyBooksPrice();
  void AboutMyBooks();
  void BuyBook();
  ifstream file;

  void Myshelf()
  {
    int n = 0;
    do
    {
      cout << "\n1.Book in Our shelf" << endl;
      cout << "2.About Book" << endl;
      cout << "3.Price" << endl;
      cout << "4.Exit from out shelf\n"
           << endl;
      cout << "Enter choice : ";
      cin >> n;
      switch (n)
      {
      case 1:
        Mybook();
        break;
      case 2:
        AboutMyBooks();
        break;
      case 3:
        MyBooksPrice();
        break;
      default:
        break;
      }
    } while (n != 4);
  }
};
void shelf::Mybook()
{

  for (auto &v : Bks)
  {

    cout << " \t" << v.second.first;
    cout << "\n|----------------------------------------------------------------|\n"
         << endl;
  }
}
void shelf::MyBooksPrice()
{

  for (auto &v : Bks)
  {
    cout << " Book Code " << v.first << " : " << v.second.first << "  : Rs " << v.second.second << endl;
    ;
    cout << "\n|-----------------------------------------------------------------|" << endl;
  }
}
void shelf::AboutMyBooks()
{
  string at;
  file.open("Mybooks.txt");
  while (getline(file, at))
  {
    cout << at << endl;
  }
  file.close();
}
void shelf::BuyBook()
{
  MyBooksPrice();
  cout << "Enter Book Code to Buy Book : ";
  int code;
  cin >> code;
  map<string, int>::iterator itr;
  for (auto &v : Bks)
  {
    if (code == v.first)
    {
      cout << "Pay :: " << v.second.second << endl;
    }
  }
}
int main()
{
  // system("cls");
  book *B[20];

  int i = 0, r, t, choice;
  char titlebuy[20], authorbuy[20];
  shelf sh;

  while (1)
  {
    cout << "\nMENU"
         << "\n1. Entry of New Book"
         << "\n2. Our Books"
         << "\n3. Search Book"
         << "\n4. Buy Book"
         << "\n5. Exit"
         << "\n\nEnter your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      B[i] = new book;
      B[i]->Inputdata();
      i++;
      break;

    case 2:
      cin.ignore();
      sh.Myshelf();
      break;

    case 3:
      cin.ignore();
      cout << "\nEnter Title/Author Of Book: ";
      cin.getline(titlebuy, 20);
      for (t = 0; t < i; t++)
      {
        if (B[t]->search(titlebuy))
        {
          cout << "\nBook Found Successfully";
          B[t]->Display();
          break;
        }
      }
      if (t == i)
        cout << "\nOut of Stock";
      break;
    case 4:
      cin.ignore();
      cout << "1.Buy From Our shelf" << endl;
      cout << "2.Buy another " << endl;
      int chc;
      cout << "Enter choice ::" << endl;
      cin >> chc;
      switch (chc)
      {
      case 1:
        sh.BuyBook();
        break;
      case 2:
        cin.ignore();
        cout << "\nEnter Title Of Book: ";
        cin.getline(titlebuy, 20);
        for (t = 0; t < i; t++)
        {
          if (B[t]->search(titlebuy))
          {
            B[t]->Purchase();
            break;
          }
        }
        if (i == 0)
        {
          cout << "No books in inventory";
        }
        break;
      }

      if (t == 1)
        cout << "\nOut of stock.";

      break;
    case 5:
      exit(0);

    default:
      cout << "\nInvalid Choice Entered";
    }
  }
  return 0;
}