#ifndef PARTIE_H
#define PARTIE_H

#include <string>

//#define DEBUG_PARTIE

class IHM;
class Joueur;
class Symbole;

class Partie
{
  private:
    IHM*     ihm;
    Joueur*  joueur;
    Symbole* symbole;

    int scoreManchesJoueur     = 0;
    int scoreManchesOrdinateur = 0;
    int nbEgalitesManche       = 0;

    int scorePartiesJoueur     = 0;
    int scorePartiesOrdinateur = 0;
    int nbEgalitesParties      = 0;

    unsigned int nbManches    = 0;
    unsigned int numeroManche = 0;

  public:
    Partie(IHM* ihm, Joueur* joueur);
    Partie(Symbole* symbole);
    ~Partie();
    int getScoreManchesJoueur() const;
    int getScoreManchesOrdinateur() const;
    int getNbEgalitesManches() const;

    int getScorePartiesJoueur() const;
    int getScorePartiesOrdinateur() const;
    int getNbEgalitesParties() const;

    unsigned int getNbManches();
    void         setNbManches(unsigned int nbManches);
    int          getNumeroManche();

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
    void         determinerGagnant(ResultatDuel resultatDuel,
                                   Symbole      choixSymboleJoueur,
                                   Symbole      choixSymboleOrdinateur);
    void         determinerNbPartieGagnees();
};

#endif // PARTIE_H