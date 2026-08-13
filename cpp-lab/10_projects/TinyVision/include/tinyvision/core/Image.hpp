#pragma once

// TinyVision — Owning 2D image (width, height, channels, pixel storage).
//
// Phase 1: the foundational value type. Pixels are stored in a single
// contiguous std::vector<std::uint8_t>, laid out row-major, interleaved by
// channel:  index(x, y, c) = (y * width + x) * channels + c

#include <cstddef>
#include <cstdint>
#include <vector>

namespace tinyvision::core {

class Image {
public:
    // An empty image (0x0, no pixels).
    Image() = default;

    // Allocate a width x height image with `channels` channels,
    // all pixels initialized to 0.
    Image(int width, int height, int channels);

    // --- accessors ---
    int width() const { return width_; }
    int height() const { return height_; }
    int channels() const { return channels_; }
    std::size_t size() const { return pixels_.size(); }   // total bytes

    // --- Rule of Zero ---
    // We deliberately declare NONE of the five special members
    // (destructor / copy ctor / copy assign / move ctor / move assign).
    // std::vector already manages its own memory correctly, so the
    // compiler-generated defaults do the right thing: copying an Image
    // deep-copies the pixels, moving it steals them, destruction frees them.

private:
    int width_ = 0;
    int height_ = 0;
    int channels_ = 0;
    std::vector<std::uint8_t> pixels_;
};

}  // namespace tinyvision::core
