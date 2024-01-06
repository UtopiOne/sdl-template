#include "Helpers/CSVParser.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<int>> ParseCsv(const std::string path)
{
    std::vector<std::vector<int>> result {};
    std::string line;
    std::ifstream file(path);

    while (getline(file, line))
    {
        if (line.find_first_of("0123456789") == std::string::npos)
            continue;

        int itmp;
        std::vector<int> tmp;
        std::stringstream ss(line);
        while (ss >> itmp)
        {
            std::string tmpstr;
            tmp.push_back(itmp);
            if (!getline(ss, tmpstr, ','))
            {
                break;
            }
        }

        result.push_back(tmp);
    }

    return result;
}
