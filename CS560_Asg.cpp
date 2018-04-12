#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include "quicksort.h"

void print_arr(std::vector<int> &arr) {
    for (std::vector<int>::iterator i = begin(arr); i != end(arr); i++) {
        printf("%d, ", *i);
    }
}

int main()
{

    std::cout << "CS560 Project" << std::endl;
    int n = 0;
    int x = 0;
    int isRandomArray;
    int isQuickSort;

    // Prompt for generated array type
    do {
        std::string input;
        std::cout << "Select an option: \n0. Increasing Order Array, ";
        std::cout << "1. Random Array [0,1]: ";
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
        std::cout << "Select an option: \n0. Random Quicksort, ";
        std::cout << "1. Quicksort [0,1]: ";
        std::cin >> input;
        isQuickSort = atoi(input.c_str());
    } while (isQuickSort != 0 && isQuickSort != 1);

    // Generate array
    std::vector<int> int_arr;
    if (isRandomArray) {
        QuickSort::populate_random_array(int_arr, n);
    } else {
        QuickSort::populate_increasing_array(int_arr, n, x);
    }

    // Execute and time array sort
    std::clock_t start;
    start = std::clock();
    if (isQuickSort) {
        QuickSort::quicksort(int_arr);
    } else {
        QuickSort::rand_quicksort(int_arr);
    }
    double total_time = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
    std::cout << "Time: " << total_time << " ms" << std::endl;

    printf("\n\n");
    return 0;
}
