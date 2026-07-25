# TinyVision

**A Modern C++20 Learning Project**

## Project Goal

TinyVision is **not** intended to replace OpenCV or become a production computer vision library.

Its purpose is to serve as a structured learning project for mastering **Modern C++20** through the implementation of a small but well-designed image processing library.

The emphasis is on:

* Modern C++20 language features
* Software engineering best practices
* Memory management
* Generic programming
* Concurrency
* Project organization
* Clean architecture

The project should prioritize **code quality and learning value** over the number of implemented algorithms.

---

# Learning Objectives

By completing TinyVision, the developer should understand:

* RAII
* Constructors / Destructors
* Rule of Zero
* Rule of Five
* Move Semantics
* Smart Pointers
* Templates
* STL Containers
* Iterators
* Ranges
* Concepts
* Filesystem
* Exception Safety
* Threading
* Futures
* Condition Variables
* CMake
* Unit Testing
* Benchmarking

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

Formatting:

* clang-format

Static Analysis:

* clang-tidy

Documentation:

* Doxygen (optional)

---

# Project Structure

The project uses a conventional `include/` + `src/` split. Public headers
live under `include/tinyvision/`, grouped by module; implementations mirror
that layout under `src/`.

```text
TinyVision/
│
├── CMakeLists.txt
├── README.md
├── LICENSE
│
├── include/
│   └── tinyvision/
│       ├── core/               # Foundational value types
│       │   ├── Image.hpp
│       │   ├── ImageView.hpp
│       │   ├── Buffer.hpp
│       │   ├── Pixel.hpp
│       │   ├── Rect.hpp
│       │   └── Color.hpp
│       │
│       ├── io/                 # Image loading / saving
│       │   ├── ImageReader.hpp
│       │   ├── ImageWriter.hpp
│       │   └── PPM.hpp
│       │
│       ├── processing/         # Image operations & algorithms
│       │   ├── Resize.hpp
│       │   ├── Blur.hpp
│       │   ├── Gray.hpp
│       │   ├── Histogram.hpp
│       │   ├── Threshold.hpp
│       │   └── Sobel.hpp
│       │
│       ├── pipeline/           # Composition of filters
│       │   ├── Pipeline.hpp
│       │   └── Filter.hpp
│       │
│       └── utils/              # Cross-cutting helpers
│           ├── Timer.hpp
│           ├── Logger.hpp
│           └── Assert.hpp
│
├── src/                        # Implementations (mirrors include/)
│   ├── core/
│   ├── io/
│   ├── processing/
│   ├── pipeline/
│   └── utils/
│
├── examples/                   # Lesson programs & demos
│   ├── lesson01_image.cpp
│   ├── lesson02_ppm.cpp
│   ├── lesson03_resize.cpp
│   ├── lesson04_blur.cpp
│   └── pipeline_demo.cpp
│
├── tests/                      # GoogleTest unit tests
│
├── benchmark/                  # Google Benchmark suites
│
├── docs/                       # Documentation
│
└── assets/                     # Sample images
    ├── input/
    └── output/
```

Dependency direction: `core` ← `io`, `processing` ← `pipeline`; `utils` is
shared. Lower layers never depend on higher ones.

The project should follow modern CMake conventions.

Avoid global variables.

Favor composition over inheritance.

---

# Design Philosophy

The project should emphasize:

* Small classes
* Single Responsibility Principle
* Clear ownership
* Explicit interfaces
* RAII everywhere
* Minimal raw pointers
* Value semantics whenever possible

---

# Development Roadmap

---

## Phase 1 — Core Image Class

Implement an Image class.

Responsibilities:

* width
* height
* channels
* pixel storage

The internal storage should use:

```cpp
std::vector<uint8_t>
```

instead of raw pointers.

Implement:

* constructors
* copy constructor
* move constructor
* copy assignment
* move assignment
* destructor (only if necessary)

Learning topics:

* Class design
* Constructors
* Move semantics
* RAII
* std::vector

---

## Phase 2 — File IO

Implement:

* Load PPM images
* Save PPM images

Reason:

PPM is intentionally simple and avoids introducing third-party dependencies at the beginning.

Learning topics:

* File streams
* std::filesystem
* Binary IO

---

## Phase 3 — Basic Image Operations

Implement:

* Crop
* Resize (Nearest Neighbor)
* Flip Horizontal
* Flip Vertical
* Rotate 90°
* Convert to Grayscale

Learning topics:

* Algorithms
* Index calculations
* Function design

---

## Phase 4 — Image Filters

Implement:

* Box Blur
* Gaussian Blur
* Sharpen
* Sobel Edge Detection

Learning topics:

* 2D convolution
* Kernel abstraction
* Generic algorithms

---

## Phase 5 — Histograms

Implement:

* Histogram calculation
* Histogram Equalization

Learning topics:

* STL containers
* std::array
* std::ranges

---

## Phase 6 — Generic Programming

Refactor the library using templates.

Example:

```cpp
Image<uint8_t>

Image<float>

Image<double>
```

Introduce:

* Templates
* Concepts
* constexpr

Learning topics:

* Generic programming
* Compile-time constraints

---

## Phase 7 — Modern STL

Replace traditional loops where appropriate with:

* std::ranges
* std::views
* Algorithms

Examples:

* transform
* filter
* reduce
* sort

Goal:

Understand the philosophy of modern C++ instead of writing C-style loops everywhere.

---

## Phase 8 — Concurrency

Parallelize expensive algorithms.

Examples:

* Blur
* Histogram
* Resize

Implement using:

* std::thread
* std::future
* std::async
* std::mutex

Goal:

Learn Modern C++ concurrency primitives.

---

## Phase 9 — Benchmarking

Measure:

* Single-thread performance
* Multi-thread performance

Use:

Google Benchmark

Learning topics:

* Profiling
* Performance analysis

---

## Phase 10 — Refactoring

Improve:

* Naming
* Architecture
* Code reuse
* Error handling
* API consistency

No new features.

Only code quality improvements.

---

# Coding Guidelines

Prefer:

* const correctness
* auto when appropriate
* std::span
* std::optional
* std::string_view
* enum class
* scoped enums
* noexcept where applicable

Avoid:

* Raw new/delete
* Macros
* Global mutable state
* C-style arrays
* C-style casts

---

# Stretch Goals (Optional)

After completing the core project:

* OpenCV backend
* PNG/JPEG support
* Thread Pool
* SIMD optimization
* ONNX Runtime integration
* CUDA backend
* TensorRT backend

These are optional and should only be attempted after the Modern C++ foundations are solid.

---

# Success Criteria

The project is considered successful if:

* The entire codebase uses Modern C++20 idioms.
* Every feature is covered by unit tests.
* The architecture remains simple and maintainable.
* The developer can clearly explain every major design decision.
* New image algorithms can be added without changing existing architecture.

The primary objective is **learning Modern C++**, not competing with existing computer vision libraries.
