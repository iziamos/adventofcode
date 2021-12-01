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
    vector<long> s;

    int dataLength = inputs.size();
    long *data = inputs.data();

    for (int i = 0; i < dataLength - 2; i++)
    {
        s.push_back(data[i] + data[i + 1] + data[i + 2]);
    }


    long previous = 3000; // blah whatever
    int count = 0;
    for (long l : s)
    {
        if (l > previous)
        {
            ++count;
        }
        previous = l;
    }

    return count;
}
