/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "assets/Item.hpp"

namespace rpgtoolkit {

    string const &
    Item::GetName() const {
        return name_;
    }

    void
    Item::SetName(string const & value) {
        name_ = value;
    }

    string const &
    Item::GetDescription() const {
        return description_;
    }

    void
    Item::SetDescription(string const & value) {
        description_ = value;
    }

}