#ifndef ARNOV_TKNS_HPP
#define ARNOV_TKNS_HPP
#include "Inst.hpp"
#include <string>
#include <regex>

#define Identifier 0;
#define Number 0;

struct Token
{
    size_t type;
    std::string value;
};

class Tknst
{
public:
    explicit Tknst(Inst inputstream);

    bool isidentstart(char ch);
    bool isident(char ch);

    Token *readnext();
    void readnumber(Token *t);
    void readident(Token *t);

private:
    Inst _inst;
};

#endif