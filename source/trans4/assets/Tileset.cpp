/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <cstdint>

#include "assets/Tileset.hpp"

namespace rpgtoolkit {

    Tileset::Tileset(size_t dimension, size_t count)
        : dimension_(dimension), count_(count),
          buffer_(new uint32_t[dimension * dimension * count]) {
    }

    size_t
    Tileset::GetCount() const {
        return count_;
    }

    size_t
    Tileset::GetTileDimensions() const {
        return dimension_;
    }

    uint32_t *
    Tileset::GetImageBuffer() {
        return buffer_.get();
    }

}