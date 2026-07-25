# TinyVision

> A Modern **C++20** image-processing library, built as a structured learning project.

TinyVision is **not** meant to replace OpenCV. Its goal is to master modern C++20
— RAII, move semantics, templates, ranges, concepts, and concurrency — by
implementing a small but well-architected image library from scratch.

See [documents/project.md](documents/project.md) for the full goals, roadmap, and
design philosophy.

## Layout

```
TinyVision/
├── include/tinyvision/   Public headers
│   ├── core/             Image, ImageView, Buffer, Pixel, Rect, Color
│   ├── io/               ImageReader, ImageWriter, PPM
│   ├── processing/       Resize, Blur, Gray, Histogram, Threshold, Sobel
│   ├── pipeline/         Pipeline, Filter
│   └── utils/            Timer, Logger, Assert
├── src/                  Implementations (mirrors include/)
├── examples/             Lesson programs & demos
├── tests/                GoogleTest unit tests
├── benchmark/            Google Benchmark suites
├── docs/                 Generated / written documentation
└── assets/               Sample input/ and output/ images
```

## Build

Requires CMake 3.20+ and a C++20 compiler (GCC 11+, Clang 13+, MSVC 19.29+).

```bash
cmake -S . -B build
cmake --build build
```

Options: `TINYVISION_BUILD_EXAMPLES`, `TINYVISION_BUILD_TESTS`,
`TINYVISION_BUILD_BENCHMARKS`, `TINYVISION_WARNINGS_AS_ERRORS`.

## License

MIT — see [LICENSE](LICENSE).
