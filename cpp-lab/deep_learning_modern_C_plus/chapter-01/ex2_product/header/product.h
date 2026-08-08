#pragma once

#include <vector>

// Matrix product C = A * B.
//   A: m x n   (rectangular 2D vector)
//   B: n x p   (rectangular 2D vector)
//   returns C: m x p
// Precondition: A's column count == B's row count (A[0].size() == B.size()).
std::vector<std::vector<double>> product(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B);
