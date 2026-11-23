#include "Question.h"
#include "Utils.h"

#include <iostream>

using namespace std;

Question::Question() {
  questionId = -1;
  parentQuestionId = -1;
  fromUserId = -1;
  toUserId = -1;
  isAnonymous = 1;
}

Question::Question(const string &line) {
  vector<string> parts = SplitString(line);
  questionId = stoi(parts[0]);
  parentQuestionId = stoi(parts[1]);
  fromUserId = stoi(parts[2]);
  toUserId = stoi(parts[3]);
  isAnonymous = stoi(parts[4]);
  questionText = parts[5];
  answerText = parts[6];
}

string Question::ToString() const {
  return to_string(questionId) + "," + to_string(parentQuestionId) + "," +
         to_string(fromUserId) + "," + to_string(toUserId) + "," +
         to_string(isAnonymous) + "," + questionText + "," + answerText;
}

void Question::Print() const {
  if (parentQuestionId != -1)
    cout << "Thread reply to question ID: " << parentQuestionId << "\n";

  cout << "Question ID: " << questionId;
  if (isAnonymous == 0)
    cout << " | From user ID: " << fromUserId;

  cout << "\nQuestion: " << questionText << "\n";

  if (answerText != "")
    cout << "Answer: " << answerText << "\n";
  else
    cout << "Not answered yet\n";

  cout << "-----------------------------\n";
}

int Question::GetQuestionId() const { return questionId; }
int Question::GetParentQuestionId() const { return parentQuestionId; }
int Question::GetFromUserId() const { return fromUserId; }
int Question::GetToUserId() const { return toUserId; }
int Question::GetIsAnonymous() const { return isAnonymous; }
string Question::GetQuestionText() const { return questionText; }
string Question::GetAnswerText() const { return answerText; }

void Question::SetQuestionId(int id) { questionId = id; }
void Question::SetParentQuestionId(int id) { parentQuestionId = id; }
void Question::SetFromUserId(int id) { fromUserId = id; }
void Question::SetToUserId(int id) { toUserId = id; }
void Question::SetIsAnonymous(int value) { isAnonymous = value; }
void Question::SetQuestionText(const string &text) { questionText = text; }
void Question::SetAnswerText(const string &answer) { answerText = answer; }
