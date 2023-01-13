#ifndef SYMBOLE_H
#define SYMBOLE_H

#include <string>

class Symbole
{
  private:
    int signeMain;

  public:
    Symbole();
    Symbole(unsigned int signeMain);
    int         getSymbole() const;
    std::string getSymboleToString() const;
    enum SigneMain
    {
        INDEFINI           = -1,
        PIERRE             = 0,
        FEUILLE            = 1,
        CISEAUX            = 2,
        NbSymboles         = 3,
        UNSIGNED_SigneMain = (unsigned int)INDEFINI
    };
    // TODO surcharger l'opérateur << et >>
};

#endif // PARTIE_H