#ifndef QUESTIONS_MANAGER_H
#define QUESTIONS_MANAGER_H

#include "Question.h"
#include "User.h"

#include <vector>
using namespace std;

// Loads, saves and performs operations on questions.
class QuestionsManager {
private:
  vector<Question> questions;
  int lastQuestionId;

  int FindQuestionIndex(int questionId) const;
  int ReadQuestionIdForUser(const User &user) const;

public:
  QuestionsManager();

  void LoadDatabase();
  void UpdateDatabase() const;
  void PrintQuestionsToUser(const User &user) const;
  void PrintQuestionsFromUser(const User &user) const;
  void AnswerQuestion(const User &user);
  void DeleteQuestion(const User &user);
  void AskQuestion(const User &fromUser, const User &toUser);
  void PrintFeed() const;
};

#endif
