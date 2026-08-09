#include "convolution.h"

#include <stdexcept>

std::vector<std::vector<double>> convolution(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& K)
{
    // TODO(萌喵酱): implement 2D valid convolution
    //   1) H = A.size(); W = A[0].size();
    //   2) validate: A not empty, H >= 3, W >= 3, and K is 3x3
    //      (throw std::invalid_argument on bad input)
    //   3) output size: (H-2) x (W-2), initialized to 0.0
    //   4) for each output (i, j):
    //        C[i][j] = sum over di,dj in {0,1,2} of A[i+di][j+dj] * K[di][dj]
    //   5) return C
    (void)A;
    (void)K;
    return {};   // placeholder so it compiles
}
