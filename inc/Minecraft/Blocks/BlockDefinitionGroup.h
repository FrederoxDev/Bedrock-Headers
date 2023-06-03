#pragma once
#include <unordered_map>
#include <string>
#include <memory>

class BlockDefinition {};

class BlockDefinitionGroup {
private:
    std::unordered_map<std::string, std::unique_ptr<BlockDefinition>> mBlockDefinitions;
    int mLastBlockId;

public:
    void registerBlocks();

    int getNextBlockId() {
        return mLastBlockId++;
    }
};