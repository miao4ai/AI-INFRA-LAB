#pragma once

#include <vector>

// 2D "valid" convolution (cross-correlation) of A with a 3x3 kernel K.
//   A: H x W   (rectangular 2D vector, H >= 3, W >= 3)
//   K: 3 x 3
//   returns C: (H-2) x (W-2)
std::vector<std::vector<double>> convolution(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& K);
