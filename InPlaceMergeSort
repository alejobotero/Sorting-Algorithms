
/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Alejandro Botero    
11/27/23
InPlaceMergeSort
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

void inPlaceMergeSortImp(std::vector<int>::iterator left, std::vector<int>::iterator right) {
    if (right-left <= 1) {     // Base case: if the range has 1 or fewer elements, it is already sorted
        return;
    }
    auto center=left+(right-left) /2;     // Find the center of the range

    inPlaceMergeSortImp(left, center);     // Recursively sort the left and right halves
    inPlaceMergeSortImp(center, right);

    std::inplace_merge(left, center, right);     // Merge the sorted halves in-place
}

int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::steady_clock::now();

    inPlaceMergeSortImp(nums.begin(), nums.end());     // Call the recursive in-place merge sort function

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    return *(nums.begin()+(nums.size()-1) /2);     // Return the median value of the sorted vector
}
