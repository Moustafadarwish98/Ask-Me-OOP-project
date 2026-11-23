#include "AskMeSystem.h"
#include "Menu.h"

#include <iostream>

using namespace std;

void AskMeSystem::Run()
{
    usersManager.LoadDatabase();
    questionsManager.LoadDatabase();
    usersManager.AccessSystem();

    MainMenu menu;
    while (true)
    {
        int choice = ReadMenuChoice(menu);
        User currentUser = usersManager.GetCurrentUser();

        if (choice == 1)
            questionsManager.PrintQuestionsToUser(currentUser);
        else if (choice == 2)
            questionsManager.PrintQuestionsFromUser(currentUser);
        else if (choice == 3)
            questionsManager.AnswerQuestion(currentUser);
        else if (choice == 4)
            questionsManager.DeleteQuestion(currentUser);
        else if (choice == 5)
        {
            usersManager.ListUsersNamesIds();
            int userIndex = usersManager.ReadUserId();
            if (userIndex != -1)
            {
                User toUser = usersManager.GetUserByIndex(userIndex);
                questionsManager.AskQuestion(currentUser, toUser);
            }
        }
        else if (choice == 6)
            usersManager.ListUsersNamesIds();
        else if (choice == 7)
            questionsManager.PrintFeed();
        else
            break;
    }

    cout << "\nGoodbye!\n";
}
