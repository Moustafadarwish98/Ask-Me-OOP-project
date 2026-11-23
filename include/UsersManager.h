#ifndef USERS_MANAGER_H
#define USERS_MANAGER_H

#include "User.h"

#include <string>
#include <vector>
using namespace std;

// Handles user registration, login, lookup and account storage.
class UsersManager {
private:
  vector<User> users;
  User currentUser;
  int lastUserId;

  int FindUserByUsername(const string &username) const;
  int FindUserById(int userId) const;

public:
  UsersManager();

  void LoadDatabase();
  void UpdateDatabase() const;
  void AccessSystem();
  void DoLogin();
  void DoSignUp();
  void ListUsersNamesIds() const;
  int ReadUserId() const;

  User GetUserByIndex(int index) const;
  User GetCurrentUser() const;
};

#endif
