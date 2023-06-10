// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>

namespace Json {
	class Value;
};

class Description {
 public:
  virtual const char *getJsonName(void) const;
  virtual ~Description(void);
  virtual void deserializeData(Json::Value &);
  virtual void serializeData(Json::Value &) const;

  // Begin Non-Virtual Functions
  Description *parseDescription(Json::Value &);
  static int getId(const std::string &);
  static void registerAttributes(void);
  static void registerProperties(void);
  static void registerTriggers(void);
  static void registerComponents(void);
  static void registerJsonName(const std::string &);
  static const std::string &getName(int);

 protected:
  bool startParsing(Json::Value &, Json::Value &, const char *);
};