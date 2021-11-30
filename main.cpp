/*
 * Whoever you are reading this, this is just a java developer doing advent of
 * code in c++ cause.. why not? pls don't be horrified :p
 */


#include <iostream>
#include <string>
#include <vector>

#include "utils.h"


int
main(int argc, char **argv)
{
    char *input_file = argv[1];
    if (argc < 2)
    {
        std::cout << "Pls give input file." << std::endl;
        return -1;
    }

    std::vector<std::string> input = read_lines(input_file);

    for (const std::string& s : input)
    {
        std::cout << s << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
