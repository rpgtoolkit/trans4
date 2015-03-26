/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "assets/files/FileAssetHandle.hpp"

namespace rpgtoolkit {

    FileAssetHandle::FileAssetHandle(AssetDescriptor const & descriptor)
        : AssetHandle(descriptor), path_(descriptor.GetName()) {
    }

    bool
    FileAssetHandle::Exists() const {
        return ifstream(path_).good();
    }

    uintmax_t
    FileAssetHandle::GetSize() const {
    std::ifstream file(path_, std::ifstream::ate | std::ifstream::binary);
    return file.tellg();
    }

    unique_ptr<istream>
    FileAssetHandle::GetInputStream()  {
        return unique_ptr<istream>(
            new std::ifstream(path_, std::ifstream::binary));
    }

    unique_ptr<ostream>
    FileAssetHandle::GetOutputStream() {
        return unique_ptr<ostream>(
            new std::ofstream(path_, std::ifstream::binary));
    }

}