#ifndef RPGTOOLKIT_TRANS4_VERSION_INCLUDED
#define RPGTOOLKIT_TRANS4_VERSION_INCLUDED

#include <string>
#include <ostream>
#include <sstream>

namespace rpgtoolkit {

    const int RPGTOOLKIT_VERSION_MAJOR = 4;

    const int RPGTOOLKIT_VERSION_MINOR = 0;

    const int RPGTOOLKIT_VERSION_PATCH = 0;

    const char * RPGTOOLKIT_VERSION_RELEASE = "alpha";

    const char * RPGTOOLKIT_VERSION_METADATA = "";

    using std::string;
    using std::stringstream;

    /// Engine version information

    struct Version {

        Version(short major, short minor, short patch,
            string const & release, string const & metadata)
            : major_(major), minor_(minor), patch_(patch),
              release_(release), metadata_(metadata) {
        }

        Version(short major, short minor, short patch)
            : major_(major), minor_(minor), patch_(patch) {
        }

        short
        GetMajor() const {
            return major_;
        }

        short
        GetMinor() const {
            return minor_;
        }

        short
        GetPatch() const {
            return patch_;
        }

        string const &
        GetRelease() const {
            return release_;
        }

        string const &
        GetBuildMetadata() const {
            return metadata_;
        }

        string const
        ToString() const {
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


    private:

        short major_;

        short minor_;

        short patch_;

        string release_;

        string metadata_;

    };

}

#endif