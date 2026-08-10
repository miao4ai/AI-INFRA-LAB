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
    std::size_t H = A.size();

    // ---- validate input ----
    // A must have >= 3 rows and >= 3 cols. (H < 3 short-circuits before A[0],
    // so this stays safe even if A is empty.)
    if (H < 3 || A[0].size() < 3) {
        throw std::invalid_argument("convolution: A must be at least 3x3");
    }
    // K must be exactly 3x3. (K.size() != 3 short-circuits before K[0]/K[1]/K[2].)
    if (K.size() != 3 || K[0].size() != 3 || K[1].size() != 3 || K[2].size() != 3) {
        throw std::invalid_argument("convolution: K must be 3x3");
    }

    std::size_t W = A[0].size();   // safe now: A has >= 3 rows

    std::vector<std::vector<double>> C(H-2, std::vector<double>(W-2, 0.0));

    for (std::size_t i = 0; i < H - 2; ++i) {
        for (std::size_t j = 0; j < W - 2; ++j) {
            for (std::size_t di = 0; di < 3; ++di) {
                for (std::size_t dj = 0; dj < 3; ++dj) {
                    C[i][j] += A[i + di][j + dj] * K[di][dj];
                }
            }
        }
    }


    return C;   // placeholder so it compiles
}
