#pragma once

#include <string>

typedef uint64_t HashType64;

class HashedString {
private:
    HashType64 mStrHash = 0;
    std::string mStr;

public:
    HashedString() = default;
    HashedString(const HashedString&) = default;
    HashedString(HashedString&&) = default;
    HashedString(HashType64 hash, const char* str) : mStrHash(hash), mStr(str) {}
    HashedString(const char* str) : mStr(str), mStrHash(computeHash(str)) {}
    HashedString(const std::string& str) : mStr(str), mStrHash(computeHash(str)) {}
    HashedString(HashType64 hash, std::string str) : mStrHash(hash), mStr(str) {}
    HashedString& operator=(const HashedString&) = default;
    bool operator==(const HashedString& rhs) const {
        if (mStrHash == rhs.mStrHash)
            return mStr == rhs.mStr;
        return false;
    }
    bool operator!=(const HashedString& rhs) const {
        if (mStrHash == rhs.mStrHash)
            return mStr != rhs.mStr;
        return true;
    }
    HashType64 getHash() const { return mStrHash; }
    const std::string& getString() const { return mStr; }
    const char* c_str() const { return mStr.c_str(); }
    bool isEmpty() const { return mStr.empty(); }
    bool empty() const { return mStr.empty(); }
    void clear() { mStr = ""; mStrHash = 0; }
    static HashType64 computeHash(const char*);
    static HashType64 computeHash(const std::string& str) {
        if (str.empty())
            return 0;
        return computeHash(str.c_str());
    }
};

class StringKey : public HashedString {
protected:
    const StringKey* mMatch = nullptr;

public:
    StringKey() : HashedString() {}
    StringKey(HashedString&& key) : HashedString(key) {}
    StringKey(StringKey&& key) : HashedString(key) {}
    StringKey(const HashedString& key) : HashedString(key) {}
    StringKey(const StringKey& key) : HashedString(key) {}
    StringKey(const std::string& key) : HashedString(key) {}
    StringKey& operator=(const HashedString& rhs) { *this = rhs; }
    StringKey& operator=(const StringKey&) = default;
    bool operator==(const StringKey& rha) const {
        StringKey* lhs = const_cast<StringKey*>(this);
        StringKey* rhs = const_cast<StringKey*>(&rha);

        if (getHash() == rhs->getHash()) {
            if (mMatch == rhs) {
                lhs->mMatch = nullptr;
                rhs->mMatch = nullptr;
                return true;
            }
            else if (HashedString(*this) == HashedString(rha)) {
                lhs->mMatch = rhs;
                rhs->mMatch = this;
                return true;
            }
        }

        lhs->mMatch = nullptr;
        return false;
    }
};

namespace std
{
    template<> struct hash<StringKey>
    {
        std::size_t operator()(StringKey const& key) const noexcept
        {
            return key.getHash();
        }
    };
}