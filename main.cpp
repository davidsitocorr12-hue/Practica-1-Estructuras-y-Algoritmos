#include "AVLTree.h"
#include "DatasetManager.h"
#include "HeapSort.h"
#include "Metrics.h"
#include "QuickSort.h"

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using Clock = std::chrono::steady_clock;
constexpr std::size_t DATASET_SIZE = 100000;

int main(int argc, char* argv[]) {
    try {
        const std::string source = argc > 1 ? argv[1] : "words_alpha.txt";
        const std::string datasetFile = argc > 2 ? argv[2] : "dataset.txt";
        const std::size_t count = argc > 3 ? std::stoull(argv[3]) : DATASET_SIZE;

        const std::vector<std::string> original =
            createDataset(source, datasetFile, count);
        std::cout << "Dataset creado: " << original.size() << " palabras\n\n";

        std::vector<std::string> quick = original;
        auto start = Clock::now();
        quickSort(quick);
        const double quickMs =
            std::chrono::duration<double, std::milli>(Clock::now() - start).count();
        writeWords("sorted_quicksort.txt", quick);
        printResult("QuickSort", quickMs, vectorMemoryBytes(quick), isSorted(quick));

        std::vector<std::string> heap = original;
        start = Clock::now();
        heapSort(heap);
        const double heapMs =
            std::chrono::duration<double, std::milli>(Clock::now() - start).count();
        writeWords("sorted_heapsort.txt", heap);
        printResult("HeapSort", heapMs, vectorMemoryBytes(heap), isSorted(heap));

        AVLTree tree;
        start = Clock::now();
        for (const std::string& word : original) tree.insert(word);
        const std::vector<std::string> avl = tree.getSorted();
        const double avlMs =
            std::chrono::duration<double, std::milli>(Clock::now() - start).count();
        writeWords("sorted_avl.txt", avl);
        printResult("AVL + inorder", avlMs,
                    tree.estimatedMemoryBytes() + vectorMemoryBytes(avl),
                    isSorted(avl));

        if (quick.size() != count || heap.size() != count || avl.size() != count)
            throw std::runtime_error("Un algoritmo perdio elementos del dataset.");
        if (quick != heap || quick != avl)
            throw std::runtime_error("Los tres resultados no coinciden.");

        std::cout << "\nVerificacion final: resultados iguales y correctamente ordenados.\n";
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
