#pragma once
#include <string>

class SemVersion {
    uint16_t mMajor;
    uint16_t mMinor;
    uint16_t mPatch;
    std::string mPreRelease;
    std::string mBuildMeta;
    std::string mFullVersionString;
    bool mValidVersion;
    bool mAnyVersion;
};

class BaseGameVersion {
    SemVersion mSemVersion;
};