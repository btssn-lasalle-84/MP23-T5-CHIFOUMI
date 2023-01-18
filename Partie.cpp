#include "Partie.h"
#include "IHM.h"
#include "Joueur.h"
#include "Symbole.h"
#include <string>

#ifdef DEBUG_PARTIE
#include <iostream>
#endif

Partie::Partie(IHM* ihm, Joueur* joueur) : ihm(ihm), joueur(joueur)
{
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] " << this
              << std::endl;
#endif
    srand(time(nullptr));
}

Partie::Partie(Symbole* symbole) : symbole(symbole)
{
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] " << this
              << std::endl;
#endif
}

Partie::~Partie()
{
    delete joueur;
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] " << this
              << std::endl;
#endif
}

void Partie::demarrer()
{
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << " début" << std::endl;
#endif
    ihm->afficherChoixSymbole();
    Symbole choixSymboleJoueur     = ihm->saisirSymbole();
    Symbole choixSymboleOrdinateur = obtenirSymboleOrdinateur();
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << "choixSymboleJoueur = " << choixSymboleJoueur.getSymbole()
              << " -> " << choixSymboleJoueur.getSymboleToString() << std::endl;
#endif
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << "choixSymboleOrdinateur = "
              << choixSymboleOrdinateur.getSymbole() << " -> "
              << choixSymboleOrdinateur.getSymboleToString() << std::endl;
#endif

    Partie::ResultatDuel resultatDuel =
      determinerResultat(choixSymboleJoueur, choixSymboleOrdinateur);

    // TODO extraire une méthode
    if(resultatDuel == ResultatDuel::GAGNE)
    {
        ihm->afficherResultat(joueur->getPseudo(),
                              choixSymboleJoueur,
                              choixSymboleOrdinateur,
                              resultatDuel);
        scoreJoueur += 1;
    }
    else if(resultatDuel == ResultatDuel::PERDU)
    {
        ihm->afficherResultat("L'ordinateur",
                              choixSymboleJoueur,
                              choixSymboleOrdinateur,
                              resultatDuel);
        scoreOrdinateur += 1;
    }
    else
    {
        ihm->afficherResultat("L'ordinateur",
                              choixSymboleJoueur,
                              choixSymboleOrdinateur,
                              resultatDuel);
        nbEgalites += 1;
    }
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << " fin" << std::endl;
#endif
}

Symbole Partie::obtenirSymboleOrdinateur()
{
    Symbole choixOrdinateur(rand() % Symbole::SigneMain::NbSymboles);
    return choixOrdinateur;
}

Partie::ResultatDuel Partie::determinerResultat(Symbole choixJoueur,
                                                Symbole choixOrdinateur)
{
    switch(choixJoueur.getSymbole())
    {
        case Symbole::SigneMain::PIERRE:
            if(choixOrdinateur.getSymbole() == Symbole::SigneMain::PIERRE)
            {
                return Partie::ResultatDuel::EGALITE;
            }
            else if(choixOrdinateur.getSymbole() == Symbole::SigneMain::FEUILLE)
            {
                return Partie::ResultatDuel::PERDU;
            }
            else
            {
                return Partie::ResultatDuel::GAGNE;
            }
            break;
        case Symbole::SigneMain::FEUILLE:
            if(choixOrdinateur.getSymbole() == Symbole::SigneMain::PIERRE)
            {
                return Partie::ResultatDuel::GAGNE;
            }
            else if(choixOrdinateur.getSymbole() == Symbole::SigneMain::FEUILLE)
            {
                return Partie::ResultatDuel::EGALITE;
            }
            else
            {
                return Partie::ResultatDuel::PERDU;
            }
            break;
        case Symbole::SigneMain::CISEAUX:
            if(choixOrdinateur.getSymbole() == Symbole::SigneMain::PIERRE)
            {
                return Partie::ResultatDuel::PERDU;
            }
            else if(choixOrdinateur.getSymbole() == Symbole::SigneMain::FEUILLE)
            {
                return Partie::ResultatDuel::GAGNE;
            }
            else
            {
                return Partie::ResultatDuel::EGALITE;
            }
            break;
        default:
#ifdef DEBUG_PARTIE
            std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                      << "choixJoueur = " << choixJoueur.getSymbole()
                      << " non valide !!!" << std::endl;
#endif
            return Partie::ResultatDuel::INDEFINI;
            break;
    }
}

int Partie::getScoreJoueur() const
{
    return scoreJoueur;
}

int Partie::getScoreOrdinateur() const
{
    return scoreOrdinateur;
}

int Partie::getNbEgalite() const
{
    return nbEgalites;
}