/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_ITEM_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_ITEM_INCLUDED

#include <string>

#include "assets/Asset.hpp"

namespace rpgtoolkit {

    using std::string;

    struct Item : public Asset {

        string const &
        GetName() const;

        void
        SetName(string const & value);

        string const &
        GetDescription() const;

        void
        SetDescription(string const & value);

    private:

        string name_;

        string description_;

    };

}

#endif