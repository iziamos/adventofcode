//
// Created by John Ziamos on 01/12/2021.
//

#include <vector>
#include "Problem1.h"

Problem1::Problem1(const vector<string> &inputs)
{
    for (string input : inputs)
    {
        this->inputs.push_back(atol(input.c_str()));
    }
}

long Problem1::calculateSolution() {
    long previous = 3000; // blah whatever
    int count = 0;
    for (long l : inputs)
    {
        if (l > previous)
        {
            ++count;
        }
        previous = l;
    }

    return count;
}
