/*
 * Whoever you are reading this, this is just a java developer doing advent of
 * code in c++ cause.. why not? pls don't be horrified :p
 */


#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "problems/Problem1.h"
#include "problems/Problem2.h"
#include "problems/Problem3.h"


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

//    Problem1 problem = Problem1(input);
//    Problem2 problem = Problem2(input);
    Problem3 problem = Problem3(input);

    long solution = problem.calculate_solution();

    std::cout << "The answer maaay be: " << solution << std::endl;
    return 0;
}
