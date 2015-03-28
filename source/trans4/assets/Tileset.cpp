/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <cstdint>

#include "assets/Tileset.hpp"

namespace rpgtoolkit {

    Tileset::Tileset(size_t dimension, size_t count)
        : dimension_(dimension), count_(count),
          buffer_(new char[dimension * dimension * count * 4]) {
    }

    size_t
    Tileset::GetCount() const {
        return count_;
    }

    size_t
    Tileset::GetTileDimensions() const {
        return dimension_;
    }

    char *
    Tileset::GetImageBuffer() {
        return buffer_.get();
    }

}