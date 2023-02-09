#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

int main() {
    int count0 = 0;
    int count1 = 0;
    int gamma = 0;
    int epsilon = 0;
    std::ifstream inputFile;
    inputFile.open("input");

    if (inputFile.is_open()) {
        std::string line;
        std::getline(inputFile, line);
        int lineSize = line.size();
        int most[lineSize] = {};
        int least[lineSize] = {};
        if (line[0] == '1') {
            count1++;
        }
        else {
            count0++;
        }


        for (int i = 0; i < lineSize; ++i) {
            while (!inputFile.eof()) {
                std::getline(inputFile, line);
                if (line[i] == '1') {
                    count1++;
                }
                else {
                    count0++;
                }
            }
            if (count0 > count1) {
                most[i] = 0;
                least[i] = 1;
            }
            else {
                most[i] = 1;
                least[i] = 0;
            }

            count0 = 0;
            count1 = 0;
            inputFile.close();
            inputFile.open("input");
        }

        for (int a = 0; a < lineSize; ++a) {
            if (most[a] == 1)
                gamma += std::pow(2, lineSize-1-a);
            if (least[a] == 1)
                epsilon += std::pow(2,lineSize-1-a);
        }

        inputFile.close();
    }

    std::cout << gamma*epsilon << std::endl;
    return gamma*epsilon;
}