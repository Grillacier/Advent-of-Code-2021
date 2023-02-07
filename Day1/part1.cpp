#include <iostream>
#include <fstream>

int main()
{
    int count = 0;
    int nb;
    int tmp;
    std::ifstream inputFile;
    inputFile.open("input");

    if (inputFile.is_open())
    {
        std::string line;
        inputFile >> line;
        tmp = stoi(line);
        inputFile >> line;
        nb = stoi(line);

        while (!inputFile.eof())
        {
            if (nb > tmp)
            {
                count++;
            }
            tmp = nb;
            inputFile >> line;
            nb = stoi(line);
        }
        inputFile.close();
    }
    std::cout << count << std::endl;
    return count;
}