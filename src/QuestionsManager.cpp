#include "QuestionsManager.h"
#include "Utils.h"

#include <fstream>
#include <iostream>

using namespace std;

QuestionsManager::QuestionsManager() { lastQuestionId = 0; }

int QuestionsManager::FindQuestionIndex(int questionId) const {
  for (int i = 0; i < (int)questions.size(); i++)
    if (questions[i].GetQuestionId() == questionId)
      return i;
  return -1;
}

int QuestionsManager::ReadQuestionIdForUser(const User &user) const {
  while (true) {
    cout << "Enter question ID (-1 to cancel): ";
    int questionId = ReadNumber();
    if (questionId == -1)
      return -1;

    int index = FindQuestionIndex(questionId);
    if (index == -1)
      cout << "There is no question with this ID.\n";
    else if (questions[index].GetToUserId() != user.GetUserId())
      cout << "This question was not sent to you.\n";
    else
      return index;
  }
}

void QuestionsManager::LoadDatabase() {
  questions.clear();
  lastQuestionId = 0;
  ifstream file("data/questions.txt");
  string line;

  while (getline(file, line)) {
    if (line == "")
      continue;
    Question question(line);
    questions.push_back(question);
    if (question.GetQuestionId() > lastQuestionId)
      lastQuestionId = question.GetQuestionId();
  }
  file.close();
}

void QuestionsManager::UpdateDatabase() const {
  ofstream file("data/questions.txt");
  for (int i = 0; i < (int)questions.size(); i++)
    file << questions[i].ToString() << "\n";
  file.close();
}

void QuestionsManager::PrintQuestionsToUser(const User &user) const {
  bool found = false;
  cout << "\nQuestions sent to you:\n";
  for (int i = 0; i < (int)questions.size(); i++) {
    if (questions[i].GetToUserId() == user.GetUserId()) {
      questions[i].Print();
      found = true;
    }
  }
  if (!found)
    cout << "You have no questions.\n";
}

void QuestionsManager::PrintQuestionsFromUser(const User &user) const {
  bool found = false;
  cout << "\nQuestions sent by you:\n";
  for (int i = 0; i < (int)questions.size(); i++) {
    if (questions[i].GetFromUserId() == user.GetUserId()) {
      questions[i].Print();
      found = true;
    }
  }
  if (!found)
    cout << "You have not sent any questions.\n";
}

void QuestionsManager::AnswerQuestion(const User &user) {
  int index = ReadQuestionIdForUser(user);
  if (index == -1)
    return;

  questions[index].Print();
  cout << "Enter your answer: ";
  ClearInputLine();
  string answer;
  getline(cin, answer);
  questions[index].SetAnswerText(answer);
  UpdateDatabase();
  cout << "Answer saved.\n";
}

void QuestionsManager::DeleteQuestion(const User &user) {
  int index = ReadQuestionIdForUser(user);
  if (index == -1)
    return;

  int questionId = questions[index].GetQuestionId();
  vector<int> idsToDelete;
  idsToDelete.push_back(questionId);

  // Deleting a main question also deletes its direct thread replies.
  if (questions[index].GetParentQuestionId() == -1) {
    for (int i = 0; i < (int)questions.size(); i++)
      if (questions[i].GetParentQuestionId() == questionId)
        idsToDelete.push_back(questions[i].GetQuestionId());
  }

  for (int i = 0; i < (int)questions.size(); i++) {
    for (int j = 0; j < (int)idsToDelete.size(); j++) {
      if (questions[i].GetQuestionId() == idsToDelete[j]) {
        questions.erase(questions.begin() + i);
        i--;
        break;
      }
    }
  }

  UpdateDatabase();
  cout << "Question deleted.\n";
}

void QuestionsManager::AskQuestion(const User &fromUser, const User &toUser) {
  Question question;
  question.SetQuestionId(++lastQuestionId);
  question.SetFromUserId(fromUser.GetUserId());
  question.SetToUserId(toUser.GetUserId());

  if (toUser.IsAllowAnonymousQuestions() == 0) {
    cout << "This user does not allow anonymous questions.\n";
    question.SetIsAnonymous(0);
  } else {
    cout << "Send anonymously? (1 = yes, 0 = no): ";
    int anonymous = ReadNumber();
    while (anonymous != 0 && anonymous != 1) {
      cout << "Please enter 1 or 0: ";
      anonymous = ReadNumber();
    }
    question.SetIsAnonymous(anonymous);
  }

  cout << "Enter a main question ID to reply to, or -1 for a new thread: ";
  int parentId = ReadNumber();
  while (parentId != -1) {
    int parentIndex = FindQuestionIndex(parentId);
    if (parentIndex != -1 && questions[parentIndex].GetParentQuestionId() == -1)
      break;
    cout << "Invalid main question ID. Try again, or enter -1: ";
    parentId = ReadNumber();
  }
  question.SetParentQuestionId(parentId);

  cout << "Enter your question: ";
  ClearInputLine();
  string questionText;
  getline(cin, questionText);
  question.SetQuestionText(questionText);

  questions.push_back(question);
  UpdateDatabase();
  cout << "Question sent.\n";
}

void QuestionsManager::PrintFeed() const {
  bool found = false;
  cout << "\n========== Feed ==========\n";
  for (int i = 0; i < (int)questions.size(); i++) {
    if (questions[i].GetAnswerText() != "") {
      questions[i].Print();
      found = true;
    }
  }
  if (!found)
    cout << "There are no answered questions yet.\n";
}
