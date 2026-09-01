#include "DatasetManager.h"

#include <algorithm>
#include <fstream>
#include <random>
#include <stdexcept>

void writeWords(const std::string& filename,
                const std::vector<std::string>& words) {
    std::ofstream output(filename);
    if (!output) throw std::runtime_error("No se pudo crear: " + filename);
    for (const std::string& word : words) output << word << '\n';
}

std::vector<std::string> createDataset(const std::string& sourceFile,
                                       const std::string& datasetFile,
                                       std::size_t count) {
    std::ifstream input(sourceFile);
    if (!input) throw std::runtime_error("No se pudo abrir: " + sourceFile);

    // Reservoir sampling selecciona exactamente count palabras sin repeticion.
    std::vector<std::string> sample;
    sample.reserve(count);
    std::mt19937 generator(std::random_device{}());
    std::string word;
    std::size_t seen = 0;

    while (std::getline(input, word)) {
        if (!word.empty() && word.back() == '\r') word.pop_back();
        if (word.empty()) continue;
        ++seen;
        if (sample.size() < count) sample.push_back(word);
        else {
            std::uniform_int_distribution<std::size_t> distribution(0, seen - 1);
            const std::size_t position = distribution(generator);
            if (position < count) sample[position] = word;
        }
    }
    if (sample.size() < count) {
        throw std::runtime_error("Se requieren " + std::to_string(count) +
                                 " palabras, pero el archivo no tiene suficientes.");
    }
    std::shuffle(sample.begin(), sample.end(), generator);
    writeWords(datasetFile, sample);
    return sample;
}
