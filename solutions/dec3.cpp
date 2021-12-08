#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <array>

const uint8_t BITS = 12;

std::vector<std::bitset<BITS>> binaryData;
std::vector<std::string> binaryDataStr;

void calculateRate(std::string &, std::string &);
void filterBinaryStrings(u_int32_t &, u_int32_t &);

void analyzeData()
{
    std::ifstream input("./solutions/input/dec3input.txt");
    if (input.is_open())
    {
        for (std::string line; std::getline(input, line);)
        {
            binaryData.push_back(std::bitset<BITS>(line));
            binaryDataStr.push_back(line);
        }
        input.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
        input.close();
    }
}

uint32_t day3Part1()
{
    analyzeData();

    std::string gammaRate, epsilonRate;
    calculateRate(gammaRate, epsilonRate);

    uint32_t powerConsumption = std::stoul(gammaRate, nullptr, 2) * std::stoul(epsilonRate, nullptr, 2);

    return powerConsumption;
}

int day3Part2()
{
    uint32_t
        oxygenGenRating = 5,
        co2ScrubRating = 5;

    filterBinaryStrings(oxygenGenRating, co2ScrubRating);

    return oxygenGenRating * co2ScrubRating;
}

// ❄️

std::string day3Solution()
{
    return "❄️  December 3: Part 1: " + std::to_string(day3Part1()) + " ⭐  " + "Part 2: " + std::to_string(day3Part2()) + " ⭐";
}

void calculateRate(std::string &gammaRate, std::string &epsilonRate)
{
    for (int i = 0; i < binaryDataStr[i].size(); i++)
    {
        int zeroCount = 0;
        int oneCount = 0;

        for (int j = 0; j < binaryDataStr.size(); j++)
        {
            if (binaryDataStr[j][i] == '0')
            {
                zeroCount++;
            }
            else if (binaryDataStr[j][i] == '1')
            {
                oneCount++;
            }
        }

        if (oneCount > zeroCount)
        {
            gammaRate += ('1');
            epsilonRate += ('0');
        }
        else if (oneCount < zeroCount)
        {
            gammaRate += ('0');
            epsilonRate += ('1');
        }
        // reset the counters
        zeroCount = 0;
        oneCount = 0;
    }
}

void filterBinaryStrings(uint32_t &oxygenGenRating, uint32_t &co2ScrubRating)
{
    std::bitset<BITS> oxygen_generator_rating;

    std::vector<std::bitset<BITS>> most_common(binaryData);

    for (int i = BITS - 1; most_common.size() > 1 && i >= 0; i--)
    {
        std::array<std::vector<std::bitset<BITS>>, 2> filtered;
        for (auto diagnostic : most_common)
        {
            filtered[diagnostic[i]].push_back(diagnostic);
        }
        most_common = filtered[0].size() > filtered[1].size() ? filtered[0] : filtered[1];
    }
    oxygen_generator_rating = most_common.at(0);
    oxygenGenRating = oxygen_generator_rating.to_ulong();

    std::bitset<BITS> co2_scrubber_rating;

    std::vector<std::bitset<BITS>> least_common(binaryData);

    for (int i = BITS - 1; least_common.size() > 1 && i >= 0; i--)
    {
        std::array<std::vector<std::bitset<BITS>>, 2> filtered;
        for (auto diagnostic : least_common)
        {
            filtered[diagnostic[i]].push_back(diagnostic);
        }
        least_common = filtered[0].size() > filtered[1].size() ? filtered[1] : filtered[0];
    }

    co2_scrubber_rating = least_common.at(0);
    co2ScrubRating = co2_scrubber_rating.to_ulong();
}
