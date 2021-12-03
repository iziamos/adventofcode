//
// Created by John Ziamos on 03/12/2021.
//

#include <vector>
#include <iostream>


#include "Problem3.h"

Problem3::Problem3(vector<string> inputs) {
    this->inputs = inputs;
}

long array_of_binary_to_long(int *in, int size)
{
    long ret = 0;
    for (int i = 0; i < size; ++i)
    {
        ret += in[i] << (size - 1 - i);
    }

    return ret;
}

long Problem3::calculate_solution() {


    // gamma is when more 1, epsilon when more 0
    const int length = inputs.front().length();
    int *gt = (int *) calloc(length, sizeof(int));
    int *et = (int *) calloc(length, sizeof(int));

    const long input_size = inputs.size();

    for (int i = 0; i < length; ++i)
    {
        int g = 0;
        int e = 0;
        for (const string& s : inputs)
        {
            if (s.c_str()[i] == '1')
            {
                g++;
            }
            else
            {
                e++;
            }
        }

        gt[i] = g > e ? 1 : 0;
        et[i] = g < e ? 1 : 0; // no bit shit cuz lazy
    }

    const long gamma = array_of_binary_to_long(gt, length);
    const long epsilon = array_of_binary_to_long(et, length);

    const long consumption = gamma * epsilon;

    return consumption;
}

