#ifndef IHM_H
#define IHM_H

#include <string>
#include "Partie.h"
#include "Joueur.h"

class Partie;
class Symbole;
class Joueur;

class IHM
{
  private:
    Joueur* joueur;
    Partie* partie;

  public:
    IHM();
    ~IHM();

    void demarrerPartie() const;
    void quitterJeu() const;
    void afficherRegles() const;

    void afficherMenuPrincipal() const;
    void afficherChoixSymbole() const;
    void afficherResultat(std::string          nomJoueurGagnant,
                          Symbole              choixJoueur,
                          Symbole              choixOrdinateur,
                          Partie::ResultatDuel resultat) const;
    void afficherHistorique(int scoreManchesJoueur,
                            int scoreManchesOrdinateur,
                            int scoreEgalitesManches,
                            int scorePartiesJoueur,
                            int scorePartiesOrdinateur,
                            int nbEgalitesParties) const;

    std::string saisirPseudo() const;
    Symbole     saisirSymbole() const;
    void        retournerAuMenu() const;
    void        effacerEcran() const;
    int         saisirNbManches() const;
};

#endif // IHM_H