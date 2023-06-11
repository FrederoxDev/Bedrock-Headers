#pragma once

class ExpressionNode {
  public:
    ExpressionOp mOp;
    MolangScriptArg mValue;
    std::vector<ExpressionNode, std::allocator<ExpressionNode> > mChildren;
    uint64_t mUsedTokenFlags;
    std::string _mExpressionString;
    static std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > mExpressionOpTokens;
  private:
    static std::unordered_map<HashedString, MolangQueryFunction, std::hash<HashedString>, std::equal_to<HashedString>, std::allocator<std::pair<HashedString const, MolangQueryFunction> > > mQueryFunctionAccessors;
    static std::unordered_map<HashedString, MolangGenericQueryFunction, std::hash<HashedString>, std::equal_to<HashedString>, std::allocator<std::pair<HashedString const, MolangGenericQueryFunction> > > mGenericQueryFunctionAccessors;
    static QueryFunctionAccessor _defaultUnknownQueryFunction;
    static GenericQueryFunctionAccessor _defaultUnknownGenericQueryFunction;
    static ThreadLocal<EvalParams> mTemporaryMolangEvalParams;
    static bool mMolangInitialized;

  public:
    ExpressionNode(void);
    ExpressionNode(const char *, QueryLookupFunc, GenericQueryLookupFunc);
    ExpressionNode(const std::string &, QueryLookupFunc, GenericQueryLookupFunc);
    ExpressionNode(MolangScriptArg &, ExpressionOp);
    ExpressionNode(const Json::Value &, QueryLookupFunc, GenericQueryLookupFunc);
    ExpressionNode(float);
    ExpressionNode(const MaterialVariants &);
    void clear(void);
    ExpressionNode & operator=(float);
    ExpressionNode & operator=(const MaterialVariants &);
    bool operator==(const ExpressionNode &) const;
    bool operator!=(const ExpressionNode &) const;
    bool isInitialized(void) const;
    Json::Value toJson(void) const;
    const std::string & getExpressionString(void);
    void setExpressionString(const std::string &);
    void replaceArrayVariables(std::unordered_map<HashedString, ExpressionNode, std::hash<HashedString>, std::equal_to<HashedString>, std::allocator<std::pair<HashedString const, ExpressionNode> > > &);
    void validateArrayVariables(void);
    bool optimize(void);
    bool isValid(void) const;
    bool isBinaryExpression(void) const;
    bool contains(ExpressionOp) const;
    MolangScriptArg evalGeneric(RenderParams &) const;
    MolangScriptArg evalGeneric(RenderParams &, const MolangScriptArg &) const;
    MolangScriptArg evalGeneric(RenderParams &, const MolangScriptArg &, EvalParams &) const;
    float evalAsFloat(void) const;
    float evalAsFloat(RenderParams &) const;
    float evalAsFloat(RenderParams &, float) const;
    float evalAsFloat(RenderParams &, float, EvalParams &) const;
    const ExpressionNode * findFirstNodeByOp(ExpressionOp) const;
    std::vector<ExpressionNode const*, std::allocator<ExpressionNode const*> > collect(ExpressionOp) const;
    static void buildExpressionOpTable(void);
    static float fast_atof_positiveOnly(const char *&);
    static void fast_identifier(const char *&);
    static void fast_singleQuotedString(const char *&);
    bool parse(const std::string &, QueryLookupFunc, GenericQueryLookupFunc);
    static Bedrock::Threading::RecursiveMutex & getQueryFunctionMutex(void);
    static const QueryFunctionAccessor * queryFunctionAccessorFromString(const std::string &, bool);
    static const GenericQueryFunctionAccessor * genericQueryFunctionAccessorFromString(const std::string &, bool);
    static void addErrorMessage(const std::string &);
    static void registerQueryFunction(const std::string &, QueryFunctionAccessor, const std::string &, size_t, size_t);
    static void registerGenericQueryFunction(const std::string &, GenericQueryFunctionAccessor, const std::string &, size_t, size_t);
    static const std::unordered_map<HashedString, MolangQueryFunction, std::hash<HashedString>, std::equal_to<HashedString>, std::allocator<std::pair<HashedString const, MolangQueryFunction> > > & getQueryFunctionAccessors(void);
    static const std::unordered_map<HashedString, MolangGenericQueryFunction, std::hash<HashedString>, std::equal_to<HashedString>, std::allocator<std::pair<HashedString const, MolangGenericQueryFunction> > > & getGenericQueryFunctionAccessors(void);
    static std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, MolangQueryFunction, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, MolangQueryFunction> > > getSortedQueryFunctionAccessors(void);
    static std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, MolangGenericQueryFunction, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, MolangGenericQueryFunction> > > getSortedGenericQueryFunctionAccessors(void);
    static std::vector<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > getQueryFunctionDocumentation(void);
    static bool initializeMolang(void);
  private:
    bool _getToken(const char *&, QueryLookupFunc, GenericQueryLookupFunc, uint64_t &);
    bool _checkIsValidAndPopulateUsedTokenFlags(const uint64_t);
    bool tokenize(const char *, uint64_t &, QueryLookupFunc, GenericQueryLookupFunc);
    bool buildTree(uint64_t, QueryLookupFunc, GenericQueryLookupFunc);
    void optimizeFunctionCallParams(void);
    bool hasSubExpressions(void) const;
    bool findClosingOp(size_t &, ExpressionOp) const;
    bool processParamsAndVariables(void);
    bool processSections(void);
    bool processSemicolons(void);
    bool processArrays(void);
    bool processMathFuncs(void);
    bool processNegatives(void);
    bool processUnaryExpression(ExpressionOp);
    bool processBinaryExpression(ExpressionOp);
    void _collect(ExpressionOp, std::vector<ExpressionNode const*, std::allocator<ExpressionNode const*> > &) const;
    float _evalAsFloat(void) const;
    float _evalAsFloat(RenderParams &) const;
    float _evalAsFloat(RenderParams &, float) const;
    float _evalAsFloat(RenderParams &, float, EvalParams &) const;

    typedef std::function<const std::function<float (RenderParams &, const std::vector<float, std::allocator<float> > &)> *(const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &, bool)> QueryLookupFunc;
    typedef std::function<const std::function<MolangScriptArg (RenderParams &, const std::vector<MolangScriptArg, std::allocator<MolangScriptArg> > &)> *(const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &, bool)> GenericQueryLookupFunc;
};