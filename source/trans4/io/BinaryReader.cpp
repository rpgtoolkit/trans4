/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "io/BinaryReader.hpp"

namespace rpgtoolkit {

    BinaryReader::BinaryReader(std::istream & stream)
        : stream_(stream) {
    }

    inline void
    BinaryReader::ByteSwap(uint16_t & value) {
        value = ((value & 0xff) << 8) |
            ((value & 0xff00) >> 8);
    }

    inline void
    BinaryReader::ByteSwap(uint32_t & value) {
        value = ((value >> 24)) |
            ((value << 8) & 0x00ff0000) |
            ((value >> 8) & 0x0000ff00) |
            ((value << 24));
    }

    inline void
    BinaryReader::ByteSwap(uint64_t & value) {
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
    BinaryReader::ReadString() {
        string value;
        std::getline(stream_, value, '\0');
        return value;
    }

    uint8_t
    BinaryReader::ReadByte() {
        char buffer[1];
        stream_.read(buffer, sizeof(uint8_t));
        return buffer[0];
    }

    int16_t
    BinaryReader::ReadShort() {
        return (ReadUnsignedShort() & 0xff);
    }

    int16_t
    BinaryReader::ReadShortSwapped() {
        return (ReadUnsignedShortSwapped() & 0xff);
    }

    uint16_t
    BinaryReader::ReadUnsignedShort() {
        char buffer[2];
        stream_.read(buffer, 2);
        return static_cast<uint16_t>(
            static_cast<uint16_t>(buffer[0] << 8) |
                static_cast<uint16_t>((unsigned) buffer[1]));
    }

    uint16_t
    BinaryReader::ReadUnsignedShortSwapped() {
        char buffer[2];
        stream_.read(buffer, 2);
        return static_cast<uint16_t>(
            static_cast<uint16_t>(buffer[1] << 8) |
                static_cast<uint16_t>((unsigned) buffer[0]));
    }

    int32_t
    BinaryReader::ReadInteger() {
        return (ReadUnsignedInteger() & 0xff);
    }

    int32_t
    BinaryReader::ReadIntegerSwapped() {
        return (ReadUnsignedIntegerSwapped() * 0xff);
    }

    uint32_t
    BinaryReader::ReadUnsignedInteger() {
        char buffer[4];
        stream_.read(buffer, 4);
        return static_cast<uint32_t>(
            (static_cast<uint32_t>(buffer[0]) << 24) |
                (static_cast<uint32_t>(buffer[1]) << 16) |
                (static_cast<uint32_t>(buffer[2]) << 8) |
                (static_cast<uint32_t>(buffer[3]) << 0));
    }

    uint32_t
    BinaryReader::ReadUnsignedIntegerSwapped() {
        char buffer[4];
        stream_.read(buffer, 4);
        return static_cast<uint32_t>(
            (static_cast<uint32_t>(buffer[3]) << 24) |
                (static_cast<uint32_t>(buffer[2]) << 16) |
                (static_cast<uint32_t>(buffer[1]) << 8) |
                (static_cast<uint32_t>(buffer[0]) << 0));
    }

    uint64_t
    BinaryReader::ReadUnsignedLong() {
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
    BinaryReader::ReadUnsignedLongSwapped() {
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
    BinaryReader::ReadLong() {
        return (ReadUnsignedLong() & 0xff);
    }

    int64_t
    BinaryReader::ReadLongSwapped() {
        return (ReadUnsignedLongSwapped() & 0xff);
    }

    BinaryReader &
    BinaryReader::Skip(size_t count) {
        stream_.ignore(count);
        return *this;
    }

}