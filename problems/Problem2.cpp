//
// Created by John Ziamos on 02/12/2021.
//

#include <vector>
#include <iostream>

#include "Problem2.h"

Problem2::Problem2(vector<string> inputs) {
    this->inputs = inputs;
}

long Problem2::calculate_solution() {

    long height = 0;
    long forwardness = 0;
    long aim = 0;

    for (string s : inputs)
    {
        char first = s.at(0);
        long number = atol(s.substr(s.find(' ') + 1).c_str());

        std::cout << first << " " << number << std::endl;

        switch (first) {
            case 'f':
                forwardness += number;
                height -= number * aim;
                break;
            case 'u':
                aim -= number;
                break;
            case 'd':
                aim += number;
                break;
        }
    }


    return forwardness * height;
}
