#ifndef DATASET_MANAGER_H
#define DATASET_MANAGER_H

#include <cstddef>
#include <string>
#include <vector>

std::vector<std::string> createDataset(const std::string& sourceFile,
                                       const std::string& datasetFile,
                                       std::size_t count);
void writeWords(const std::string& filename,
                const std::vector<std::string>& words);

#endif
