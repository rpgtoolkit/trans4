/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_TILESET_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_TILESET_INCLUDED

#include <cstdint>
#include <memory>

#include "assets/Asset.hpp"

namespace rpgtoolkit {

    using std::unique_ptr;

    enum class TilesetPerspective {

        SQUARE,
        ISOMETRIC

    };

    struct Tileset : public Asset {

        Tileset (size_t dimension, size_t count);

        size_t
        GetCount() const;

        size_t
        GetTileDimensions() const;

        char *
        GetImageBuffer();

    private:

        size_t dimension_;
        size_t count_;

        unique_ptr<char[]> buffer_;

    };

}

#endif