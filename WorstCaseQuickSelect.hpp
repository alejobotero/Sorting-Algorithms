/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Alejandro Botero    
11/27/23
WorstCaseQuickSelect
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>& worstCaseQuickSelect(){
    int size = 20000;   // Define the size of the vector
    int halfsize = (size)/2;    // Calculate the half size
    static std::vector<int> worse(size);    // Static vector to store the worst-case scenario
    std::vector<int>::iterator start = worse.begin();   // Iterator for the beginning of the vector
    std::vector<int>::iterator center = worse.begin() + halfsize;   // Iterator for the middle of the vector
    std::vector<int>::iterator end = worse.end() - 1;   // Iterator for the end of the vector
    
    for(int i = 0; i < halfsize; ++i){
        if(i % 2 == 0){     // Alternate between consecutive odd and even numbers in the middle of the vector
            *(center + i) = i + 1;
        }else{
            *(center + i) = halfsize + i;
        }
        *(start + i) = (i + 1) * 2; // Fill the beginning of the vector with consecutive even numbers
    }

    return worse;       // Return the worst case vector
}
