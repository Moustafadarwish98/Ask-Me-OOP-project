#include "UsersManager.h"
#include "Menu.h"
#include "Utils.h"

#include <fstream>
#include <iostream>

using namespace std;

UsersManager::UsersManager() { lastUserId = 0; }

int UsersManager::FindUserByUsername(const string &username) const {
  for (int i = 0; i < (int)users.size(); i++)
    if (users[i].GetUserName() == username)
      return i;
  return -1;
}

int UsersManager::FindUserById(int userId) const {
  for (int i = 0; i < (int)users.size(); i++)
    if (users[i].GetUserId() == userId)
      return i;
  return -1;
}

void UsersManager::LoadDatabase() {
  users.clear();
  lastUserId = 0;
  ifstream file("data/users.txt");
  string line;

  while (getline(file, line)) {
    if (line == "")
      continue;
    User user(line);
    users.push_back(user);
    if (user.GetUserId() > lastUserId)
      lastUserId = user.GetUserId();
  }
  file.close();
}

void UsersManager::UpdateDatabase() const {
  ofstream file("data/users.txt");
  for (int i = 0; i < (int)users.size(); i++)
    file << users[i].ToString() << "\n";
  file.close();
}

void UsersManager::AccessSystem() {
  LoginMenu menu;
  int choice = ReadMenuChoice(menu);
  if (choice == 1)
    DoLogin();
  else
    DoSignUp();
}

void UsersManager::DoLogin() {
  while (true) {
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    int index = FindUserByUsername(username);
    if (index != -1 && users[index].GetPassword() == password) {
      currentUser = users[index];
      cout << "\nWelcome, " << currentUser.GetName() << "!\n";
      return;
    }
    cout << "Invalid username or password. Try again.\n";
  }
}

void UsersManager::DoSignUp() {
  string username;
  while (true) {
    cout << "\nChoose a username (no spaces): ";
    cin >> username;
    if (FindUserByUsername(username) == -1)
      break;
    cout << "This username is already taken.\n";
  }

  User newUser;
  newUser.ReadUser(username, lastUserId + 1);
  lastUserId++;
  users.push_back(newUser);
  currentUser = newUser;
  UpdateDatabase();
  cout << "\nAccount created successfully.\n";
}

void UsersManager::ListUsersNamesIds() const {
  cout << "\nSystem users:\n";
  for (int i = 0; i < (int)users.size(); i++)
    cout << "ID: " << users[i].GetUserId() << " | Name: " << users[i].GetName()
         << "\n";
}

int UsersManager::ReadUserId() const {
  while (true) {
    cout << "\nEnter user ID (-1 to cancel): ";
    int userId = ReadNumber();
    if (userId == -1)
      return -1;

    int index = FindUserById(userId);
    if (index == -1)
      cout << "Invalid user ID.\n";
    else if (userId == currentUser.GetUserId())
      cout << "You cannot ask yourself a question.\n";
    else
      return index;
  }
}

User UsersManager::GetUserByIndex(int index) const { return users[index]; }
User UsersManager::GetCurrentUser() const { return currentUser; }
