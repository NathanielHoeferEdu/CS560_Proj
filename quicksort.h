#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

class QuickSort
{
public:

    int MAX_RANGE = 10000;

    /**
     * @brief Sorts an array using the quick sort method.
     *
     * @param arr: The array to be sorted.
     */
    static void quicksort(std::vector<int> &arr);

    /**
     * @brief Sorts an array using the random quick sort method.
     *
     * @param arr: The array to be sorted.
     */
    static void rand_quicksort(std::vector<int> &arr);

    /**
     * @brief Generates an array of values [N+X, N+2X, N+3X, ..., N+NX]
     *
     * @param n: Number of elements to be generated in the array.
     * @param x: Amount to increase the incremental elements.
     * @return Generated ordered array.
     */
    static vector<int> * increasing_array(int n, int x);

    /**
     * @brief Generates an array of random values from 0 to MAX_RANGE
     *
     * @param n: Number of elements to be generated in the array.
     * @return Generated random array.
     */
    static vector<int> * random_array(int n);

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
