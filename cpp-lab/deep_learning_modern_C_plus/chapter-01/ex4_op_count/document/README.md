# Chapter 01 — Exercise 4: Operation Count & Cost Comparison

## Problem

Rewrite `product` (Ex 2) and `convolution` (Ex 3) so that, in addition to the
result matrix, they **report how many multiplications and additions** they
performed internally. Then compare the computational cost of the two.

## Design

Return both the result and the counts together. We use a small struct for the
counts and `std::pair` to bundle it with the result matrix:

```cpp
struct OpCount {
    std::size_t multiplications = 0;
    std::size_t additions       = 0;
};

std::pair<std::vector<std::vector<double>>, OpCount>
product_counted(const std::vector<std::vector<double>>& A,
                const std::vector<std::vector<double>>& B);

std::pair<std::vector<std::vector<double>>, OpCount>
convolution_counted(const std::vector<std::vector<double>>& A,
                    const std::vector<std::vector<double>>& K);
```

## What counts as an operation

- Every `A[i][k] * B[k][j]` (or `A[..]*K[..]`) is **one multiplication**.
- Every time you add a product into an accumulator is **one addition**.

## Expected cost (sanity check your counts)

- **product** of `m×n` by `n×p`:
  - multiplications = `m * n * p`
  - additions      ≈ `m * p * (n - 1)`  (summing n products needs n-1 adds)
- **convolution** (valid, 3×3) of `H×W`:
  - output is `(H-2)×(W-2)`, each output does 9 mults and 8 adds
  - multiplications = `(H-2) * (W-2) * 9`
  - additions      = `(H-2) * (W-2) * 8`

## Goal

Print the result + counts for both, and discuss which is cheaper for given sizes.

## What to build

- `header/op_count.h` — `OpCount` struct + the two `*_counted` declarations
- `src/op_count.cpp`  — the implementations
- `app/main.cpp`      — run both, print results and multiplication/addition counts
