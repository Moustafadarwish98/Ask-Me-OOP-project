#include "Menu.h"
#include "Utils.h"

#include <iostream>

using namespace std;

Menu::~Menu() {}

void LoginMenu::Display() const {
  cout << "\n========== Ask Me ==========\n";
  cout << "1. Login\n";
  cout << "2. Sign Up\n";
}

int LoginMenu::GetOptionCount() const { return 2; }

void MainMenu::Display() const {
  cout << "\n========== Main Menu ==========\n";
  cout << "1. Print questions sent to me\n";
  cout << "2. Print questions sent by me\n";
  cout << "3. Answer a question\n";
  cout << "4. Delete a question\n";
  cout << "5. Ask a question\n";
  cout << "6. List system users\n";
  cout << "7. Feed\n";
  cout << "8. Logout and exit\n";
}

int MainMenu::GetOptionCount() const { return 8; }

int ReadMenuChoice(const Menu &menu) {
  // Display() and GetOptionCount() are selected according to the real menu
  // type.
  menu.Display();
  return ::ReadMenuChoice(menu.GetOptionCount());
}
