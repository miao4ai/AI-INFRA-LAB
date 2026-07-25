# TinyLinear

**A Modern C++20 Numerical Computing Learning Project**

## Project Goal

TinyLinear is **not** intended to replace Eigen, BLAS/LAPACK, or NumPy, nor to
become a production numerical library.

Its purpose is to serve as a structured learning project for mastering both
**numerical linear algebra** and **Modern C++20** by implementing a small but
well-designed linear algebra and optimization library from scratch.

The emphasis is on:

* Numerical algorithms and their stability
* Modern C++20 language features
* Generic, backend-agnostic design
* Memory layout and performance
* Clean, testable architecture

The project should prioritize **correctness, numerical understanding, and code
quality** over the number of implemented algorithms.

---

# Learning Objectives

By completing TinyLinear, the developer should understand:

### Numerical

* Vector / matrix representations and memory layout
* Matrix multiplication and BLAS-style kernels
* LU, QR, Cholesky, SVD, and eigenvalue decompositions
* Numerical stability, conditioning, and error analysis
* Gradient-based and second-order optimization

### Modern C++

* Value semantics & RAII
* Move semantics & the Rule of Zero/Five
* Templates, concepts, and `constexpr`
* Expression templates (stretch goal)
* `std::span`, `std::mdspan`-style views
* SIMD and parallelism
* Unit testing & benchmarking

---

# Technology Stack

Language:

* C++20

Build System:

* CMake

Testing:

* GoogleTest

Benchmark:

* Google Benchmark

Formatting / Static Analysis:

* clang-format
* clang-tidy

Optional Backends:

* SIMD intrinsics
* CUDA

---

# Project Structure

The project uses a conventional header-first `include/` + `src/` split. Public
headers live under `include/tinylinear/`, grouped by module; implementations
mirror that layout under `src/`.

```text
TinyLinear/
│
├── CMakeLists.txt
├── README.md
│
├── include/
│   └── tinylinear/
│       ├── core/               # Fundamental data types
│       │   ├── Vector.hpp
│       │   ├── Matrix.hpp
│       │   ├── Tensor.hpp       # (later)
│       │   └── Shape.hpp
│       │
│       ├── linalg/             # Matrix decompositions & solvers
│       │   ├── LU.hpp
│       │   ├── QR.hpp
│       │   ├── SVD.hpp
│       │   ├── Cholesky.hpp
│       │   └── EigenSolver.hpp
│       │
│       ├── optimize/           # Numerical optimization
│       │   ├── GradientDescent.hpp
│       │   ├── Newton.hpp
│       │   └── LBFGS.hpp
│       │
│       └── backend/            # Compute backends
│           ├── CPU.hpp
│           ├── SIMD.hpp
│           └── CUDA.hpp         # (optional)
│
├── src/                        # Implementations (mirrors include/)
│   ├── core/
│   ├── linalg/
│   ├── optimize/
│   └── backend/
│
├── examples/                   # Demo programs
│
├── tests/                      # GoogleTest unit tests
│
└── docs/                       # Documentation
```

Dependency direction: `core` ← `linalg`, `optimize`; every module can target a
`backend`. Lower layers never depend on higher ones.

The project should follow modern CMake conventions. Avoid global mutable state.
Favor composition and free functions over deep inheritance hierarchies.

---

# Design Philosophy

The project should emphasize:

* Value semantics for `Vector` / `Matrix`
* Clear ownership and no raw `new`/`delete`
* Explicit, generic interfaces (templated on scalar type)
* Backend abstraction without runtime overhead where possible
* Separation of algorithm (linalg/optimize) from storage (core) and
  execution (backend)
* Numerical correctness verified by tests against known results

---

# Development Roadmap

---

## Phase 1 — Core Types

Implement `Vector` and `Matrix`.

Responsibilities:

* Shape / dimensions
* Contiguous storage (`std::vector<T>`), row-major
* Element access and basic arithmetic (`+`, `-`, scalar `*`)

Learning topics:

* Class design, Rule of Zero/Five, move semantics
* Memory layout and indexing

---

## Phase 2 — Matrix Operations

Implement:

* Matrix–vector and matrix–matrix multiplication
* Transpose
* Norms (L1, L2, Frobenius, inf)
* Submatrix / row / column views

Learning topics:

* Cache-friendly loops
* Views and `std::span`

---

## Phase 3 — Direct Solvers

Implement:

* LU decomposition (partial pivoting) + solve
* Cholesky decomposition for SPD systems
* QR decomposition (Householder)

Learning topics:

* Pivoting and numerical stability
* Backward / forward substitution

---

## Phase 4 — Advanced Decompositions

Implement:

* Eigenvalue solver (symmetric: Jacobi / QR algorithm)
* SVD

Learning topics:

* Iterative algorithms and convergence
* Conditioning and rank

---

## Phase 5 — Optimization

Implement:

* Gradient Descent (with line search)
* Newton's method
* L-BFGS

Learning topics:

* First- vs second-order methods
* Convergence criteria

---

## Phase 6 — Generic Programming

Templatize on scalar type (`float`, `double`) and add:

* Concepts constraining scalar / matrix types
* `constexpr` where feasible

Learning topics:

* Generic numerical code
* Compile-time constraints

---

## Phase 7 — Backends & Performance

Introduce a backend abstraction:

* Reference `CPU` scalar backend
* `SIMD` vectorized kernels
* Optional `CUDA` backend

Learning topics:

* Data parallelism
* Benchmarking single-thread vs SIMD vs GPU

---

## Phase 8 — Benchmarking & Refactoring

* Benchmark kernels with Google Benchmark
* Improve API consistency, naming, and error handling

No new features — quality only.

---

# Coding Guidelines

Prefer:

* const correctness
* value semantics
* templates + concepts
* `std::span` / view types
* `noexcept` where applicable
* explicit numerical types

Avoid:

* Raw `new`/`delete`
* Macros
* Global mutable state
* C-style arrays and casts

---

# Stretch Goals (Optional)

* Expression templates (lazy evaluation)
* Sparse matrices
* Automatic differentiation
* BLAS/LAPACK backend
* Multi-threaded kernels
* GPU (CUDA / cuBLAS) backend

---

# Success Criteria

The project is considered successful if:

* The codebase uses Modern C++20 idioms throughout.
* Every algorithm is covered by unit tests validated against known results.
* Numerical decompositions reconstruct their inputs within tolerance.
* The architecture cleanly separates storage, algorithms, and backends.
* New algorithms can be added without changing existing architecture.

The primary objective is **learning numerical computing and Modern C++**, not
competing with existing linear algebra libraries.
