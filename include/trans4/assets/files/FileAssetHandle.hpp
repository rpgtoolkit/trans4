/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_FILEASSETHANDLE_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_FILEASSETHANDLE_INCLUDED

#include <memory>
#include <string>
#include <iostream>
#include <fstream>

#include "assets/AssetHandle.hpp"

namespace rpgtoolkit {

    using std::string;
    using std::unique_ptr;
    using std::ostream;
    using std::istream;
    using std::ifstream;

    struct FileAssetHandle : public AssetHandle {

        FileAssetHandle(AssetDescriptor const & descriptor);

        bool
        Exists() const override;

        uintmax_t
        GetSize() const override;

        unique_ptr<istream>
        GetInputStream() override;

        unique_ptr<ostream>
        GetOutputStream() override;

    private:

        string path_;

    };

}

#endif