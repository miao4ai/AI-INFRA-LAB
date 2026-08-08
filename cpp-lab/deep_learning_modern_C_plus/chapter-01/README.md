# Chapter 01 — Introduction to Deep Learning Programming

Exercises. Ex 1 is conceptual (answered below); Ex 2–4 are coding tasks, each in
its own folder. I write my own solutions — no book code copied.

## Ex 1 — Real-world examples (conceptual)

Give real-world examples of supervised, unsupervised, and reinforcement learning.

- **Supervised**: _(fill in — e.g. spam detection from labeled emails)_
- **Unsupervised**: _(fill in — e.g. customer segmentation / clustering)_
- **Reinforcement**: _(fill in — e.g. game-playing agent, robot control)_

## Ex 2 — `product` → [ex2_product/](ex2_product/)

Matrix multiplication of two rectangular 2D vectors A and B.

```cpp
std::vector<std::vector<double>> product(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B);
```

## Ex 3 — `convolution` → [ex3_convolution/](ex3_convolution/)

2D convolution of matrix A by a 3×3 kernel K (A is a rectangular 2D vector).

```cpp
std::vector<std::vector<double>> convolution(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& K);
```

## Ex 4 — operation count & cost comparison → [ex4_op_count/](ex4_op_count/)

Rewrite `product` and `convolution` to also report the total number of
multiplications and additions performed, then compare their computational cost.

## Build / run

Each folder is self-contained. Compile with sanitizers while learning:

```bash
g++ -std=c++20 -fsanitize=address,undefined -g main.cpp -o run && ./run
```
