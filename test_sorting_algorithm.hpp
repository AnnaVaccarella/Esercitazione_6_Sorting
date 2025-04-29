#pragma once

#include <gtest/gtest.h>
#include <vector>
#include "sorts.hpp"  // Include il file header dove hai dichiarato gli algoritmi BubbleSort e HeapSort

// Test per l'algoritmo BubbleSort
TEST(BubbleSortTest, SortsCorrectly) {
    std::vector<int> v = {5, 3, 8, 1, 2};
    bubbleSort(v);  // Esegui BubbleSort
    EXPECT_EQ(v, std::vector<int>({1, 2, 3, 5, 8}));  // Verifica che il vettore sia ordinato correttamente
}

// Test per l'algoritmo HeapSort
TEST(HeapSortTest, SortsCorrectly) {
    std::vector<int> v = {5, 3, 8, 1, 2};
    heapSort(v);  // Esegui HeapSort
    EXPECT_EQ(v, std::vector<int>({1, 2, 3, 5, 8}));  // Verifica che il vettore sia ordinato correttamente
}
