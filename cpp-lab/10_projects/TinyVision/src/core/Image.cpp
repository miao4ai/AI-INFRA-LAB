#include "tinyvision/core/Image.hpp"

namespace tinyvision::core {

// TODO(萌喵酱): implement the constructor.
//   - store width / height / channels
//   - size the pixel buffer to hold every byte, initialized to 0
//     (how many bytes total? think: width * height * channels)
//   Hint: use the member initializer list, e.g.
//     : width_(width), height_(height), channels_(channels),
//       pixels_( /* total bytes */ , 0)
Image::Image(int width, int height, int channels)
    : width_(width), height_(height), channels_(channels) {
    // (you can either fill pixels_ here, or better: use the init list above)
}

}  // namespace tinyvision::core
