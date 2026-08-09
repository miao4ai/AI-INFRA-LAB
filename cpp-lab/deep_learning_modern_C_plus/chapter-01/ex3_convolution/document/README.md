# Chapter 01 — Exercise 3: 2D Convolution

## Problem

Write a function that computes the **2D convolution** of a rectangular matrix `A`
with a **3×3 kernel** `K`, both `std::vector<std::vector<double>>`.

```cpp
std::vector<std::vector<double>> convolution(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& K);   // K is 3x3
```

## Definition (valid convolution)

Slide the 3×3 kernel over `A`. For each position `(i, j)` of the output, multiply
the 3×3 window of `A` (top-left corner at `A[i][j]`) element-wise with `K` and sum:

```
C[i][j] = sum over (di, dj) in {0,1,2} of ( A[i+di][j+dj] * K[di][dj] )
```

> Note: this element-wise slide-and-sum is technically *cross-correlation*; deep
> learning "convolution" layers use exactly this (no kernel flip). Keep it simple.

## Output size

With a 3×3 kernel and **no padding** ("valid" mode), the output shrinks by 2 in
each dimension:

```
A is  H x W   ->   C is (H-2) x (W-2)
```

## Assumptions

- `A` is rectangular, with `H >= 3` and `W >= 3`.
- `K` is always 3×3.

## Example

```
A = [[1, 2, 3, 0],        K = [[1, 0, -1],
     [4, 5, 6, 1],             [1, 0, -1],
     [7, 8, 9, 2],             [1, 0, -1]]   (a simple edge kernel)
     [1, 0, 1, 3]]
     (4 x 4)                   (3 x 3)        ->  C is 2 x 2
```

## What to build

- `header/convolution.h` — the declaration
- `src/convolution.cpp`  — the implementation
- `app/main.cpp`         — build A and K, call `convolution`, print the result
