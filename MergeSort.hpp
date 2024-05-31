
/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Alejandro Botero    
11/27/23
MergeSort 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

void mergeSort (std::vector<int>& nums){
    if(nums.size() <= 1){     // Base case: if the vector has 1 or fewer elements, it is already sorted
        return;
    }
        int center = nums.size()/2;     // Find the center of the vector

        std::vector<int> left(nums.begin(), nums.begin() + center);    // Create left and right sub-vectors
        std::vector<int> right(nums.begin() + center, nums.end());

        mergeSort(left);     // Recursively apply merge sort to left and right sub-vectors
        mergeSort(right);
        std::merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin());     // Merge the sorted left and right sub-vectors
}

int mergeSort (std::vector<int>& nums, int& duration){
    auto start = std::chrono::steady_clock::now();
    mergeSort(nums);
    
    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    return *(nums.begin() + (nums.size() - 1)/2);     // Return the median value of the sorted vector
}
