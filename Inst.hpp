#ifndef ARNOV_INST_HPP
#define ARNOV_INST_HPP

#include <string>
#include <functional>

class Inst
{
public:
    explicit Inst(std::string input);
    typedef std::function<bool(char)> handler_t;
    char peek();
    char next();
    bool eof();
    std::string read(const handler_t &predicate);

private:
    size_t pos;
    std::string _input;
};

#endif