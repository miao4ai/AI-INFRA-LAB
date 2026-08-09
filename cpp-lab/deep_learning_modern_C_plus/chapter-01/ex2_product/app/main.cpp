#include "product.h"

#include <iostream>
#include <stdexcept>
#include <vector>

using Matrix = std::vector<std::vector<double>>;

// Print a matrix, one row per line.
static void print(const Matrix& M) {
    for (const auto& row : M) {
        for (double x : row) {
            std::cout << x << '\t';
        }
        std::cout << '\n';
    }
}

int main() {
    // A: 2x3, B: 3x2  ->  expected C = [[58, 64], [139, 154]]
    Matrix A = {
        {1, 2, 3},
        {4, 5, 6},
    };
    Matrix B = {
        { 7,  8},
        { 9, 10},
        {11, 12},
    };

    try {
        Matrix C = product(A, B);
        std::cout << "A * B =\n";
        print(C);
    } catch (const std::invalid_argument& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
