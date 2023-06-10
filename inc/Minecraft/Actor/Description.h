#pragma once
#include <string>
#include <unordered_map>

namespace Json {
class Value;
}

struct Description {
 public:
  static std::unordered_map<
      int, std::string, std::hash<int>, std::equal_to<int>,
      std::allocator<
          std::pair<int const, std::basic_string<char, std::char_traits<char>,
                                                 std::allocator<char> > > > >
      DESCRIPTION_NAME;
  static std::unordered_map<
      std::string, int, std::hash<std::string>,
      std::equal_to<std::basic_string<char, std::char_traits<char>,
                                      std::allocator<char> > >,
      std::allocator<std::pair<std::basic_string<char, std::char_traits<char>,
                                                 std::allocator<char> > const,
                               int> > >
      DESCRIPTION_ID;
  static std::unordered_map<
      std::string, int, std::hash<std::string>,
      std::equal_to<std::basic_string<char, std::char_traits<char>,
                                      std::allocator<char> > >,
      std::allocator<std::pair<std::basic_string<char, std::char_traits<char>,
                                                 std::allocator<char> > const,
                               int> > >
      NAME_TO_ID_MAP;
  static std::unordered_map<
      int, std::string, std::hash<int>, std::equal_to<int>,
      std::allocator<
          std::pair<int const, std::basic_string<char, std::char_traits<char>,
                                                 std::allocator<char> > > > >
      ID_TO_NAME_MAP;

  Description *parseDescription(Json::Value &);
  virtual const char *getJsonName(void) const;
  virtual ~Description(void);
  static int getId(const std::string &);
  static void registerAttributes(void);
  static void registerProperties(void);
  static void registerTriggers(void);
  static void registerComponents(void);
  static void registerJsonName(const std::string &);
  static const std::string &getName(int);
  virtual void deserializeData(Json::Value &);
  virtual void serializeData(Json::Value &) const;

 protected:
  bool startParsing(Json::Value &, Json::Value &, const char *);
};