#include <iostream>
#include <vector>
#include "quicksort.h"

void print_arr(std::vector<int> &arr) {
    for (std::vector<int>::iterator i = begin(arr); i != end(arr); i++) {
        printf("%d, ", *i);
    }
}

int main()
{
    std::vector<int> inc_v;
    QuickSort::populate_increasing_array(inc_v, 5, 2);
    printf("Increasing Array:\n");
    printf("Unsorted: ");
    print_arr(inc_v);
    QuickSort::quicksort(inc_v);
    printf("\nSorted: ");
    print_arr(inc_v);

    std::vector<int> rand_v;
    QuickSort::populate_random_array(rand_v, 5);
    printf("\n\nRandom Array:\n");
    printf("Unsorted: ");
    print_arr(rand_v);
    QuickSort::rand_quicksort(rand_v);
    printf("\nSorted: ");
    print_arr(rand_v);

    printf("\n\n");
    return 0;
}
