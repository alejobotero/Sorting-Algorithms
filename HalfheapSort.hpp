/*
CSCI335 Fall 2023
Assignment 2 – Sorting
Alejandro Botero    
11/27/23
HalfHeapSort 
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
using namespace std;

void percDown (std::vector<int>& heap, std::vector<int>::size_type hole ) { //performs a percolate down operation at a specific index (hole)
    if (heap.size() == 1 + hole * 2) {    // if there is only a left child
        if(heap[0] > heap[hole * 2]) {         // compare with the left child and swap if necessary
            heap[hole] = heap[hole * 2];
            hole = hole * 2 ;
        }
    }
    else if (hole > (heap.size() - 1)/ 2 ) { // if the index is beyond the last non-leaf node
        std::cout << " " << std::endl;    // no further action
    } else {    // continue the downward heap operation
        while (heap[0] > heap[hole * 2] || heap[0] > heap[1 + hole * 2]) {
            if(heap[hole * 2] <= heap[1 + hole * 2]) // if the left child is less than or equal to the right child
            {
                heap[hole] = heap[hole * 2];
                hole = hole * 2;
            } else { // if the right child is greater
                heap[hole] = heap[1 + hole * 2];
                hole = 1 + hole * 2;
            }
            if(hole > (heap.size() - 1)/ 2) { // check if the index is beyond the last non-leaf node
                break;
            }             
            if(heap.size() == 1 + hole * 2) { // if there's only a left child, handle it separately
                if(heap[0] > heap[hole * 2]) {
                    heap[hole] = heap[hole * 2];
                    hole = hole * 2;
                    break;
                } else {
                    break;
                }
            }
        }
    }
    heap[hole] = heap[0];     // set the original value at the correct position
}

void buildHeap (std::vector<int>& heap) {
    int node = (heap.size() - 1)/ 2;     // start from the last non-leaf node and perform percDown
    while(0 < node) {
        heap[0] = heap[node];
        percDown(heap, node);
        --node;
    }
}

int halfHeapSort (std::vector<int>& nums, int& duration ) {
    auto start = chrono::steady_clock::now();
    
    nums.push_back(nums[0]);     // duplicate the first element at the end and build the heap
    buildHeap(nums);
    
    int size = nums.size()/ 2 - 1;
    for(int i = 0; i < size; i++) {
        nums[0] = nums[nums.size()-1];      // swap the root with the last element and adjust the heap
        nums[1] = nums[nums.size()-1];
        nums.pop_back();
        percDown(nums, 1);
    }

    auto end = chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return nums[1];     // return the second smallest element 
}
