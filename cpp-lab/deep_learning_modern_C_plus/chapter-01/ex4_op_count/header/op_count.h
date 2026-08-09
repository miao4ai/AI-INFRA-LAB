#pragma once

#include <cstddef>
#include <utility>
#include <vector>

// Number of algebraic operations performed by a routine.
struct OpCount {
    std::size_t multiplications = 0;
    std::size_t additions       = 0;
};

// Matrix product C = A * B, also reporting how many mults/adds it did.
//   returns { C, counts }
std::pair<std::vector<std::vector<double>>, OpCount>
product_counted(const std::vector<std::vector<double>>& A,
                const std::vector<std::vector<double>>& B);

// 2D valid convolution of A with a 3x3 kernel K, also reporting mults/adds.
//   returns { C, counts }
std::pair<std::vector<std::vector<double>>, OpCount>
convolution_counted(const std::vector<std::vector<double>>& A,
                    const std::vector<std::vector<double>>& K);
