#include "Inst.hpp"

Inst::Inst(std::string input) : _input(move(input))
{
    pos = 0;
};

char Inst::peek()
{
    if (_input.length() < pos)
        return '\0';
    return _input[pos];
}

char Inst::next()
{
    char tmp = peek();
    pos++;
    return tmp;
}

bool Inst::eof()
{
    return peek() == '\0';
}

std::string Inst::read(const handler_t &predicate)
{
    std::string tmp;
    while (!eof() && predicate(peek()))
        tmp += next();
    return tmp;
}