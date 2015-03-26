/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYITEMSERIALIZER_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_SERIALIZERS_LEGACYITEMSERIALIZER_INCLUDED

#include "assets/AssetSerializer.hpp"

namespace rpgtoolkit {

    struct LegacyItemSerializer : public AssetSerializer {

        const int VERSION_MAJOR = 2;
        const int VERSION_MINOR = 7;

        bool
        CanSerialize(AssetDescriptor const & descriptor) override;

        bool
        CanDeserialize(AssetDescriptor const & descriptor) override;

        void
        Serialize(AssetHandle & handle) override;

        virtual void
        Deserialize(AssetHandle & handle) override;

    };

}

#endif