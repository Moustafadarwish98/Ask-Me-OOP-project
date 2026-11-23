#ifndef ASK_ME_SYSTEM_H
#define ASK_ME_SYSTEM_H

#include "QuestionsManager.h"
#include "UsersManager.h"

// Coordinates the managers and controls the application's main loop.
class AskMeSystem
{
private:
    UsersManager usersManager;
    QuestionsManager questionsManager;

public:
    void Run();
};

#endif
