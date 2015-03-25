#ifndef RPGTOOLKIT_TRANS4_ASSETS_ITEM_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_ITEM_INCLUDED

#include <string>

#include "assets/Asset.hpp"

namespace rpgtoolkit {

    using std::string;

    struct Item : public Asset {

        string const &
        GetName() const {
            return name_;
        }

        void
        SetName(string const & value) {
            name_ = value;
        }

        string const &
        GetDescription() const {
            return description_;
        }

        void
        SetDescription(string const & value) {
            description_ = value;
        }

    private:

        string name_;

        string description_;

    };

}

#endif