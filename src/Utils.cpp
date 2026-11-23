#include "Utils.h"

#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

vector<string> SplitString(const string &line, char delimiter) {
  vector<string> parts;
  string part;
  stringstream input(line);

  while (getline(input, part, delimiter))
    parts.push_back(part);

  // getline does not return the final empty field after a trailing delimiter.
  if (!line.empty() && line[line.length() - 1] == delimiter)
    parts.push_back("");

  return parts;
}

int ReadNumber() {
  int number;
  while (!(cin >> number)) {
    cout << "Please enter a valid number: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return number;
}

int ReadMenuChoice(int numberOfChoices) {
  cout << "\nEnter your choice: ";
  int choice = ReadNumber();

  while (choice < 1 || choice > numberOfChoices) {
    cout << "Invalid choice. Enter a number from 1 to " << numberOfChoices
         << ": ";
    choice = ReadNumber();
  }
  return choice;
}

void ClearInputLine() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
