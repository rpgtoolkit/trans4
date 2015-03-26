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
    /// binary data from input streams; all binary functions assume
    /// a big endian or network order data stream.

    struct BinaryReader {

        BinaryReader(std::istream & stream);

        static void
        ByteSwap(uint16_t & value);

        static void
        ByteSwap(uint32_t & value);

        static void
        ByteSwap(uint64_t & value);

        string
        ReadString();

        uint8_t
        ReadByte();

        int16_t
        ReadShort();

        int16_t
        ReadShortSwapped();

        uint16_t
        ReadUnsignedShort();

        uint16_t
        ReadUnsignedShortSwapped();

        int32_t
        ReadInteger();

        int32_t
        ReadIntegerSwapped();

        uint32_t
        ReadUnsignedInteger();

        uint32_t
        ReadUnsignedIntegerSwapped();

        uint64_t
        ReadUnsignedLong();

        uint64_t
        ReadUnsignedLongSwapped();

        int64_t
        ReadLong();

        int64_t
        ReadLongSwapped();

        BinaryReader &
        Skip(size_t count);

        template<typename T>
        BinaryReader &
        Read(T & value) {
            (*this) >> value;
            return *this;
        }

        template<typename T>
        T Read() const {
            T value;
            (*this) >> value;
            return value;
        }

    private:

        std::istream & stream_;

    };

}

#endif