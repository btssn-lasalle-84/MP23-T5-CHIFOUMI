#ifndef SYMBOLE_H
#define SYMBOLE_H

#include <string>

class Symbole
{
  private:
    unsigned int signeMain;

  public:
    Symbole();
    Symbole(unsigned int signeMain);
    unsigned int getSymbole() const;
    std::string  getSymboleToString() const;
    enum SigneMain
    {
        INDEFINI = -1,
        PIERRE,
        FEUILLE,
        CISEAUX,
        NbSymboles,
        UNSIGNED_SigneMain = (unsigned int) INDEFINI
    };
    // TODO surcharger l'opérateur << et >>
};

#endif // PARTIE_H