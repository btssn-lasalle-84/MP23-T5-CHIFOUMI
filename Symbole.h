#ifndef SYMBOLE_H
#define SYMBOLE_H

#include <string>

#define NB_SYMBOLE_PIERRE  1
#define NB_SYMBOLE_FEUILLE 2
#define NB_SYMBOLE_CISEAUX 3

class Symbole
{
  private:
    unsigned int sybole;

  public:
    Symbole();
    Symbole(unsigned int sybole);
    unsigned int getSymbole() const;
    enum Symboles
    {
        Pierre,
        Feuille,
        Ciseaux,
    };
};

#endif // PARTIE_H