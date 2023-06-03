#pragma once

#include <string>
#include <memory>

class IDataInput;
class IDataOutput;
class PrintStream;

class Tag {
public:
    enum class Type : unsigned char {
        End,
        Byte,
        Short,
        Int,
        Int64,
        Float,
        Double,
        ByteArray,
        String,
        List,
        Compound,
        IntArray
    };

    static const std::string NullString;
    static const int TAGERR_OUT_OF_BOUNDS;
    static const int TAGERR_BAD_TYPE;

    virtual ~Tag() = default;
    virtual void deleteChildren() {}
    virtual void write(IDataOutput&) const = 0;
    virtual void load(IDataInput&) = 0;
    virtual std::string toString() const = 0;
    virtual Type getId() const = 0;
    virtual bool equals(const Tag&) const;
    virtual void print(PrintStream&) const;
    virtual void print(const std::string&, PrintStream&) const;
    virtual std::unique_ptr<Tag> copy() const = 0;
    virtual size_t hash() const = 0;

    static std::unique_ptr<Tag> readNamedTag(IDataInput&, std::string&);
    static void writeNamedTag(const std::string&, const Tag&, IDataOutput&);
    static std::unique_ptr<Tag> newTag(Type);
    static std::string getTagName(Type);
    
protected:
    Tag();
};