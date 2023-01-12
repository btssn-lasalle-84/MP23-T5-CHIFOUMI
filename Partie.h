#ifndef PARTIE_H
#define PARTIE_H

#include <string>

#define DEBUG_PARTIE

class IHM;
class Joueur;
class Symbole;

class Partie
{
  private:
    IHM*     ihm;
    Joueur*  joueur;
    Symbole* symbole;

  public:
    Partie(IHM* ihm);
    Partie(Symbole* symbole);
    ~Partie();

    enum ResultatDuel
    {
        INDEFINI,
        EGALITE,
        GAGNE,
        PERDU
    };
    void         demarrer();
    Symbole      obtenirSymboleOrdinateur();
    ResultatDuel determinerResultat(Symbole choixJoueur,
                                    Symbole choixOrdinateur);
};

#endif // PARTIE_H