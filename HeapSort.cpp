#include "HeapSort.h"

#include <utility>

namespace {
void heapify(std::vector<std::string>& words, int heapSize, int root) {
    while (true) {
        int largest = root;
        const int left = 2 * root + 1;
        const int right = 2 * root + 2;

        if (left < heapSize && words[left] > words[largest]) largest = left;
        if (right < heapSize && words[right] > words[largest]) largest = right;
        if (largest == root) return;

        std::swap(words[root], words[largest]);
        root = largest;
    }
}
}

void heapSort(std::vector<std::string>& words) {
    const int size = static_cast<int>(words.size());
    for (int root = size / 2 - 1; root >= 0; --root) {
        heapify(words, size, root);
    }
    for (int end = size - 1; end > 0; --end) {
        std::swap(words[0], words[end]);
        heapify(words, end, 0);
    }
}
