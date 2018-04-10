#include <iostream>
#include <vector>
#include "quicksort.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    std::vector<int> v = {6, 4, 2, 3, 5, 100, -2, -4, 0, 10, 1000, -50, -4, 20};
    QuickSort::rand_quicksort(v);
    for (int i = 0; i < v.size(); i++) {
        printf("%d, ", v[i]);
    }
    printf("\n");
    return 0;
}
