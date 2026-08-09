#include "op_count.h"

#include <stdexcept>

std::pair<std::vector<std::vector<double>>, OpCount>
product_counted(const std::vector<std::vector<double>>& A,
                const std::vector<std::vector<double>>& B)
{
    // TODO(萌喵酱): same as Ex2's product, but count operations.
    //   - increment count.multiplications on every A[i][k] * B[k][j]
    //   - increment count.additions every time you add a product into C[i][j]
    //   - return { C, count };
    OpCount count;
    (void)A;
    (void)B;
    return { {}, count };   // placeholder so it compiles
}

std::pair<std::vector<std::vector<double>>, OpCount>
convolution_counted(const std::vector<std::vector<double>>& A,
                    const std::vector<std::vector<double>>& K)
{
    // TODO(萌喵酱): same as Ex3's convolution, but count operations.
    //   - 9 multiplications and 8 additions per output cell
    //   - return { C, count };
    OpCount count;
    (void)A;
    (void)K;
    return { {}, count };   // placeholder so it compiles
}
