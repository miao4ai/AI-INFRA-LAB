#include "convolution.h"

#include <iostream>
#include <stdexcept>
#include <vector>

using Matrix = std::vector<std::vector<double>>;

static void print(const Matrix& M) {
    for (const auto& row : M) {
        for (double x : row) {
            std::cout << x << '\t';
        }
        std::cout << '\n';
    }
}

int main() {
    // A: 4x4, K: 3x3  ->  C is 2x2
    Matrix A = {
        {1, 2, 3, 0},
        {4, 5, 6, 1},
        {7, 8, 9, 2},
        {1, 0, 1, 3},
    };
    Matrix K = {
        {1, 0, -1},
        {1, 0, -1},
        {1, 0, -1},
    };

    try {
        Matrix C = convolution(A, K);
        std::cout << "conv(A, K) =\n";
        print(C);
    } catch (const std::invalid_argument& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
