#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <ctime>
#include "sorts.hpp"


// Funzioni di supporto


std::vector<int> generateRandomVector(int size) {
    std::vector<int> vec(size);
    for (int& val : vec)
        val = rand() % 100000;
    return vec;
}

std::vector<int> generateSortedVector(int size) {
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i)
        vec[i] = i;
    return vec;
}

std::vector<int> generateReversedVector(int size) {
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i)
        vec[i] = size - i;
    return vec;
}

template <typename SortFunc>
long long measureTime(SortFunc sortFunc, std::vector<int> vec) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(vec);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}


// Main


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <dimensione_vettore>\n";
        return 1;
    }

    int size = std::stoi(argv[1]);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    auto randomVec = generateRandomVector(size);
    auto sortedVec = generateSortedVector(size);
    auto reversedVec = generateReversedVector(size);

    // BubbleSort
    std::cout << "[BubbleSort]\n";
    std::cout << "  Random:    " << measureTime(bubbleSort, randomVec) << " µs\n";
    std::cout << "  Sorted:    " << measureTime(bubbleSort, sortedVec) << " µs\n";
    std::cout << "  Reversed:  " << measureTime(bubbleSort, reversedVec) << " µs\n\n";

    // HeapSort
    std::cout << "[HeapSort]\n";
    std::cout << "  Random:    " << measureTime(heapSort, randomVec) << " µs\n";
    std::cout << "  Sorted:    " << measureTime(heapSort, sortedVec) << " µs\n";
    std::cout << "  Reversed:  " << measureTime(heapSort, reversedVec) << " µs\n";

    return 0;
}
