#include "product.h"
#include <stdexcept>

std::vector<std::vector<double>> product(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B)
{
    // TODO(萌喵酱): implement matrix multiplication
    //   1) dimensions: m = A.size(); n = A[0].size(); p = B[0].size();
    //   2) (optional) validate that A[0].size() == B.size()
    //   3) allocate C as m x p, initialized to 0.0
    //   4) triple loop: C[i][j] += A[i][k] * B[k][j]
    //   5) return C
    std::size_t m = A.size();
    std::size_t n = A[0].size();
    std::size_t p = B.size();
    std::size_t q = B[0].size();

    if (n!=p){
        throw std::invalid_argument("A's columns size has to be equal to B's row size");
    }

   std::vector<std::vector<double>> C(m, std::vector<double>(q, 0.0));

    for (std::size_t i = 0; i < m; ++i) {
        for (std::size_t j = 0; j < q; ++j) {
            for (std::size_t k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }   
        }
    }

    
    return C;   // placeholder so it compiles
}
