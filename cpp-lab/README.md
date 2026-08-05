# cpp-lab

> **Modern C++ from fundamentals to concurrent, real-world systems.**

A hands-on lab for learning modern C++ (C++20) through small, focused modules.
Each numbered directory builds on the previous one, moving from language basics
to memory, concurrency, and full projects.

---

## Structure

```
cpp-lab
│
├── 01_basics            Syntax, types, control flow, functions
├── 02_stl               Containers, iterators, algorithms, ranges
├── 03_oop               Classes, inheritance, polymorphism, RAII
├── 04_templates         Generics, variadics, template metaprogramming
├── 05_smart_pointers    unique_ptr, shared_ptr, weak_ptr, ownership
├── 06_concurrency       Threads, mutexes, atomics, async
├── 07_memory            Memory model, allocators, layout, alignment
├── 08_cpp20             Concepts, ranges, coroutines, modules
├── 09_design_patterns   Idiomatic C++ implementations of classic patterns
├── 10_projects          Larger end-to-end projects
│
├── CMakeLists.txt
└── README.md
```

---

## Project Roadmap

Six projects under `10_projects/`, each targeting one layer of the modern C++ /
AI-infra stack. Every phase builds on the previous ones and converges on a mini
inference runtime.

| Phase   | Project             | Core Goal                                              |
| ------- | ------------------- | ------------------------------------------------------ |
| Phase 1 | **TinyVision**      | Modern C++ (classes, RAII, move, templates, STL)       |
| Phase 2 | **TinyMemory**      | Resource management (allocators, memory pool, alignment) |
| Phase 3 | **TinyScheduler**   | Concurrency (thread pool, futures, task scheduler)     |
| Phase 4 | **TinyLinear**      | Numerical computing (matrix, SIMD, cache, BLAS ideas)  |
| Phase 5 | **TinyInfer**       | Integrate phases 1–4 into a mini inference runtime     |
| Phase 6 | **TinyDistributed** | Distributed execution (MPI, Ray, Spark, cluster scheduling) |

> **Target: 3 months. 坚信能完成 💪**

---

## Build

Requires CMake 3.20+ and a C++20 compiler (GCC 11+, Clang 13+, or MSVC 19.29+).

```bash
cmake -S . -B build
cmake --build build
```

Build a single module's target:

```bash
cmake --build build --target <target_name>
```

---

## Philosophy

* Every concept gets a minimal, runnable example.
* Prefer standard library and modern idioms over legacy patterns.
* Read the theory, then build it from scratch.
