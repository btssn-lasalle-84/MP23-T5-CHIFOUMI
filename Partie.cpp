#include "Partie.h"
#include "IHM.h"
#include "Joueur.h"
#include "Symbole.h"
#include <string>
#include <iostream>
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

int Partie::getScoreManchesJoueur() const
{
    return scoreManchesJoueur;
}

int Partie::getScoreManchesOrdinateur() const
{
    return scoreManchesOrdinateur;
}

int Partie::getNbEgalitesManches() const
{
    return nbEgalitesManche;
}

int Partie::getScorePartiesJoueur() const
{
    return scorePartiesJoueur;
}
int Partie::getScorePartiesOrdinateur() const
{
    return scorePartiesOrdinateur;
}
int Partie::getNbEgalitesParties() const
{
    return nbEgalitesParties;
}

int Partie::getNumeroManche() const
{
    return numeroManche;
}

unsigned int Partie::getNbManches() const
{
    return nbManches;
}

void Partie::setNbManches(unsigned int nbManches)
{
    this->nbManches = nbManches;
}

int Partie::getNumeroVariante() const
{
    return numeroVariante;
}
void Partie::setNumeroVariante(int numeroVariante)
{
    this->numeroVariante = numeroVariante;
}

void Partie::demarrer()
{
    mettreAZeroManches();
    determinerNumeroVariante(numeroVariante);
    determinerNbPartieGagnees();
}

void Partie::mettreAZeroManches()
{
    numeroManche           = 0;
    scoreManchesJoueur     = 0;
    scoreManchesOrdinateur = 0;
    nbEgalitesManche       = 0;
}

void Partie::determinerNumeroVariante(int numeroVariante)
{
    switch(numeroVariante)
    {
        case 1:
            jouerVarianteClassique();
            break;
        case 2:
            jouerVarianteGalaxie();
            break;
        default:
            std::cout << "Aucune Variante selectionnée " << std::endl;
    }
}

void Partie::determinerNbPartieGagnees()
{
    if(scoreManchesJoueur > scoreManchesOrdinateur)
    {
        scorePartiesJoueur += 1;
    }
    else if(scoreManchesJoueur < scoreManchesOrdinateur)
    {
        scorePartiesOrdinateur += 1;
    }
    else
    {
        nbEgalitesParties += 1;
    }
}

Symbole Partie::obtenirSymboleOrdinateur()
{
    Symbole choixOrdinateur = (rand() % Symbole::SigneMain::NbSymboles);
    return choixOrdinateur;
}

Symbole Partie::obtenirSymboleOrdinateurVariante()
{
    Symbole choixOrdinateur = (rand() % Symbole::SigneMain::NbSymbolesVariante);
    return choixOrdinateur;
}

Partie::ResultatDuel Partie::determinerResultat(Symbole choixJoueur,
                                                Symbole choixOrdinateur)
{
    if(numeroVariante == 2)
    {
        switch(choixJoueur.getSymbole())
        {
#ifdef DEBUG_PARTIE
            std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                      << "  Variante 2 PFCGA= " << numeroVariante << std::endl;
#endif
            case Symbole::SigneMain::PIERRE:
                if(choixOrdinateur.getSymbole() == Symbole::SigneMain::PIERRE)
                {
                    return Partie::ResultatDuel::EGALITE;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::FEUILLE)
                {
                    return Partie::ResultatDuel::PERDU;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::GALAXIE)
                {
                    return Partie::ResultatDuel::PERDU;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::ACARIEN)
                {
                    return Partie::ResultatDuel::GAGNE;
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
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::FEUILLE)
                {
                    return Partie::ResultatDuel::EGALITE;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::GALAXIE)
                {
                    return Partie::ResultatDuel::PERDU;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::ACARIEN)
                {
                    return Partie::ResultatDuel::GAGNE;
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
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::FEUILLE)
                {
                    return Partie::ResultatDuel::GAGNE;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::GALAXIE)
                {
                    return Partie::ResultatDuel::PERDU;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::ACARIEN)
                {
                    return Partie::ResultatDuel::GAGNE;
                }
                else
                {
                    return Partie::ResultatDuel::EGALITE;
                }

                break;
            case Symbole::SigneMain::GALAXIE:
                if(choixOrdinateur.getSymbole() == Symbole::SigneMain::PIERRE)
                {
                    return Partie::ResultatDuel::GAGNE;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::FEUILLE)
                {
                    return Partie::ResultatDuel::GAGNE;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::CISEAUX)
                {
                    return Partie::ResultatDuel::GAGNE;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::ACARIEN)
                {
                    return Partie::ResultatDuel::PERDU;
                }
                else
                {
                    return Partie::ResultatDuel::EGALITE;
                }
            case Symbole::SigneMain::ACARIEN:
                if(choixOrdinateur.getSymbole() == Symbole::SigneMain::PIERRE)
                {
                    return Partie::ResultatDuel::PERDU;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::FEUILLE)
                {
                    return Partie::ResultatDuel::PERDU;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::CISEAUX)
                {
                    return Partie::ResultatDuel::PERDU;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::GALAXIE)
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
                std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__
                          << "] "
                          << "choixJoueur = " << choixJoueur.getSymbole()
                          << " non valide !!!" << std::endl;
#endif
                return Partie::ResultatDuel::INDEFINI;
                break;
        }
    }
    else
    {
        switch(choixJoueur.getSymbole())
        {
#ifdef DEBUG_PARTIE
            std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                      << "  Variante 1 PFC= " << numeroVariante << std::endl;
#endif
            case Symbole::SigneMain::PIERRE:
                if(choixOrdinateur.getSymbole() == Symbole::SigneMain::PIERRE)
                {
                    return Partie::ResultatDuel::EGALITE;
                }
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::FEUILLE)
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
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::FEUILLE)
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
                else if(choixOrdinateur.getSymbole() ==
                        Symbole::SigneMain::FEUILLE)
                {
                    return Partie::ResultatDuel::GAGNE;
                }
                else
                {
                    return Partie::ResultatDuel::EGALITE;
                }
            default:
#ifdef DEBUG_PARTIE
                std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__
                          << "] "
                          << "choixJoueur = " << choixJoueur.getSymbole()
                          << " non valide !!!" << std::endl;
#endif
                return Partie::ResultatDuel::INDEFINI;
                break;
        }
    }
}
void Partie::determinerGagnant(ResultatDuel resultatDuel,
                               Symbole      choixSymboleJoueur,
                               Symbole      choixSymboleOrdinateur)
{
    if(resultatDuel == ResultatDuel::GAGNE)
    {
        ihm->afficherResultat(joueur->getPseudo(),
                              choixSymboleJoueur,
                              choixSymboleOrdinateur,
                              resultatDuel);
        scoreManchesJoueur += 1;
    }
    else if(resultatDuel == ResultatDuel::PERDU)
    {
        ihm->afficherResultat("L'ordinateur",
                              choixSymboleJoueur,
                              choixSymboleOrdinateur,
                              resultatDuel);
        scoreManchesOrdinateur += 1;
    }
    else
    {
        ihm->afficherResultat("L'ordinateur",
                              choixSymboleJoueur,
                              choixSymboleOrdinateur,
                              resultatDuel);
        nbEgalitesManche += 1;
    }
}

void Partie::jouerVarianteClassique()
{
    while(numeroManche != getNbManches())
    {
#ifdef DEBUG_PARTIE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << " début variante classique" << std::endl;
#endif
        ihm->afficherChoixSymbole();
        Symbole choixSymboleJoueur     = ihm->saisirSymbole();
        Symbole choixSymboleOrdinateur = obtenirSymboleOrdinateur();
#ifdef DEBUG_PARTIE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << "choixSymboleJoueur = " << choixSymboleJoueur.getSymbole()
                  << " -> " << choixSymboleJoueur.getSymboleToString()
                  << std::endl;
#endif
#ifdef DEBUG_PARTIE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << "choixSymboleOrdinateur = "
                  << choixSymboleOrdinateur.getSymbole() << " -> "
                  << choixSymboleOrdinateur.getSymboleToString() << std::endl;
#endif
        Partie::ResultatDuel resultatDuel =
          determinerResultat(choixSymboleJoueur, choixSymboleOrdinateur);
        determinerGagnant(resultatDuel,
                          choixSymboleJoueur,
                          choixSymboleOrdinateur);

#ifdef DEBUG_PARTIE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << " fin" << std::endl;
#endif
        numeroManche += 1;
    }
}

void Partie::jouerVarianteGalaxie()
{
    while(numeroManche != getNbManches())
    {
#ifdef DEBUG_PARTIE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << " Début variante Galaxie" << std::endl;
#endif
        ihm->afficherChoixSymboleVariante();
        Symbole choixSymboleJoueur     = ihm->saisirSymbole();
        Symbole choixSymboleOrdinateur = obtenirSymboleOrdinateurVariante();
#ifdef DEBUG_PARTIE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << "choixSymboleJoueur = " << choixSymboleJoueur.getSymbole()
                  << " -> " << choixSymboleJoueur.getSymboleToString()
                  << std::endl;
#endif
#ifdef DEBUG_PARTIE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << "choixSymboleOrdinateur = "
                  << choixSymboleOrdinateur.getSymbole() << " -> "
                  << choixSymboleOrdinateur.getSymboleToString() << std::endl;
#endif
        Partie::ResultatDuel resultatDuel =
          determinerResultat(choixSymboleJoueur, choixSymboleOrdinateur);
        determinerGagnant(resultatDuel,
                          choixSymboleJoueur,
                          choixSymboleOrdinateur);

#ifdef DEBUG_PARTIE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << " fin" << std::endl;
#endif
        numeroManche += 1;
    }
}