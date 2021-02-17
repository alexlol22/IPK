#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int> reversed(const std::vector<int> &v)
{
    std::vector<int> result;
    for (std::size_t i = v.size(); i > 0; i--)
    {
        result.push_back(v[i-1]);
    }
    //0-1=overflow;
    return result;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    { //should be 2, since the executable is the 1st arg
        std::cerr << "Usage: " << argv[0] << " [number] [number]..." << std::endl;
        return 1;
    }
    std::cerr << "Reading in " << (argc - 1) << " numbers from stdin"
              << std::endl;
    std::vector<int> numbers;
    for (std::size_t i = 1; i < argc; ++i) //we dont want the executable in here, so start with 1
    {
        // atoi converts a string to a number
        int number = std::stoi(argv[i]);
        numbers.push_back(number);
    }

    std::cerr << "Reversing order of numbers" << std::endl;
    auto reverse = reversed(numbers);

    for (auto n : reverse)
        std::cout << n << std::endl;
}
