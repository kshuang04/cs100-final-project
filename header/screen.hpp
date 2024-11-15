#ifndef SCREEN_HPP
#define SCREEN_HPP
#include <string>

class Screen
{
    protected:
    void displayTextSlowly(const std::string& text, int delayMilliseconds, int endDelayMilliseconds);

    public:
    virtual void printScreen() = 0;
};

#endif