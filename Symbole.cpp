#include "Symbole.h"

Symbole::Symbole() : signeMain(SigneMain::INDEFINI)
{
}

Symbole::Symbole(unsigned int signeMain) : signeMain(signeMain)
{
}

unsigned int Symbole::getSymbole() const
{
    return signeMain;
}

std::string Symbole::getSymboleToString() const
{
    switch(signeMain)
    {
        case INDEFINI:
            return "indéfini";
            break;
        case PIERRE:
            return "pierre";
            break;
        case FEUILLE:
            return "feuille";
            break;
        case CISEAUX:
            return "ciseaux";
            break;
    }
    return std::string();
}