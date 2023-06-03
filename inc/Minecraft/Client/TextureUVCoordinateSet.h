#pragma once

#include <utility>
#include "Minecraft/Client/ResourceLocation.h"

class IsotropicFaceData {
private:
    unsigned int mFaceTextureIsotropic;
    unsigned int mIsotropicFaceEnabled;
};

struct TextureUVCoordinateSet {
public:
    TextureUVCoordinateSet(float u0, float v0, float u1, float v1, float weightt, uint16_t _texSizeWa, uint16_t _texSizeHa, ResourceLocation location, IsotropicFaceData isotropicFaceData) {
        _u0 = u0;
        _v0 = v0;
        _u1 = u1;
        _v1 = v1;
        weight = weightt;
        _texSizeW = _texSizeWa;
        _texSizeH = _texSizeHa;
        sourceFileLocation = location;
        mIsotropicFaceData = isotropicFaceData;
    }
private:
    float weight;
    float _u0;
    float _v0;
    float _u1;
    float _v1;
    uint16_t _texSizeW;
    uint16_t _texSizeH;
    ResourceLocation sourceFileLocation;
    IsotropicFaceData mIsotropicFaceData;
};