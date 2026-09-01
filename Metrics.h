#ifndef METRICS_H
#define METRICS_H

#include <cstddef>
#include <string>
#include <vector>

bool isSorted(const std::vector<std::string>& words);
std::size_t vectorMemoryBytes(const std::vector<std::string>& words);
void printResult(const std::string& name, double milliseconds,
                 std::size_t memoryBytes, bool ordered);

#endif
