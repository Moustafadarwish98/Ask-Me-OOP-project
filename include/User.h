#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// Stores one user's account information and preferences.
class User {
private:
  int userId;
  string userName;
  string password;
  string name;
  string email;
  int allowAnonymousQuestions;

public:
  User();
  explicit User(const string &line);

  string ToString() const;
  void ReadUser(const string &username, int id);

  int GetUserId() const;
  string GetUserName() const;
  string GetPassword() const;
  string GetName() const;
  string GetEmail() const;
  int IsAllowAnonymousQuestions() const;

  void SetUserId(int id);
  void SetUserName(const string &username);
  void SetPassword(const string &userPassword);
  void SetName(const string &userName);
  void SetEmail(const string &userEmail);
  void SetAllowAnonymousQuestions(int value);
};

#endif
