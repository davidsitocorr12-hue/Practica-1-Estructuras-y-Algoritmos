#include "Metrics.h"

#include <iomanip>
#include <iostream>

bool isSorted(const std::vector<std::string>& words) {
    for (std::size_t i = 1; i < words.size(); ++i)
        if (words[i - 1] > words[i]) return false;
    return true;
}

std::size_t vectorMemoryBytes(const std::vector<std::string>& words) {
    std::size_t bytes = words.capacity() * sizeof(std::string);
    for (const std::string& word : words) bytes += word.capacity() + 1;
    return bytes;
}

void printResult(const std::string& name, double milliseconds,
                 std::size_t memoryBytes, bool ordered) {
    std::cout << std::left << std::setw(18) << name
              << " tiempo: " << std::fixed << std::setprecision(3)
              << milliseconds << " ms"
              << " | memoria aprox.: " << memoryBytes / 1024.0 / 1024.0
              << " MiB | ordenado: " << (ordered ? "SI" : "NO") << '\n';
}
