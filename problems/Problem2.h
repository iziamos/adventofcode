//
// Created by John Ziamos on 02/12/2021.
//

#ifndef ADVENTOFCODE_PROBLEM2_H
#define ADVENTOFCODE_PROBLEM2_H

#include <string>
using namespace std;


class Problem2 {
public:
    explicit Problem2(vector<string> inputs);
    long calculate_solution();

private:
    vector<string> inputs;
};


#endif //ADVENTOFCODE_PROBLEM2_H
