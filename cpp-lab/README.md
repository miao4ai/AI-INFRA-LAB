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
