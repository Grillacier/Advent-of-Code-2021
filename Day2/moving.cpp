#include <iostream>
#include <fstream>

int main()
{
    std::string direction;
    int steps;
    int x = 0;
    int y = 0;
    std::ifstream inputFile;
    inputFile.open("input");

    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            std::getline(inputFile, direction);
            steps = (int) direction[direction.size()-1] - 48;
            if (direction[0] == 'f')
            {
                x += steps;
            }
            else if (direction[0] == 'd')
            {
                y += steps;
            }
            else if (direction[0] == 'u')
            {
                y -= steps;
            }
        }
        inputFile.close();
    }
    std::cout << x*y << std::endl;
    return x*y;
}