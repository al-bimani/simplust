#include <iostream>
#include <string>
#include "Inst.hpp"
#include "Tknst.hpp"

using namespace std;

int main()
{
    Inst inputstream = Inst("var 3.14");
    Tknst tokenstream = Tknst(inputstream);

    Token *ident = tokenstream.readnext();
    cout << ident->value << endl; // var
    Token *num = tokenstream.readnext();
    cout << num->value; // 3.14
    return 0;
}