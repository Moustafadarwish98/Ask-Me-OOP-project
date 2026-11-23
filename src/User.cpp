#include "User.h"
#include "Utils.h"

#include <iostream>

using namespace std;

User::User() {
  userId = -1;
  allowAnonymousQuestions = 1;
}

User::User(const string &line) {
  vector<string> parts = SplitString(line);
  userId = stoi(parts[0]);
  userName = parts[1];
  password = parts[2];
  name = parts[3];
  email = parts[4];
  allowAnonymousQuestions = stoi(parts[5]);
}

string User::ToString() const {
  return to_string(userId) + "," + userName + "," + password + "," + name +
         "," + email + "," + to_string(allowAnonymousQuestions);
}

void User::ReadUser(const string &username, int id) {
  userName = username;
  userId = id;

  cout << "Enter password: ";
  cin >> password;
  cout << "Enter name (use underscores instead of spaces): ";
  cin >> name;
  cout << "Enter email: ";
  cin >> email;
  cout << "Allow anonymous questions? (1 = yes, 0 = no): ";
  cin >> allowAnonymousQuestions;

  while (allowAnonymousQuestions != 0 && allowAnonymousQuestions != 1) {
    cout << "Please enter 1 or 0: ";
    cin >> allowAnonymousQuestions;
  }
}

int User::GetUserId() const { return userId; }
string User::GetUserName() const { return userName; }
string User::GetPassword() const { return password; }
string User::GetName() const { return name; }
string User::GetEmail() const { return email; }
int User::IsAllowAnonymousQuestions() const { return allowAnonymousQuestions; }

void User::SetUserId(int id) { userId = id; }
void User::SetUserName(const string &username) { userName = username; }
void User::SetPassword(const string &userPassword) { password = userPassword; }
void User::SetName(const string &userName) { name = userName; }
void User::SetEmail(const string &userEmail) { email = userEmail; }
void User::SetAllowAnonymousQuestions(int value) {
  allowAnonymousQuestions = value;
}
