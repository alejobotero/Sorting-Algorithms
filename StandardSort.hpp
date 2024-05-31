/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Alejandro Botero    
11/27/23
StandardSort
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

int standardSort(std::vector<int>& nums, int& duration){
    auto start = std::chrono::steady_clock::now();     // Start the timer
    std::sort(nums.begin(), nums.end());     // Use std::sort to perform sorting on the vector

    auto end = std::chrono::steady_clock::now();     // Stop the timer
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();      // Calculate the execution time
    
    return *(nums.begin() + (nums.size() - 1)/2);     // Return the median value of the sorted vector
}
