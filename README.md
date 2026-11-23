# Ask Me – C++ Console Application

A beginner-friendly, object-oriented question-and-answer application written in C++. Users can create an account, ask other users questions, reply to question threads, answer received questions, and browse answered questions in a public feed.

## Features

- User registration and login
- Usernames and unique numeric user IDs
- Anonymous or identified questions, depending on the recipient's settings
- Main questions and thread replies
- Answering and deleting received questions
- Lists of sent and received questions
- Public feed of answered questions
- File-based data storage using text files

## Project structure

```text
AskMeProject/
├── data/
│   ├── questions.txt
│   └── users.txt
├── include/
│   ├── AskMeSystem.h
│   ├── Menu.h
│   ├── Question.h
│   ├── QuestionsManager.h
│   ├── User.h
│   ├── UsersManager.h
│   └── Utils.h
├── src/
│   ├── AskMeSystem.cpp
│   ├── Menu.cpp
│   ├── Question.cpp
│   ├── QuestionsManager.cpp
│   ├── User.cpp
│   ├── UsersManager.cpp
│   ├── Utils.cpp
│   └── main.cpp
├── .gitignore
├── CMakeLists.txt
└── README.md
```

## Requirements

- A C++11-compatible compiler (GCC, Clang, or MSVC)

## Build and run

Run these commands from the project root.

### Linux / macOS (GCC or Clang)

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -Iinclude src/*.cpp -o AskMe
./AskMe
```

### Windows (MinGW)

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -Iinclude src/*.cpp -o AskMe.exe
AskMe.exe
```

The application reads and writes `data/users.txt` and `data/questions.txt`. Run the executable from the project root so these relative paths resolve correctly.

## OOP concepts used

- **Encapsulation:** `User` and `Question` keep their data members private and expose getters and setters.
- **Abstraction:** `UsersManager` and `QuestionsManager` provide operations that hide the details of storing and searching records.
- **Inheritance:** `LoginMenu` and `MainMenu` derive from the abstract `Menu` base class.
- **Polymorphism:** `ReadMenuChoice(const Menu&)` works with a base-class reference and calls virtual functions. The correct menu implementation is selected at runtime.
- **Composition:** `AskMeSystem` contains a `UsersManager` and a `QuestionsManager` and coordinates their work.

## Data format

The text files use comma-separated fields. User records follow this format:

```text
userId,username,password,name,email,allowAnonymousQuestions
```

Question records follow this format:

```text
questionId,parentQuestionId,fromUserId,toUserId,isAnonymous,questionText,answerText
```

A `parentQuestionId` of `-1` means the question starts a new thread. A blank answer means the question has not been answered.

## Current limitations

- Commas are not supported inside names, usernames, question text, or answers because commas separate file fields.
- Passwords are stored as plain text. This is a learning project, not a production authentication system.
- The program uses simple text files rather than a database.
- The menu system supports one login session per program run.

## Learning note

The inheritance and polymorphism example is intentionally kept small and visible in `Menu.h` and `Menu.cpp`. The project does not force an inheritance relationship between `User` and `Question`, because they represent different domain concepts rather than parent and child types.
