#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

class QuickSort
{
public:

    const static int MAX_RANGE = 10000;

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
