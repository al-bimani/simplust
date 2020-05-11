#include <iostream>
#include <string>
#include "Inst.hpp"
#include "Tknst.hpp"

using namespace std;

int main()
{
    Inst inputstream = Inst("var pi = 3.14");
    Tknst tokenstream = Tknst(inputstream);

    Token *token = new Token();

    while (!tokenstream.eof())
    {
        token = tokenstream.next();

        cout << token->tostring() << endl;
    }

    return 0;
}