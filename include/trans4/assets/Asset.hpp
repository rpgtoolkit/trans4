/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_ASSET_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_ASSET_INCLUDED

namespace rpgtoolkit {

    /// Represents an engine asset. All engine assets must derive
    /// from this base class.

    struct Asset {

        /// Resets any asset contents to a newly initialized form.
        ///
        /// Useful for reverting an asset back to default values for
        /// the purpose of data conversion or editing.

        virtual void
        Reset() { }

    };

}

#endif