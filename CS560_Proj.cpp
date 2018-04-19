//==============================================================================
// CS 560 Project - Quicksort Analysis
//==============================================================================
/*
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Class: CS560 - Spring 2018
    Date: 4/14/2018

    Generates an array of values ranging from 1 to 10000 based on user input of
    the following:
    * N number of elements
    * Populating array with random values or
        increasing values [N+X, N+2X, N+3X, ..., N+NX]

    Then the generated array is timed while sorting using one of the following
    sorting algorithms from user input:
    * Quicksort
    * Random Quicksort

    The resulting arrays are printed to a file within the present working
    directory.

    If a filepath is passed in as a command argument, then a report of average
    runtimes will be generated of the four permutations of array value types
    and sorting algorithms using N=10, 100, 1000, 10000. The report will then
    be stored to that file name in CSV format.

******************************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
#include "quicksort.h"
#include "output.h"


int main(int argc, char *argv[])
{
    std::cout << "CS560 Project - Analyzing Quicksort Runtimes" << std::endl;
    int n = 0;
    int x = 0;
    ArrayType arrayType = ArrayType::NONE;
    SortType sortType = SortType::NONE;

    // Run average analysis and compile report if filepath provided as argument
    if (argc == 2) {
        std::cout << "Compiling report and writing to " << std::string(argv[1]) << "..." << std::endl;
        QuickSort::compile_report(std::string(argv[1]));
        exit(0);
    }

    // Prompt for generated array type
    do {
        std::string input;
        std::cout << "\nSelect an option [1,2]:" << std::endl;
        std::cout << "1. Increasing Order Array, 2. Random Array  ";
        std::cin >> input;
        if (input == "1") {
            arrayType = ArrayType::INCREASING;
        } else if (input == "2") {
            arrayType = ArrayType::RANDOM;
        }
    } while (arrayType == ArrayType::NONE);

    // Prompt for N
    do {
        std::string input;
        std::cout << "Number of integers: ";
        std::cin >> input;
        n = atoi(input.c_str());
    } while (n < 1);

    // Collect X if using increasing array
    if (arrayType == ArrayType::INCREASING) {
        do {
            std::string input;
            std::cout << "Value of X: ";
            std::cin >> input;
            x = atoi(input.c_str());
        } while (!x);
    }

    // Prompt for quicksort type
    do {
        std::string input;
        std::cout << "\nSelect an option [1,2]:" << std::endl;
        std::cout << "1. Random Quicksort, 2. Quicksort  ";
        std::cin >> input;
        if (input == "1") {
            sortType = SortType::RANDOM;
        } else if (input == "2") {
            sortType = SortType::STANDARD;
        }
    } while (sortType == SortType::NONE);

    // Generate array
    std::vector<int> orig_arr;
    QuickSort::populate_array(orig_arr, arrayType, n, x);
    std::vector<int> sorted_arr = orig_arr;

    // Execute and time array sort
    double total_time = QuickSort::calc_runtime(sorted_arr, sortType);
    std::cout << std::setprecision(4) << std::fixed << "\nTime: " << total_time << " ms" << std::endl;

    // Print results to file
    std::stringstream filename;
    filename << n << "N";
    if (arrayType == ArrayType::RANDOM) {
        filename << "_RandArr";
    } else if (arrayType == ArrayType::INCREASING) {
        filename << "_" << x << "X_IncArr";
    } else {
        std::cout << "Invalid Array Population Type.";
        exit(1);
    }
    if (sortType == SortType::STANDARD) {
        filename << "_QS.txt";
    } else if (sortType == SortType::RANDOM) {
        filename << "_RandQS.txt";
    } else {
        std::cout << "Invalid Sorting Type.";
        exit(1);
    }
    Output::output_arr_file(orig_arr, sorted_arr, filename.str());
    std::cout << "File " << filename.str() << " written.";

    printf("\n\n");
    return 0;
}
