/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Alejandro Botero    
11/27/23
QuickSelect 
*/
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> 

std::vector<int>::iterator medianofthree(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator mid) {
	int num_[] = {*low, *mid, *high};               // create an array with the three values and sort it            
	std::sort(std::begin(num_), std::end(num_));               
	
    return std::find(nums.begin(), nums.end(), num_[1]);         // find the iterator of the median value 
}

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    auto med = low + std::distance(low, high) / 2;                      
	
    std::vector<int>::iterator pivot = medianofthree(nums, low, high, med);      // choose the pivot using the median of three strategy
    std::iter_swap(pivot, high);                             
	
    pivot = high;                // pivot points to last value    
	
    std::vector<int>::iterator i = low;                     //iterator points to the 1st value
	std::vector<int>::iterator j = pivot - 1;               // iterator points to the 2nd to last value

	while (true) {                  // partitioning step
		while (*pivot > *i)                                
		{
			i++;                        //increment        
		} 
        while (*pivot < *j and low < j)      
		{
			j--;                  //decrement                           
		}
        if (i >= j) {           //if i passes j break
			break;
		}

		std::iter_swap(i, j);            // swap elements to maintain the partition                             
		i++;                                                                 
		j--;                                                   
	}
	std::iter_swap(i, pivot);                                 
	pivot = i;                                                 

	return pivot;                                            
}

int quick_select(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator median) {
	while (std::distance(low, high)>=0) {
		if (std::distance(low, high)<=10) {     // if the size of the partition is small perform std::sort
			std::sort(low, high+1);  
			return *median;
		}
		std::vector<int>::iterator pivot = hoarePartition(nums, low, high);           // choose a pivot 

		if (pivot==median) {         // check if the pivot is the median
			return *pivot;
		} else if (pivot>median) {      
			high = pivot-1;     // if the median is on the left side, update the high iterator
		} else {
			low = pivot+1; // if the median is on the right side, update the low iterator
		}
	}

	return -1;
}

int quickSelect(std::vector<int>& nums, int& duration) {
	std::vector<int>::iterator low = nums.begin();
	std::vector<int>::iterator high = nums.end() - 1;
	std::vector<int>::iterator median = low + std::distance(low, high) / 2;
	auto start = std::chrono::steady_clock::now();
	int num = quick_select(nums, low, high, median);        // Perform the quick_select algorithm            

	auto end = std::chrono::steady_clock::now();

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	return num;                   //return the median value                         

}
