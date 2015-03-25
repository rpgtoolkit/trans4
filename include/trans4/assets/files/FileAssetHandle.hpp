/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_FILEASSETHANDLE_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_FILEASSETHANDLE_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

#include <trans4/assets/AssetHandle.hpp>

namespace rpgtoolkit {

    using std::string;
    using std::unique_ptr;
    using std::ostream;
    using std::istream;
    using std::ifstream;

    struct FileAssetHandle : public AssetHandle {

        FileAssetHandle(AssetDescriptor const & descriptor)
                  : AssetHandle(descriptor), path_(descriptor.name()) {
        }

        bool
        exists() const override {
            return ifstream(path_);
        }

        uintmax_t
        size() const override {
            std::ifstream file(path_, std::ifstream::ate | std::ifstream::binary);
            return file.tellg();
        }

        unique_ptr<istream>
        read() override {
            return unique_ptr<istream>(
                    new std::ifstream(path_, std::ifstream::binary));
        }

        unique_ptr<ostream>
        write() override {
            return unique_ptr<ostream>(
                    new std::ofstream(path_, std::ifstream::binary));
        }

    private:

        string path_;

    };

}

#endif