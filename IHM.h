#ifndef IHM_H
#define IHM_H

#include <string>
#include "Partie.h"
#include "Joueur.h"

#define NUMERO_VERSION 2.0

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
    void afficherRegleVariante() const;
    void afficherChoixVariante() const;
    void afficherChoixSymbole() const;
    void afficherChoixSymboleVariante() const;

    void afficherMenuPrincipal() const;
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
    int         saisirNbManches() const;
    int         saisirVariante() const;

    void determinerRegleAMontrer() const;
    void appuyerPourRetournerMenu() const;
    void effacerEcran() const;
};

#endif // IHM_H