#pragma once
#include <unordered_map>
#include <string>
#include "Minecraft/Memory/SharedPtr.h"
#include "Minecraft/Blocks/BlockLegacy.h"

class BlockTypeRegistry {
public:
    static std::unordered_map<std::string, SharedPtr<BlockLegacy>>& mBlockLookupMap;
    static WeakPtr<BlockLegacy> lookupByName(const std::string&);
};