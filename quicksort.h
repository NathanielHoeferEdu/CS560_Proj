#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

struct SortTypes {
    enum Types {
        STANDARD,
        RANDOM,
        NONE
    };
};
typedef SortTypes::Types SortType;

struct ArrayTypes {
    enum Types {
        INCREASING,
        RANDOM,
        NONE
    };
};
typedef ArrayTypes::Types ArrayType;

class QuickSort
{
public:

    static const int MAX_RANGE;
    static const int TIMES_TO_RUN;
    static const int DEFAULT_X;
    static std::vector<int> N_VALS;

    /**
     * @brief Sorts an array using the quicksort method choosing the first element as pivot.
     *
     * @param arr: The array to be sorted.
     */
    static void quicksort(std::vector<int> &arr);

    /**
     * @brief Sorts an array using the quicksort method choosing a random element as pivot.
     *
     * @param arr: The array to be sorted.
     */
    static void rand_quicksort(std::vector<int> &arr);

    /**
     * @brief Modifies an existing array by populating it with values [N+X, N+2X, N+3X, ..., N+NX]
     *
     * @param arr: Array to be populated, preferrably empty.
     * @param n: Number of elements to be generated in the array.
     * @param x: Amount to increase the incremental elements.
     * @throws invalid_argument when n < 1
     */
    static void populate_increasing_array(std::vector<int> &arr, int n, int x);

    /**
     * @brief Modifies an existing array by populating it with randomly ordered values from 0 to MAX_RANGE
     *
     * @param arr: Array to be populated, preferrably empty.
     * @param n: Number of elements to be generated in the array.
     * @throws invalid_argument when n < 1
     */
    static void populate_random_array(std::vector<int> &arr, int n);

    /**
     * @brief Modifies an existing array by populating it with the specified values
     * @param arr: Array to be populated, preferrably empty.
     * @param arrayType: The type of array to be produced after being populated.
     * @param n: Number of elements.
     * @param x: Amount to increase the incremental elements if producing increasing array.
     */
    static void populate_array(std::vector<int> &arr, ArrayType arrayType, int n, int x);

    /**
     * @brief Calculates the runtime to sort an array with the specified sorting method.
     *
     * @param arr: Array to be sorted.
     * @param sortType: The sort method to use.
     * @return The runtime in milliseconds.
     */
    static double calc_runtime(std::vector<int> &arr, SortType sortType);

    /**
     * @brief Executes all permutations of quicksort and rand_quicksort using either increasing array or random array. The data is then stored in a CSV formatted file.
     *
     * @param filepath: File with CSV stored results.
     */
    static void compile_report(std::string filepath);

private:

    /**
     * @brief Sorts an array using the quick sort method.
     *
     * @param arr: The array to be sorted.
     * @param p: First index in the subarray.
     * @param r: Last index in the subarray.
     */
    static void quicksort(std::vector<int> &arr, int p, int r);

    /**
     * @brief Partitions a subarray in place, around first element.
     *
     * @param arr: The array to be partitioned.
     * @param p: First index in the subarray.
     * @param r: Last index in the subarray.
     * @return The final index of the pivot.
     */
    static int partition(std::vector<int> &arr, int p, int r);

    /**
     * @brief Sorts an array using the random quick sort method.
     *
     * @param arr: The array to be sorted.
     * @param p: First index in the subarray.
     * @param r: Last index in the subarray.
     */
    static void rand_quicksort(std::vector<int> &arr, int p, int r);

    /**
     * @brief Partitions a subarray in place, around a random element.
     *
     * @param arr: The array to be partitioned.
     * @param p: First index in the subarray.
     * @param r: Last index in the subarray.
     * @return The final index of the pivot.
     */
    static int rand_partition(std::vector<int> &arr, int p, int r);
};

#endif // QUICKSORT_H
