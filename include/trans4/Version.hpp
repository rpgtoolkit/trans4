/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_VERSION_INCLUDED
#define RPGTOOLKIT_TRANS4_VERSION_INCLUDED

#include <string>
#include <ostream>

namespace rpgtoolkit {

    using std::string;
    using std::stringstream;

    /// Engine version information

    struct Version {

        Version(short major, short minor, short patch,
            string const & release, string const & metadata);

        Version(short major, short minor, short patch);

        short
        GetMajor() const;

        short
        GetMinor() const;

        short
        GetPatch() const;

        string const &
        GetRelease() const;

        string const &
        GetBuildMetadata() const;

        string const
        ToString() const;

    private:

        short major_;

        short minor_;

        short patch_;

        string release_;

        string metadata_;

    };

}

#endif