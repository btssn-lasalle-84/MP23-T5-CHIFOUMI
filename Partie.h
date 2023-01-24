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

    int scoreManchesJoueur     = 0;
    int scoreManchesOrdinateur = 0;
    int nbEgalitesManche       = 0;

    int scorePartiesJoueur     = 0;
    int scorePartiesOrdinateur = 0;
    int nbEgalitesParties      = 0;

    unsigned int nbManches    = 0;
    unsigned int numeroManche = 0;

    int numeroVariante = 0;

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
    int getNumeroManche() const;

    unsigned int getNbManches() const;
    void         setNbManches(unsigned int nbManches);
    int          getNumeroVariante() const;
    void         setNumeroVariante(int numeroVariante);

    enum ResultatDuel
    {
        INDEFINI,
        EGALITE,
        GAGNE,
        PERDU
    };

    void demarrer();

    void mettreAZeroManches();
    void determinerNumeroVariante(int numeroVariante);
    void determinerNbPartieGagnees();

    Symbole obtenirSymboleOrdinateur();
    Symbole obtenirSymboleOrdinateurVariante();

    ResultatDuel determinerResultat(Symbole choixJoueur,
                                    Symbole choixOrdinateur);
    void         determinerGagnant(ResultatDuel resultatDuel,
                                   Symbole      choixSymboleJoueur,
                                   Symbole      choixSymboleOrdinateur);

    void jouerVarianteClassique();
    void jouerVarianteGalaxie();

    ResultatDuel jouerPierre(Symbole choixOrdinateur);
    ResultatDuel jouerCiseaux(Symbole choixOrdinateur);
    ResultatDuel jouerFeuille(Symbole choixOrdinateur);
    ResultatDuel jouerAcarien(Symbole choixOrdinateur);
    ResultatDuel jouerGalaxie(Symbole choixOrdinateur);
};

#endif // PARTIE_H