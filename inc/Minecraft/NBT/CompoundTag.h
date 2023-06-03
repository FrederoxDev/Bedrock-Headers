#pragma once

#include "gsl/string_span"
#include <functional>
#include <map>
#include <memory>
#include <variant>
#include "Minecraft/NBT/Tag.h"

class CompoundTagVariant;
class PrintStream;
class TagMemoryChunk;
class ListTag;
class IDataOutput;
class IDataInput;

typedef gsl::basic_string_span<const char> string_span;
typedef std::map<std::string, CompoundTagVariant, std::less<>> TagMap;

class CompoundTag : public Tag {
private:
	TagMap mTags;

public:
	virtual ~CompoundTag() = default;
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&);
	virtual std::string toString() const;
	virtual Tag::Type getId() const;
	virtual bool equals(const Tag&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual std::unique_ptr< Tag, std::default_delete<Tag>> copy() const;
	virtual unsigned __int64 hash() const;

	// Begin Non-Virtual Functions
	CompoundTag();
	CompoundTag(CompoundTag&);
	Tag* put(std::string, std::unique_ptr<Tag, std::default_delete<Tag>>);
	unsigned char& putByte(std::string, unsigned char);
	short& putShort(std::string, short);
	int& putInt(std::string, int);
	float& putFloat(std::string, float);
	std::string& putString(std::string, std::string);
	TagMemoryChunk& putByteArray(std::string, TagMemoryChunk);
	CompoundTag& putCompound(std::string, CompoundTag);
	CompoundTag* putCompound(std::string, std::unique_ptr<CompoundTag, std::default_delete<CompoundTag>>);
	void putBoolean(std::string, bool);
	void append(const CompoundTag&);
	bool contains(const string_span) const;
	bool contains(const string_span, Tag::Type) const;
	unsigned char getByte(const string_span) const;
	short getShort(const string_span) const;
	int getInt(const string_span) const;
	float getFloat(const string_span) const;
	const std::string& getString(const string_span) const;
	const TagMemoryChunk& getByteArray(const string_span) const;
	const CompoundTag* getCompound(const string_span) const;
	CompoundTag* getCompound(const string_span);
	const ListTag* getList(const string_span) const;
	ListTag* getList(const string_span);
	bool getBoolean(const string_span) const;
	void deepCopy(const CompoundTag&);
	std::unique_ptr< CompoundTag, std::default_delete< CompoundTag> > clone() const;
	bool remove(const string_span);
};

class CompoundTagVariant {
    typedef std::variant<CompoundTag> Variant;

public:
    Variant mTagStorage;

    CompoundTagVariant() {}
};