#include "Tknst.hpp"

Tknst::Tknst(Inst inputstream) : _inst(std::move(inputstream)){};

bool Tknst::isidentstart(char ch)
{
    return ch == '_' || isalpha(ch);
}

bool Tknst::isident(char ch)
{
    std::string chars = "0123456789$";
    return isidentstart(ch) || chars.find(ch) != std::string::npos;
}

Token *Tknst::readnext()
{
    if (_inst.eof())
        return nullptr;
    _inst.read([](char ch) { return ((std::string) " \n\r\t").find(ch) != std::string::npos; });

    char ch = _inst.peek();
    Token *t = new Token();

    if (isdigit(ch))
        readnumber(t);

    if (isidentstart(ch))
        readident(t);

    return t;
}

void Tknst::readnumber(Token *t)
{
    bool doted = false;
    t->type = Number;
    t->value = _inst.read([&](char ch) {
        if (ch == '.')
        {
            if (doted)
                return false;
            doted = true;
            return true;
        }
        return !!isdigit(ch);
    });
}

void Tknst::readident(Token *t)
{
    t->type = Identifier;
    t->value = _inst.read([&](char ch) { return isident(ch); });
}