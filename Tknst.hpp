#ifndef ARNOV_TKNS_HPP
#define ARNOV_TKNS_HPP
#include "Inst.hpp"
#include <string>
#include <regex>

#define Identifier "Identifier";
#define Number "Number";
#define Operator "Operator";

struct Token
{
    std::string type;
    std::string value;

    std::string tostring();
};

class Tknst
{
public:
    explicit Tknst(Inst inputstream);

    bool isidentstart(char ch);
    bool isident(char ch);
    bool isoperator(char ch);
    bool iswhitespace(char ch);

    Token *readnext();
    Token *next();
    Token *peek();
    bool eof();

    void skipwhitespaces();
    void readnumber(Token *t);
    void readident(Token *t);
    void readoperator(Token *t);

private:
    Inst _inst;
    Token *current = nullptr;
};

#endif