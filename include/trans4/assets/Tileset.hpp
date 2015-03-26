#ifndef RPGTOOLKIT_TRANS4_ASSETS_TILESET_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_TILESET_INCLUDED

namespace rpgtoolkit {

    enum class TilesetPerspective {

        SQUARE,
        ISOMETRIC

    };

    struct Tileset : public Asset {


        Tileset (size_t dimension, size_t count)
            : dimension_(dimension), count_(count),
              buffer_(new uint32_t[dimension * dimension * count]) {
        }

        size_t
        GetCount() const {
            return count_;
        }

        size_t
        GetTileDimensions() const {
            return dimension_;
        }

        uint32_t *
        GetImageBuffer() {
            return buffer_.get();
        }

    private:

        size_t dimension_;
        size_t count_;

        unique_ptr<uint32_t[]> buffer_;

    };

}

#endif