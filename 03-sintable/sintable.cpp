#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double pi = 3.141592653589793;

bool legal_int(char *str);

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Missing arguments" << '\n';
        std::cout << "Enter #samples(positive) #bits(positive) [OPTIONS]!" << '\n';
        return -1;
    }
    if (!((legal_int(argv[1]) && legal_int(argv[2]))))
    {
        std::cout << "Invalid arguments" << '\n';
        std::cout << "Enter #samples(positive) #bits(positive) [OPTIONS]!" << '\n';
        return -1;
    }

    uint32_t num_of_sample = std::stoi(argv[1]);
    uint32_t num_of_bit = std::stoi(argv[2]);
    uint32_t pos_range = pow(2, (num_of_bit - 1)) - 1;

    double coef = double((2 * pi) / num_of_sample);

    int x = 0;
    while (x < num_of_sample)
    {
        int sin_x = int(pos_range * sin(x * coef));
        int cosin_x = int(pos_range * cos(x * coef));
        std::cout << std::setw(10) << std::left << sin_x;
        if ((argc > 3) && (argv[3] == std::string("c")))
        {
            std::cout << " " << cosin_x;
        }
        std::cout << '\n';
        x++;
    }
}

bool legal_int(char *str)
{
    uint32_t index = 0;
    while (str[index] != 0)
    {
        if (!isdigit(str[index]))
        {
            return false;
        }
        index++;
    }
    return true;
}
