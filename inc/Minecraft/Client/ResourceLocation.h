#pragma once
#include <string>

typedef uint64_t HashType64;

enum class ResourceFileSystem {
    InUserPackage,
    InAppPackage,
    RawPath,
    InSettingDir,
    InExternalDir,
    InServerPackage,
    InDataDir,
    InUserDir,
    InWorldDir
};

class ResourceLocation {
public:
    ResourceFileSystem mFileSystem;
private:
    std::string mPath; // Core::HeapPathBuffer
    HashType64 mPathHash;
    size_t mFullHash;
};