//
// Created by John Ziamos on 01/12/2021.
//

#include <vector>
#include "Problem1.h"
#include "../utils.h"

Problem1::Problem1(vector<string> inputs)
{
    this->inputs = inputs;
}

long Problem1::calculate_solution() {
    vector<long> things = strings_to_longs(inputs);

    long dataLength = things.size();
    long *data = things.data();

    vector<long> windows;
    windows.reserve(dataLength - 2);

    for (int i = 0; i < dataLength - 2; i++)
    {
        windows.push_back(data[i] + data[i + 1] + data[i + 2]);
    }

    long previous = 3000; // blah whatever
    int ret = 0;
    for (long w : windows)
    {
        if (w > previous)
        {
            ++ret;
        }
        previous = w;
    }
    return ret;
}
