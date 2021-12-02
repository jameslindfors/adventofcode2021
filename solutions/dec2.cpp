#include <iostream>
#include <fstream>
#include <vector>

std::vector<uint16_t> horizontalValues;
std::vector<int16_t> depthValues;
std::vector<std::string> totalValues;

void filterDataToVec() {
    std::ifstream input("./solutions/input/dec2input.txt");
    if (input.is_open()){   
    for (std::string line; std::getline(input, line);) {
        totalValues.push_back(line);
        if (line.find("forward") != std::string::npos){
            std::string number = line.substr(line.find("forward") + 7);
            horizontalValues.push_back(std::stoi(number));
        } else if (line.find("up") != std::string::npos) {
            std::string number = line.substr(line.find("up") + 3);
            depthValues.push_back(std::stoi(number.insert(0, "-").c_str()));
        } else if (line.find("down") != std::string::npos){
            std::string number = line.substr(line.find("down") + 4);
            depthValues.push_back(std::stoi(number));
        }
    }
    input.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        input.close();
    }
}

int day2Part1() {
    filterDataToVec();

    int horPos = 0;
    int depPos = 0;

    for (int i: horizontalValues) {
        horPos += i;
    }
    for (int i: depthValues) {
        depPos += i;
    }

    return horPos * depPos;
}

int day2Part2() {
    int horPos = 0;
    int depPos = 0;
    int aim = 0;

    for (int x = 0; x < totalValues.size(); x++) {
        if (totalValues[x].find("forward") != std::string::npos){
            std::string number = totalValues[x].substr(totalValues[x].find("forward") + 7);
            horPos += std::stoi(number);
            depPos += aim * std::stoi(number);
        } else if (totalValues[x].find("up") != std::string::npos) {
            std::string number = totalValues[x].substr(totalValues[x].find("up") + 3);
            aim += std::stoi(number.insert(0, "-").c_str());
        } else if (totalValues[x].find("down") != std::string::npos){
            std::string number = totalValues[x].substr(totalValues[x].find("down") + 4);
            aim += std::stoi(number);
        }
    }

    return horPos * depPos;
}

std::string day2Solution() {
    return "🎁 December 2: Part 1: " + std::to_string(day2Part1()) + " ⭐  " + "Part 2: " + std::to_string(day2Part2()) + " ⭐";
}