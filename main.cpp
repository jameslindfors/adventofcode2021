#include <iostream>
#include <iomanip>
#include "solutions/dec1.cpp"
#include "solutions/dec2.cpp"
#include "solutions/dec3.cpp"

int main()
{
    std::cout << "--------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(58) << "🎅  Welcome to Advent of Code 2021! 🎄" << std::endl;
    std::cout << "--------------------------------------------------------------------" << std::endl;
    std::cout << day1Solution() << std::endl;
    std::cout << day2Solution() << std::endl;
    std::cout << day3Solution() << std::endl;
    std::cout << "--------------------------------------------------------------------" << std::endl;

    return 0;
}