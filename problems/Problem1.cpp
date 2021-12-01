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

    int ret = 0;
    long previous = 3000; // blah whatever
    for (int i = 0; i < dataLength - 2; i++)
    {
        long window = data[i] + data[i + 1] + data[i + 2];
        if (window > previous)
        {
            ++ret;
        }
        previous = window;
    }
    return ret;
}
