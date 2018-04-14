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

******************************************************************************/

#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include "quicksort.h"
#include "output.h"

int main()
{
    std::cout << "CS560 Project - Analyzing Quicksort Runtimes" << std::endl;
    int n = 0;
    int x = 0;
    int isRandomArray;
    int isQuickSort;

    // Prompt for generated array type
    do {
        std::string input;
        std::cout << "\nSelect an option [0,1]:" << std::endl;
        std::cout << "0. Increasing Order Array, 1. Random Array  ";
        std::cin >> input;
        isRandomArray = atoi(input.c_str());
    } while (isRandomArray != 0 && isRandomArray != 1);

    // Prompt for N
    do {
        std::string input;
        std::cout << "Number of integers: ";
        std::cin >> input;
        n = atoi(input.c_str());
    } while (n < 1);

    // Collect X if using increasing array
    if (!isRandomArray) {
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
        std::cout << "\nSelect an option [0,1]:" << std::endl;
        std::cout << "0. Random Quicksort, 1. Quicksort  ";
        std::cin >> input;
        isQuickSort = atoi(input.c_str());
    } while (isQuickSort != 0 && isQuickSort != 1);

    // Generate array
    std::vector<int> orig_arr;
    if (isRandomArray) {
        QuickSort::populate_random_array(orig_arr, n);
    } else {
        QuickSort::populate_increasing_array(orig_arr, n, x);
    }
    std::vector<int> sorted_arr = orig_arr;

    // Execute and time array sort
    std::clock_t start;
    start = std::clock();
    if (isQuickSort) {
        QuickSort::quicksort(sorted_arr);
    } else {
        QuickSort::rand_quicksort(sorted_arr);
    }
    double total_time = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
    std::cout << "\nTime: " << total_time << " ms" << std::endl;

    // Print results to file
    std::stringstream filename;
    filename << n << "N";
    if (isRandomArray) {
        filename << "_RandArr";
    } else {
        filename << "_" << x << "X_IncArr";
    }
    if (isQuickSort) {
        filename << "_QS.txt";
    } else {
        filename << "_RandQS.txt";
    }
    Output::output_arr_file(orig_arr, sorted_arr, filename.str());
    std::cout << "File " << filename.str() << " written.";

    printf("\n\n");
    return 0;
}
