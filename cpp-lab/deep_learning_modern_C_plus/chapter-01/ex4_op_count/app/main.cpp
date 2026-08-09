#include "op_count.h"

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
    Matrix A = {
        {1, 2, 3},
        {4, 5, 6},
    };
    Matrix B = {
        { 7,  8},
        { 9, 10},
        {11, 12},
    };

    Matrix Aimg = {
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
        auto [C, pc] = product_counted(A, B);
        std::cout << "product result:\n";
        print(C);
        std::cout << "product: " << pc.multiplications << " mults, "
                  << pc.additions << " adds\n\n";

        auto [D, cc] = convolution_counted(Aimg, K);
        std::cout << "convolution result:\n";
        print(D);
        std::cout << "convolution: " << cc.multiplications << " mults, "
                  << cc.additions << " adds\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
