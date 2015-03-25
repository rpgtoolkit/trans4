/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_IO_BINARYREADER_INCLUDED
#define RPGTOOLKIT_TRANS4_IO_BINARYREADER_INCLUDED

#include <cstdint>
#include <string>
#include <iostream>
#include <vector>

namespace rpgtoolkit {

    using std::istream;
    using std::vector;
    using std::string;

    /// Read-only binary stream interface. This stream wrapper reads
    /// binary data from input streams in a constructor-defined
    /// byte ordering.

    struct BinaryReader {

        BinaryReader(std::istream & stream)
                : stream_(stream) {
            buffer_.resize(8);
        }

        /// Reads a null-terminated string.

        inline BinaryReader &
        operator>>(string & value) {
            std::getline(stream_, value, '\0');
            return *this;
        }

        /// Reads unsigned byte.

        inline BinaryReader &
        operator>>(uint8_t & value) {
            stream_.read(buffer_.data(), sizeof(uint8_t));
            value = buffer_[0];
            return *this;
        }

        /// Reads an unsigned short integer (16-bit)

        inline BinaryReader &
        operator>>(uint16_t & value) {
            stream_.read(buffer_.data(), sizeof(uint16_t));
            value =
                    (buffer_[1] << 0x08) |
                    (buffer_[0] << 0x00);
            return *this;
        }

        /// Reads an unsigned integer (32-bit)

        inline BinaryReader &
        operator>>(uint32_t & value) {
            stream_.read(buffer_.data(), sizeof(uint32_t));
            value =
                    (buffer_[3] << 0x18) |
                    (buffer_[2] << 0x10) |
                    (buffer_[1] << 0x08) |
                    (buffer_[0] << 0x00);
            return *this;
        }

        /// Reads an unsigned long integer (64-bit)

        inline BinaryReader &
        operator>>(uint64_t & value) {
            stream_.read(buffer_.data(), sizeof(uint64_t));
            value =
                    (buffer_[7] << 0x38) |
                    (buffer_[6] << 0x30) |
                    (buffer_[5] << 0x28) |
                    (buffer_[4] << 0x20) |
                    (buffer_[3] << 0x18) |
                    (buffer_[2] << 0x10) |
                    (buffer_[1] << 0x08) |
                    (buffer_[0] << 0x00);
            return *this;
        }

    private:

        std::vector<char> buffer_;
        std::istream & stream_;

    };

}

#endif