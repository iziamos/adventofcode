//
// Created by John Ziamos on 01/12/2021.
//

#ifndef ADVENTOFCODE_PROBLEM1_H
#define ADVENTOFCODE_PROBLEM1_H

#include <string>
using namespace std;

class Problem1 {
public:
    explicit Problem1(vector<string> inputs);
    long calculate_solution();

private:
    vector<string> inputs;
};


#endif //ADVENTOFCODE_PROBLEM1_H
