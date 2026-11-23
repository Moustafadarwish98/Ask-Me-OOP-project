#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

// Represents a question or a reply in a question thread.
class Question {
private:
  int questionId;
  int parentQuestionId;
  int fromUserId;
  int toUserId;
  int isAnonymous;
  string questionText;
  string answerText;

public:
  Question();
  explicit Question(const string &line);

  string ToString() const;
  void Print() const;

  int GetQuestionId() const;
  int GetParentQuestionId() const;
  int GetFromUserId() const;
  int GetToUserId() const;
  int GetIsAnonymous() const;
  string GetQuestionText() const;
  string GetAnswerText() const;

  void SetQuestionId(int id);
  void SetParentQuestionId(int id);
  void SetFromUserId(int id);
  void SetToUserId(int id);
  void SetIsAnonymous(int value);
  void SetQuestionText(const string &text);
  void SetAnswerText(const string &answer);
};

#endif
