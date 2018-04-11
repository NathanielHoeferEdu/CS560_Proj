#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "quicksort.h"

void QuickSort::quicksort(std::vector<int> &arr) {
    return QuickSort::quicksort(arr, 0, arr.size()-1);
}

void QuickSort::rand_quicksort(std::vector<int> &arr) {
    return QuickSort::rand_quicksort(arr, 0, arr.size()-1);
}

void QuickSort::populate_increasing_array(std::vector<int> &arr, int n, int x) {
    if (n < 1) {
        throw std::invalid_argument("n is not valid.");  // Invalid n
    }
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(n + (i * x));
    }
}

void QuickSort::populate_random_array(std::vector<int> &arr, int n) {
    if (n < 1) {
        throw std::invalid_argument("n is not valid.");  // Invalid n
    }
    srand(time(NULL));
    arr.clear();
    for (int i = 0; i < n; i++) {
        int val = rand() % QuickSort::MAX_RANGE;
        arr.push_back(val);
    }
}

int QuickSort::partition(std::vector<int> &arr, int p, int r) {
    int x = arr[p];
    int i = p;
    int j = r + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] <= x && i < j);
        do {
            j--;
        } while (arr[j] >= x && j >= i);
        if (i < j) {
            std::swap(arr[i], arr[j]);
        } else {
            break;
        }
    }
    std::swap(arr[p], arr[j]);
    return j;
}

void QuickSort::quicksort(std::vector<int> &arr, int p, int r) {
    if (p < r) {
        int q = QuickSort::partition(arr, p, r);
        QuickSort::quicksort(arr, p, q-1);
        QuickSort::quicksort(arr, q+1, r);
    }
}

int QuickSort::rand_partition(std::vector<int> &arr, int p, int r) {
    srand(time(NULL));
    int index = (rand() % (r-p)) + p;
    std::swap(arr[p], arr[index]);
    return QuickSort::partition(arr, p, r);
}

void QuickSort::rand_quicksort(std::vector<int> &arr, int p, int r) {
    if (p < r) {
        int q = QuickSort::rand_partition(arr, p, r);
        QuickSort::rand_quicksort(arr, p, q-1);
        QuickSort::rand_quicksort(arr, q+1, r);
    }
}


