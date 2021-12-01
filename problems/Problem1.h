//
// Created by John Ziamos on 01/12/2021.
//
#include <string>
using namespace std;

#ifndef ADVENTOFCODE_PROBLEM1_H
#define ADVENTOFCODE_PROBLEM1_H

class Problem1 {
public:
    Problem1(const vector<string> &inputs);
    long calculateSolution();

private:
    vector<long> inputs;
};


#endif //ADVENTOFCODE_PROBLEM1_H
