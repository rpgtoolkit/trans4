/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <sstream>

#include "Version.hpp"

namespace rpgtoolkit {

    Version::Version(short major, short minor, short patch,
        string const & release, string const & metadata)
        : major_(major), minor_(minor), patch_(patch),
          release_(release), metadata_(metadata) {
    }

    Version::Version(short major, short minor, short patch)
        : major_(major), minor_(minor), patch_(patch) {
    }

    short
    Version::GetMajor() const {
        return major_;
    }

    short
    Version::GetMinor() const {
        return minor_;
    }

    short
    Version::GetPatch() const {
        return patch_;
    }

    string const &
    Version::GetRelease() const {
        return release_;
    }

    string const &
    Version::GetBuildMetadata() const {
        return metadata_;
    }

    string const
    Version::ToString() const {
        stringstream buffer;
        buffer << major_ << ".";
        buffer << minor_ << ".";
        buffer << patch_;
        if (!release_.empty()) {
            buffer << "-" << release_;
        }
        if (!metadata_.empty()) {
            buffer << "+" << metadata_;
        }
        return buffer.str();
    }

}