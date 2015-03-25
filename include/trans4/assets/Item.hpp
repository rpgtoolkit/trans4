#ifndef RPGTOOLKIT_TRANS4_ASSETS_ITEM_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_ITEM_INCLUDED

#include <string>
#include <trans4/assets/Asset.hpp>

namespace rpgtoolkit {

    using std::string;

    struct Item : public Asset {

        string name;
        string description;

    };

}

#endif