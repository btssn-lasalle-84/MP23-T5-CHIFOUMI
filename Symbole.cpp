#include "Symbole.h"

Symbole::Symbole() : signeMain(SigneMain::INDEFINI)
{
}

Symbole::Symbole(unsigned int signeMain) : signeMain(signeMain)
{
}

int Symbole::getSymbole() const
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
            return "la pierre";
            break;
        case FEUILLE:
            return "la feuille";
            break;
        case CISEAUX:
            return "le ciseaux";
            break;
    }
    return std::string();
}