#include "Tknst.hpp"

std::string Token::tostring()
{
    std::string tag = "";
    tag += "[" + type + "] " + value + "";
    return tag;
}

Tknst::Tknst(Inst inputstream) : _inst(std::move(inputstream)){};

bool Tknst::isidentstart(char ch)
{
    return ch == '_' || isalpha(ch);
}

bool Tknst::isident(char ch)
{
    std::string chars = "0123456789$"; // isdigit(ch) || ch == '$'
    return isidentstart(ch) || chars.find(ch) != std::string::npos;
}

bool Tknst::iswhitespace(char ch)
{
    std::string spaces = "  \n\r\t";
    return spaces.find(ch) != std::string::npos;
}

bool Tknst::isoperator(char ch)
{
    std::string operators = "+-*/%=&|<>!";
    return operators.find(ch) != std::string::npos;
}

Token *Tknst::readnext()
{
    if (_inst.eof())
        return nullptr;

    skipwhitespaces(); // skip whitespaces

    char ch = _inst.peek();
    Token *t = new Token();

    if (isdigit(ch))
        readnumber(t);

    if (isidentstart(ch))
        readident(t);

    if (isoperator(ch))
        readoperator(t);

    // unexpected character
    return t;
}

Token *Tknst::peek()
{
    if (current == nullptr)
    {
        current = readnext();
    }
    return current;
}

Token *Tknst::next()
{
    Token *tmp = new Token();
    if (current != nullptr)
    {
        tmp = current;
        current = nullptr;
    }
    else
        tmp = readnext();
    return tmp;
}

bool Tknst::eof()
{
    return peek() == nullptr;
}

void Tknst::skipwhitespaces()
{
    _inst.read([&](char ch) { return iswhitespace(ch); });
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

void Tknst::readoperator(Token *t)
{
    t->type = Operator;
    t->value = _inst.read([&](char ch) { return isoperator(ch); });
}