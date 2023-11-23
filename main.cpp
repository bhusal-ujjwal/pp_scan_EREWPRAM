#include <iostream>
#include <vector>
#include <../omp.h>

void prefixScan(std::vector<int>& input) {
    int numThreads = omp_get_num_threads();
    int numElements = input.size();

    // Perform the EREW PRAM prefix scan algorithm
    for (int d = 1; d < numElements; d *= 2) {
        #pragma omp parallel for num_threads(numThreads)
        for (int i = d; i < numElements; i++) {
            input[i] += input[i - d];
        }
    }
}

int main() {
    int N; // Number of elements
    int numThreads; // Number of threads

    // Read input from the user
    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    std::cout << "Enter the number of threads: ";
    std::cin >> numThreads;

    // Set the number of threads for OpenMP
    omp_set_num_threads(numThreads);

    // Generate the input array
    std::vector<int> input(N);
    for (int i = 0; i < N; i++) {
        input[i] = i + 1;
    }

    // Perform the prefix scan
    prefixScan(input);

    // Print the result
    std::cout << "Prefix scan result:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
