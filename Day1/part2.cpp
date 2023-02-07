#include <iostream>
#include <fstream>

int main()
{
    int count = 0;
    int current = 0;
    int prev = 0;
    int a, b;
    std::ifstream inputFile;
    inputFile.open("input");

    if (inputFile.is_open())
    {
        std::string line;

        inputFile >> line;
        prev += stoi(line);

        inputFile >> line;
        prev += stoi(line);
        current += stoi(line);

        inputFile >> line;
        prev += stoi(line);
        current += stoi(line);
        a = stoi(line);

        inputFile >> line;
        current += stoi(line);
        b = stoi(line);

        while (!inputFile.eof())
        {
            if (current > prev)
            {
                count++;
            }

            prev = current;
            current = 0;
            current = a + b;
            inputFile >> line;
            current += stoi(line);
            a = b;
            b = stoi(line);
        }
        inputFile.close();
    }
    std::cout << count << std::endl;
    return count;
}