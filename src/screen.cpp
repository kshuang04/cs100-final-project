#include "../header/screen.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

void Screen::displayTextSlowly(const std::string& text, int delayMilliseconds, int endDelayMilliseconds) 
{
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(endDelayMilliseconds));
}