// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
#include <memory>

#include "Minecraft/Actor/FilterGroup.h"

class ActorFilterGroup;
class Actor;
class FilterInput;
class VariantParameterList;

namespace Json {
	class Value;
};


class ActorFilterGroup : public FilterGroup {
public:
	virtual ~ActorFilterGroup();
protected:
	virtual std::shared_ptr< FilterGroup> _createSubgroup(FilterGroup::CollectionType) const;
	virtual bool _handleUnknownMember(const std::string&, const Json::Value&);

// Begin Non-Virtual Functions
public:
	ActorFilterGroup(FilterGroup::CollectionType);
	ActorFilterGroup(const ActorFilterGroup&);
	ActorFilterGroup(ActorFilterGroup&);
	static void initialize();
	bool evaluate(const Actor&, const VariantParameterList&) const;
protected:
	bool _addLegacyFilter(const std::string&, const ActorFilterGroup::LegacyMapping&, const FilterInput&);
	bool _processLegacyMember(const std::string&, const Json::Value&, const ActorFilterGroup::LegacyMapping&);
	bool _processLegacyArray(const std::string&, const Json::Value&, const ActorFilterGroup::LegacyMapping&);
};