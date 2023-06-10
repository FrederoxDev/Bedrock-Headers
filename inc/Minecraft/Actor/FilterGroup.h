// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
class FilterTest;
class FilterInput;
// class Json::Value;
// struct FilterTest::Definition;
// struct std::array<FilterContext,7>;
struct FilterParamDefinition;
struct FilterInputs;
// struct std::string;
struct FilterContext;


class FilterGroup {
	// ~FilterGroup
	// ~FilterGroup
	// Unknown pure virtual
protected:
	virtual bool _setupContext(const FilterTest&, FilterContext&) const;
	virtual bool _handleUnknownMember(const std::string&, const Json::Value&);

// Begin Non-Virtual Functions
public:
	bool evaluate(std::array<FilterContext,7>&) const;
	bool parse(const Json::Value&);
	bool addFilterTest(const FilterTest::Definition&, const FilterInputs&);
	void serialize(Json::Value&) const;
protected:
	bool _parseObject(const std::string&, const Json::Value&);
	bool _parseMember(const std::string&, const Json::Value&);
	bool _parseTest(const Json::Value&);
	bool _parseFilterInputs(const Json::Value&, const FilterTest::Definition&, FilterInputs&);
	bool _parseFilterParam(const std::string&, const std::string&, const Json::Value&, const FilterParamDefinition&, FilterInput&);

// Begin Variables
};