#ifndef OUTPUT_H
#define OUTPUT_H

#include <vector>
#include <string>

class Output
{
public:

    /**
     * @brief Prints the elements of two arrays to a file along with the proper headers
     *
     * @param orig: The unsorted array.
     * @param sorted: The sorted array.
     * @param filepath: File path to store the file.
     */
    static void output_arr_file(std::vector<int> &orig, std::vector<int> &sorted, std::string filepath);

    /**
     * @brief Records results to a CSV file.
     *
     * @param The results from a running all four array and sorting type permutations over the various N times.
     */
    static void output_to_csv(std::vector< std::vector<double> > &results, std::string filepath);
};

#endif // OUTPUT_H
