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

        BinaryReader(std::istream & stream)
            : stream_(stream) {
        }

        inline void
        static ByteSwap(uint16_t & value) {
            value = ((value & 0xff) << 8) |
                ((value & 0xff00) >> 8);
        }

        inline void
        static ByteSwap(uint32_t & value) {
            value = ((value >> 24)) |
                ((value << 8) & 0x00ff0000) |
                ((value >> 8) & 0x0000ff00) |
                ((value << 24));
        }

        inline void
        static ByteSwap(uint64_t & value) {
            value = ((value << 56) |
                ((value << 40) & 0xff000000000000ULL) |
                ((value << 24) & 0xff0000000000ULL) |
                ((value << 8) & 0xff00000000ULL) |
                ((value >> 8) & 0xff000000ULL) |
                ((value >> 24) & 0xff0000ULL) |
                ((value >> 40) & 0xff00ULL) |
                ((value >> 56)));
        }

        string
        ReadString() {
            string value;
            std::getline(stream_, value, '\0');
            return value;
        }

        uint8_t
        ReadByte() {
            char buffer[1];
            stream_.read(buffer, sizeof(uint8_t));
            return buffer[0];
        }

        int16_t
        ReadShort() {
            return (ReadUnsignedShort() & 0xff);
        }

        int16_t
        ReadShortSwapped() {
            return (ReadUnsignedShortSwapped() & 0xff);
        }

        uint16_t
        ReadUnsignedShort() {
            char buffer[2];
            stream_.read(buffer, 2);
            return static_cast<uint16_t>(
                static_cast<uint16_t>(buffer[0] << 8) |
                    static_cast<uint16_t>((unsigned) buffer[1]));
        }

        uint16_t
        ReadUnsignedShortSwapped() {
            char buffer[2];
            stream_.read(buffer, 2);
            return static_cast<uint16_t>(
                static_cast<uint16_t>(buffer[1] << 8) |
                    static_cast<uint16_t>((unsigned) buffer[0]));
        }

        int32_t
        ReadInteger() {
            return (ReadUnsignedInteger() & 0xff);
        }

        int32_t
        ReadIntegerSwapped() {
            return (ReadUnsignedIntegerSwapped() * 0xff);
        }

        uint32_t
        ReadUnsignedInteger() {
            char buffer[4];
            stream_.read(buffer, 4);
            return static_cast<uint32_t>(
                (static_cast<uint32_t>(buffer[0]) << 24) |
                    (static_cast<uint32_t>(buffer[1]) << 16) |
                    (static_cast<uint32_t>(buffer[2]) << 8) |
                    (static_cast<uint32_t>(buffer[3]) << 0));
        }

        uint32_t
        ReadUnsignedIntegerSwapped() {
            char buffer[4];
            stream_.read(buffer, 4);
            return static_cast<uint32_t>(
                (static_cast<uint32_t>(buffer[3]) << 24) |
                    (static_cast<uint32_t>(buffer[2]) << 16) |
                    (static_cast<uint32_t>(buffer[1]) << 8) |
                    (static_cast<uint32_t>(buffer[0]) << 0));
        }

        uint64_t
        ReadUnsignedLong() {
            char buffer[8];
            stream_.read(buffer, 8);
            return static_cast<uint64_t>(
                (static_cast<uint64_t>(buffer[0]) << 56) |
                    (static_cast<uint64_t>(buffer[1]) << 48) |
                    (static_cast<uint64_t>(buffer[2]) << 40) |
                    (static_cast<uint64_t>(buffer[3]) << 32) |
                    (static_cast<uint64_t>(buffer[4]) << 24) |
                    (static_cast<uint64_t>(buffer[5]) << 16) |
                    (static_cast<uint64_t>(buffer[6]) << 8) |
                    (static_cast<uint64_t>(buffer[7]) << 0));
        }

        uint64_t
        ReadUnsignedLongSwapped() {
            char buffer[8];
            stream_.read(buffer, 8);
            return static_cast<uint64_t>(
                (static_cast<uint64_t>(buffer[7]) << 56) |
                    (static_cast<uint64_t>(buffer[6]) << 48) |
                    (static_cast<uint64_t>(buffer[5]) << 40) |
                    (static_cast<uint64_t>(buffer[4]) << 32) |
                    (static_cast<uint64_t>(buffer[3]) << 24) |
                    (static_cast<uint64_t>(buffer[2]) << 16) |
                    (static_cast<uint64_t>(buffer[1]) << 8) |
                    (static_cast<uint64_t>(buffer[0]) << 0));
        }

        int64_t
        ReadLong() {
            return (ReadUnsignedLong() & 0xff);
        }

        int64_t
        ReadLongSwapped() {
            return (ReadUnsignedLongSwapped() & 0xff);
        }

        BinaryReader &
        Skip(size_t count) {
            stream_.ignore(count);
            return *this;
        }

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