//
// Created by John Ziamos on 30/11/2021.
//

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> read_lines(char * filename)
{
    std::fstream file_stream;
    std::ifstream ifs(filename);
    std::string str((std::istreambuf_iterator<char>(ifs)),
                    (std::istreambuf_iterator<char>()));

    std::stringstream strm(str);

    std::vector<std::string> ret;
    std::string t;
    while(std::getline(strm, t, '\n'))
    {
        ret.push_back(t);
    }

    return ret;
}

std::vector<long> strings_to_longs(std::vector<std::string> strings)
{
    std::vector<long> ret;
    ret.reserve(strings.size());
    for (const std::string& s : strings)
    {
        ret.push_back(atol(s.c_str()));
    }
    return ret;
}