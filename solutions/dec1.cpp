#include <iostream>
#include <vector>
#include <fstream>

std::vector<uint16_t> SONAR_VALUES;

void readSonarValues() {
    std::ifstream input("solutions/input/dec1input.txt");
    if (input.is_open()){   
    // Loop through the file with a for loop
    for (std::string line; std::getline(input, line);) {
        // Convert the string to an int
        uint16_t value = std::stoi(line);
        // Add the value to the vector
        SONAR_VALUES.push_back(value);
    }
    input.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        input.close();
    }
}

int day1Part1() {
    readSonarValues();

    uint16_t increased = 0;

    for (uint16_t i = 0; i < SONAR_VALUES.size(); ++i) {
        if (SONAR_VALUES[i] > SONAR_VALUES[i-1]) {
            increased += 1;
        }
    }
    return increased;
}

int day1Part2() {
    uint16_t increasedWindow = 0;
    uint16_t SIZE = SONAR_VALUES.size()-3;
    uint32_t sum = 0;
    uint32_t prevSum=0;

    for (uint16_t i = 0; i < SIZE; ++i) {
        sum = SONAR_VALUES.at(i) + SONAR_VALUES.at(i+1) + SONAR_VALUES.at(i+2);

        if (prevSum < sum) {
            increasedWindow += 1;
            prevSum = sum;
            sum = 0;
        } else if (sum == prevSum) {
            prevSum = sum;
            sum = 0;
        } else if (sum < prevSum) {
            prevSum = sum;
            sum = 0;
        }
    }

    return increasedWindow;
}

std::string day1Solution() {
    return "✨ December 1: Part 1: " + std::to_string(day1Part1()) + " ⭐  " + "Part 2: " + std::to_string(day1Part2()) + " ⭐";
}