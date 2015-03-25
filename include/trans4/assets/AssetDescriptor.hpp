/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <vector>
#include <string>
#include <functional>

#ifndef RPGTOOLKIT_TRANS4_ASSETS_ASSETDESCRIPTOR_INCLUDED
#define RPGTOOLKIT_TRANS4_ASSETS_ASSETDESCRIPTOR_INCLUDED

namespace rpgtoolkit {

    using std::string;
    using std::vector;
    using std::hash;

    /// Describes an engine asset with a type identifier and
    /// a URI representing the asset location. The asset pipeline
    /// uses descriptors for caching, asset resolution, and various
    /// asset pipeline operations.

    struct AssetDescriptor {

        AssetDescriptor(int type, string const & uri)
                : type_(type), uri_(uri) {

            // TODO: Replace with a proper RFC3986 parser

            size_t scheme = uri_.find_first_of("://");
            size_t lslash = uri_.rfind("/");
            size_t query = uri_.find_first_of("?");

            // Extract the URI scheme

            if (scheme != string::npos) {
                scheme_ = uri_.substr(0, scheme);
            }

            // Find the last slash in the URI

            if (lslash == string::npos) {
                lslash = 0;
                if (scheme != string::npos) {
                    lslash = scheme;
                }
            }

            // Extract the path from the URI; checks if a scheme is present
            // and if not simply reads up until a query marker (?) or the end
            // of the URI.

            if (lslash < uri_.size()) {

                size_t pos = 0;

                if (scheme != string::npos) {
                    pos = (scheme + 3);
                }

                name_ = uri_.substr(pos,
                        (query != string::npos)
                                ? query - pos
                                : uri_.size());

                pos = name_.rfind(".");

                if (pos != string::npos && pos < name_.size() - 1) {
                    extension_ = name_.substr(pos + 1);
                }

            }

            // Extract all tags following a query marker (?)

            // NOTE: Does not currently parse query values; for example,
            /// ?x=y parses to ?x=y instead of a map with x -> y

            if (query != string::npos) {

                string tag;
                string q = uri_.substr(query + 1);

                size_t pos = 0;
                size_t lpos = 0;

                // Extract all tags separated by query separator (&)

                while (pos != string::npos) {
                    lpos = pos;
                    pos = q.find("&", lpos + 1);
                    if (pos != string::npos) {
                        tag = q.substr(lpos, pos);
                        if (tag.size() > 0) {
                            tags_.push_back(tag);
                        }
                    }
                    else {
                        if (lpos <= q.size()) {
                            tag = q.substr(lpos + 1);
                            if (tag.size() > 0) {
                                tags_.push_back(tag);
                            }
                        }
                    }
                }
            }

            if (scheme_.size() == 0) {
                scheme_ = "file";           // default scheme
            }

        }

        /// Returns a collection of tags associated with the asset descriptor
        /// for use by the asset framework in filtering runtime assets.

        vector<string> &
        tags() {
            return tags_;
        }


        /// Returns the asset type of the descriptor.

        int
        type() const {
            return type_;
        }

        /// Returns the fully-qualified URI representing the descriptor.

        string const &
        uri() const {
            return uri_;
        }

        /// Returns the file name of the descriptor path.

        string const &
        name() const {
            return name_;
        }

        /// Returns the file extension of the descriptor path (name).

        string const
        extension() const {
            return extension_;
        }

        /// Returns the URI scheme (e.g. file://, http://) associated
        /// with the asset descriptor.

        string const &
        scheme() const {
            return scheme_;
        }

    private:

        friend struct AssetDescriptorHash;
        friend struct AssetDescriptorEquals;

        int type_;

        string uri_;
        string scheme_;
        string name_;
        string extension_;

        vector<string> tags_;

    };

    /// Functor that computes a hash for a given asset descriptor.

    struct AssetDescriptorHash {

        template<typename T>
        static inline void
        hash_combine(size_t & seed, T const & v) {
            hash<T> hasher;
            seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed << 2);
        }

        size_t
        operator()(AssetDescriptor const & descriptor) const {
            size_t result = 0;
            hash_combine(result, descriptor.type_);
            hash_combine(result, descriptor.name_);
            for (auto & tag : descriptor.tags_) {
                hash_combine(result, tag);
            }
            return result;
        }

    };

    /// Functor that computes equality for a given asset descriptor.

    struct AssetDescriptorEquals {

        bool
        operator()(
                AssetDescriptor const & lhs,
                AssetDescriptor const & rhs) const {
            if (&lhs == &rhs) {
                return true;
            }
            return (lhs.type_ == rhs.type_ && lhs.name_ == rhs.name_);
        }

    };

}

#endif