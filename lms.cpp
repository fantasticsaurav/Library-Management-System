#include <bits/stdc++.h>
using namespace std;

struct Book
{
  int id;
  string title;
  string author;
  bool isAvailable;
};

vector<Book> library;

void addBook()
{
  Book b;
  cout << "\nEnter Book ID: ";
  cin >> b.id;
  cin.ignore();
  cout << "Enter Book Title: ";
  getline(cin, b.title);
  cout << "Enter Book Author: ";
  getline(cin, b.author);
  b.isAvailable = true;
  library.push_back(b);
  cout << "✅ Book added successfully!\n";
}

void displayBooks()
{
  if (library.empty())
  {
    cout << "\n📚 No books available.\n";
    return;
  }
  cout << "\n--- Library Books ---\n";
  for (const auto &b : library)
  {
    cout << "ID: " << b.id
         << " | Title: " << b.title
         << " | Author: " << b.author
         << " | Status: " << (b.isAvailable ? "Available" : "Issued")
         << "\n";
  }
}

void searchBook()
{
  cin.ignore();
  string searchTitle;
  cout << "\nEnter book title to search: ";
  getline(cin, searchTitle);
  bool found = false;
  for (const auto &b : library)
  {
    if (b.title == searchTitle)
    {
      cout << "\n✅ Book Found:\n";
      cout << "ID: " << b.id << " | Title: " << b.title << " | Author: " << b.author << "\n";
      found = true;
      break;
    }
  }
  if (!found)
    cout << "❌ Book not found.\n";
}

void deleteBook()
{
  int id;
  cout << "\nEnter Book ID to delete: ";
  cin >> id;
  for (auto it = library.begin(); it != library.end(); ++it)
  {
    if (it->id == id)
    {
      library.erase(it);
      cout << "🗑️ Book deleted successfully!\n";
      return;
    }
  }
  cout << "❌ Book ID not found.\n";
}

int main()
{
  int choice;
  do
  {
    cout << "\n===============================";
    cout << "\n   📚 Library Management System";
    cout << "\n===============================";
    cout << "\n1. Add Book";
    cout << "\n2. View All Books";
    cout << "\n3. Search Book";
    cout << "\n4. Delete Book";
    cout << "\n5. Exit";
    cout << "\nEnter your choice: ";
    if (!(cin >> choice))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\n❌ Invalid input! Please enter a number.\n";
      continue;
    }

    switch (choice)
    {
    case 1:
      addBook();
      break;
    case 2:
      displayBooks();
      break;
    case 3:
      searchBook();
      break;
    case 4:
      deleteBook();
      break;
    case 5:
      cout << "\n👋 Exiting program...\n";
      break;
    default:
      cout << "\n❌ Invalid choice! Try again.\n";
    }
  } while (choice != 5);

  return 0;
}
