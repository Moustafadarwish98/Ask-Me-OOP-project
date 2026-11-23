#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
using namespace std;

// General-purpose functions shared by the project.
vector<string> SplitString(const string &line, char delimiter = ',');
int ReadNumber();
int ReadMenuChoice(int numberOfChoices);
void ClearInputLine();

#endif
