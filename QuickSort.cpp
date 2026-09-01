#include "QuickSort.h"

#include <utility>

namespace {
int partition(std::vector<std::string>& words, int low, int high) {
    const int middle = low + (high - low) / 2;
    std::swap(words[middle], words[high]);
    const std::string pivot = words[high];
    int smaller = low - 1;

    for (int current = low; current < high; ++current) {
        if (words[current] <= pivot) {
            ++smaller;
            std::swap(words[smaller], words[current]);
        }
    }
    std::swap(words[smaller + 1], words[high]);
    return smaller + 1;
}

void quickSortRecursive(std::vector<std::string>& words, int low, int high) {
    while (low < high) {
        const int pivot = partition(words, low, high);
        // Recorrer primero la parte pequena limita la pila a O(log n).
        if (pivot - low < high - pivot) {
            quickSortRecursive(words, low, pivot - 1);
            low = pivot + 1;
        } else {
            quickSortRecursive(words, pivot + 1, high);
            high = pivot - 1;
        }
    }
}
}

void quickSort(std::vector<std::string>& words) {
    if (!words.empty()) {
        quickSortRecursive(words, 0, static_cast<int>(words.size()) - 1);
    }
}
