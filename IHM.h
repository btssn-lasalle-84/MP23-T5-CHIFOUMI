#ifndef IHM_H
#define IHM_H

#include <string>
#include "Partie.h"

class Partie;
class Symbole;

class IHM
{
  private:
    Partie* partie;

  public:
    IHM();
    ~IHM();

    void demarrerPartie() const;
    void quitterJeu() const;

    void afficherMenuPrincipal() const;
    void afficherChoixSymbole() const;
    void afficherResultat(std::string          nomJoueurGagnant,
                          Symbole              choixGagnant,
                          Partie::ResultatDuel resultat) const;
    void afficherHistorique(int scoreJoueur, int scoreOrdinateur) const;

    std::string saisirPseudo() const;
    Symbole     saisirSymbole() const;
};

#endif // IHM_H