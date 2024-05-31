/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Alejandro Botero    
11/27/23
HalfSelectionSort 
*/
#include <iostream>
#include <vector>
#include <chrono>

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::steady_clock::now();
    
    if (nums.size() > 50000) {     // Check if the vector size exceeds the limit
        std::cout << "Vector size exceeds the limit" << std::endl;
        return -1;
    }

    for (auto i = nums.begin(); i <= nums.begin() + ((nums.size() - 1) / 2); ++i) {     // Iterate through the vector, finding the smallest elements up to the median
        auto min = i;
        for (auto it = i + 1; it != nums.end(); ++it) {        // Find the minimum element in the unsorted portion
            if (*it < *min) {
                min = it;
            }
        }
        std::iter_swap(i, min);         // Swap the found minimum element with the current position
    }
    
    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return *(nums.begin() + (nums.size() - 1) / 2);     // Return the median value 

}
