//
// Created by John Ziamos on 03/12/2021.
//

#include <utility>
#include <vector>

#include "Problem3.h"

Problem3::Problem3(vector<string> inputs) {
    this->inputs = std::move(inputs);
}

int most_common_bit_bias_1(vector<string> inputs, int i)
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

    return g < e ? 0 : 1;
}

int most_common_bit_bias_0(const vector<string>& inputs, int i) //begging to be generalised but no time
{
    int g = 0;
    int e = 0;
    for (const string& s : inputs)
    {
        if (s.c_str()[i] == '0')
        {
            g++;
        }
        else
        {
            e++;
        }
    }

    return g > e ? 1 : 0;
}

string find_oxygen(vector<string> inputs, int pos)
{
    if (inputs.size() == 1)
    {
        return inputs.front();
    }

    const int i = most_common_bit_bias_1(inputs, pos);
    vector<string> filtered;

    for (const string& s : inputs)
    {
        if (s.c_str()[pos] == ('0' + i))
        {
            filtered.push_back(s);
        }
    }

    return find_oxygen(filtered, pos + 1); // lol this will break if solution is duplicate
}

string find_dioxyde(vector<string> inputs, int pos)
{
    if (inputs.size() == 1)
    {
        return inputs.front();
    }

    const int i = most_common_bit_bias_0(inputs, pos); // this is the real only diff with method above
    vector<string> filtered;

    for (const string& s : inputs)
    {
        if (s.c_str()[pos] == ('0' + i))
        {
            filtered.push_back(s);
        }
    }

    return find_dioxyde(filtered, pos + 1);
}

long Problem3::calculate_solution()
{
    string ox = find_oxygen(inputs, 0);
    string diox = find_dioxyde(inputs, 0);

    const long oxygen = std::stoi(ox, nullptr, 2);
    const long cotwo = std::stoi(diox, nullptr, 2);

    return oxygen * cotwo;
}

