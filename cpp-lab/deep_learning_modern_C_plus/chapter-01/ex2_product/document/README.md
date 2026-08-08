# Chapter 01 — Exercise 2: Matrix Product

## Problem

Write a function that computes the **matrix product** of two rectangular 2D
matrices `A` and `B`, both represented as `std::vector<std::vector<double>>`.

```cpp
std::vector<std::vector<double>> product(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B);
```

## Definition

If `A` is an `m × n` matrix and `B` is an `n × p` matrix, then the product
`C = A × B` is an `m × p` matrix where each entry is:

```
C[i][j] = sum over k of ( A[i][k] * B[k][j] )    for k = 0 .. n-1
```

## Assumptions

- `A` and `B` are always rectangular (every row has the same length).
- The inner dimensions must match: **columns of A == rows of B**
  (i.e. `A[0].size() == B.size()`), otherwise the product is undefined.

## Example

```
A = [[1, 2, 3],       B = [[7,  8],          C = A × B = [[ 58,  64],
     [4, 5, 6]]            [9, 10],                       [139, 154]]
     (2 × 3)               [11,12]]                        (2 × 2)
                            (3 × 2)
```

## What to build

- `header/product.h` — the declaration
- `src/product.cpp`  — the implementation
- `app/main.cpp`     — a small driver that builds A, B, calls `product`, prints C
