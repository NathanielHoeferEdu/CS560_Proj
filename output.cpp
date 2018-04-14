#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "output.h"

void Output::output_arr_file(std::vector<int> &orig, std::vector<int> &sorted, std::string filepath)
{
    std::ofstream output;
    output.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        // TODO - Make output and formatting more dynamic.
        output.open(filepath);
        output << "=======   ========   ========" << std::endl;
        output << "Elem      Original   Sorted  " << std::endl;
        output << "=======   ========   ========" << std::endl;
        for (int i = 0; i < orig.size(); i++) {
            std::stringstream elem;
            elem << "[" << i << "]";
            output << std::setw(10) << std::left << elem.str();
            output << std::setw(11) << orig[i];
            output << sorted[i] << std::endl;
        }
    } catch (const std::ofstream::failure& e) {
        std::cout << "Exception opening/reading file";
    }
    output.close();
}
