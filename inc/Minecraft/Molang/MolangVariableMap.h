#pragma once
#include <unordered_map>
#include "Minecraft/Molang/MolangVariable.h"
#include "Minecraft/Util/StringHash.h"

class MolangVariableMap {
  private:
    std::unordered_map<unsigned long, MolangVariable, std::hash<unsigned long>, std::equal_to<unsigned long>, std::allocator<std::pair<unsigned long const, MolangVariable> > > mVariables;

  public:
    MolangVariableMap(void);
    MolangVariableMap(size_t);
    const std::unordered_map<unsigned long, MolangVariable, std::hash<unsigned long>, std::equal_to<unsigned long>, std::allocator<std::pair<unsigned long const, MolangVariable> > > & getVariables(void) const;
    float getMolangVariable(const HashedString &) const;
    float getMolangVariable(HashType64, const char *) const;
    float getOrAddMolangVariable(const HashedString &);
    float getOrAddMolangVariable(HashType64, const char *);
    void setMolangVariable(const HashedString &, float);
    void setMolangVariable(HashType64, const char *, float);
    void removeMolangVariable(HashType64);
    MolangVariableMap & clear(void);
    size_t size(void) const;
};