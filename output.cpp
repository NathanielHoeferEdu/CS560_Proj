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
        for (int i = 0; i < int(orig.size()); i++) {
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

void Output::output_to_csv(std::vector<std::vector<double> > &results, std::string filepath)
{
    std::ofstream output;
    output.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        output.open(filepath);
        output << "Array Type - Sort Type, 10, 100, 1000, 10000" << std::endl;
        output << "Increasing Array Type - Quicksort,";
        for (std::vector<double>::iterator i = results[0].begin(); i != results[0].end(); i++) {
            output << *i << ",";
        }
        output << "\nIncreasing Array Type - Random Quicksort,";
        for (std::vector<double>::iterator i = results[1].begin(); i != results[1].end(); i++) {
            output << *i << ",";
        }
        output << "\nRandom Array Type - Quicksort,";
        for (std::vector<double>::iterator i = results[2].begin(); i != results[2].end(); i++) {
            output << *i << ",";
        }
        output << "\nRandom Array Type - Random Quicksort,";
        for (std::vector<double>::iterator i = results[3].begin(); i != results[3].end(); i++) {
            output << *i << ",";
        }
    } catch (const std::ofstream::failure& e) {
        std::cout << "Exception opening/reading file";
    }
    output.close();
}
