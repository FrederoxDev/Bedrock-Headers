#pragma once

#include <string>
#include <vector>
#include "Minecraft/Client/TextureUVCoordinateSet.h"

class TextureAtlasItem {
protected:
    std::string mName;
    int mParsedNodeIndex = 0;
public:
    std::vector<std::vector<TextureUVCoordinateSet>> mTextureUVs;

public:
    TextureAtlasItem() = default;

    TextureAtlasItem(const std::string& name, size_t count) : mName(name) {
        mTextureUVs.resize(count);
    }

    const std::string& getName() const {
        return mName;
    }

    std::vector<TextureUVCoordinateSet>& operator[](size_t id) {
        return mTextureUVs[id];
    }

    const std::vector<TextureUVCoordinateSet>& operator[](size_t id) const {
        return mTextureUVs[id];
    }

    size_t uvCount() const {
        return mTextureUVs.size();
    }

    std::vector<std::vector<TextureUVCoordinateSet>>::iterator begin() {
        return mTextureUVs.begin();
    }

    std::vector<std::vector<TextureUVCoordinateSet>>::iterator end() {
        return mTextureUVs.end();
    }

    void setParsedNodeIndex(int parsedNodeIndex) {
        mParsedNodeIndex = parsedNodeIndex;
    }

    int getParsedNodeIndex() const {
        return mParsedNodeIndex;
    }
};