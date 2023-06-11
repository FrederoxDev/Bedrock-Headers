#pragma once

#include <vector>
#include <unordered_map>

#include "Minecraft/Util/StringHash.h"

class AttributeInstance;
class AttributeInstanceHandle;
class Attribute;

class BaseAttributeMap {
  private:
    std::unordered_map<unsigned int, AttributeInstance, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<unsigned int const, AttributeInstance> > > mInstanceMap;
    std::vector<AttributeInstanceHandle, std::allocator<AttributeInstanceHandle> > mDirtyAttributes;
    static AttributeInstance mInvalidInstance;

  public:
    AttributeInstance * getMutableInstance(const Attribute &);
    AttributeInstance * getMutableInstance(const HashedString &);
    AttributeInstance * getMutableInstance(const uint32_t);
    const AttributeInstance & getInstance(const Attribute &) const;
    const AttributeInstance & getInstance(const HashedString &) const;
    const AttributeInstance & getInstance(uint32_t) const;
    AttributeInstance & registerAttribute(const Attribute &);
    void onAttributeModified(const AttributeInstance &);
    const std::vector<AttributeInstanceHandle, std::allocator<AttributeInstanceHandle> > & getDirtyAttributes(void);
    void clearDirtyAttributes(void);
    std::vector<AttributeInstanceHandle, std::allocator<AttributeInstanceHandle> > getSyncableAttributes(void) const;
    std::unordered_map<unsigned int, AttributeInstance, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<unsigned int const, AttributeInstance> > >::const_iterator begin(void) const;
    std::unordered_map<unsigned int, AttributeInstance, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<unsigned int const, AttributeInstance> > >::iterator begin(void);
    std::unordered_map<unsigned int, AttributeInstance, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<unsigned int const, AttributeInstance> > >::const_iterator end(void) const;
    std::unordered_map<unsigned int, AttributeInstance, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<unsigned int const, AttributeInstance> > >::iterator end(void);
};