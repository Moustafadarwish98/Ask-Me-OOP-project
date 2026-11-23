#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

// Abstract base class: every menu must display its options and report its size.
class Menu
{
public:
    virtual ~Menu();
    virtual void Display() const = 0;
    virtual int GetOptionCount() const = 0;
};

class LoginMenu : public Menu
{
public:
    void Display() const override;
    int GetOptionCount() const override;
};

class MainMenu : public Menu
{
public:
    void Display() const override;
    int GetOptionCount() const override;
};

// Demonstrates runtime polymorphism through a base-class reference.
int ReadMenuChoice(const Menu& menu);

#endif
