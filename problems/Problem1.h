//
// Created by John Ziamos on 01/12/2021.
//
#include <string>
using namespace std;

#ifndef ADVENTOFCODE_PROBLEM1_H
#define ADVENTOFCODE_PROBLEM1_H

class Problem1 {
public:
    explicit Problem1(vector<string> inputs);
    long calculate_solution();

private:
    vector<string> inputs;
};


#endif //ADVENTOFCODE_PROBLEM1_H
