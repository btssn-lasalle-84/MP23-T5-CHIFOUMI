#include "Partie.h"
#include "IHM.h"
#include "Joueur.h"
#include "Symbole.h"
#include <string>

#ifdef DEBUG_PARTIE
#include <iostream>
#endif

Partie::Partie(IHM* ihm) : ihm(ihm), joueur(new Joueur)
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
    // TODO revoir l'emplacement de la saisie du pseudo (elle doit être unique)
    std::string pseudo = ihm->saisirPseudo();
    joueur->setPseudo(pseudo);

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
                              resultatDuel);
    }
    else if(resultatDuel == ResultatDuel::PERDU)
    {
        ihm->afficherResultat("L'ordinateur",
                              choixSymboleOrdinateur,
                              resultatDuel);
    }
    else
    {
        ihm->afficherResultat("L'ordinateur",
                              choixSymboleOrdinateur,
                              resultatDuel);
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
            // TODO gérer l'ensemble des combinaisons
        /*case FEUILLE:
            if(choixOrdinateur == PIERRE)
            {
                std::cout << "Vous avez gagné! L'ordinateur a choisi Pierre."
                          << std::endl;
            }
            else if(choixOrdinateur == FEUILLE)
            {
                std::cout << "Egalité! L'ordinateur a choisi Feuille également."
                          << std::endl;
            }
            else
            {
                std::cout << "Vous avez perdu! L'ordinateur a choisi Ciseaux."
                          << std::endl;
            }
            break;
        case CISEAUX:
            if(choixOrdinateur == PIERRE)
            {
                std::cout << "Vous avez perdu! L'ordinateur a choisi Pierre."
                          << std::endl;
            }
            else if(choixOrdinateur == FEUILLE)
            {
                std::cout << "Vous avez gagné! L'ordinateur a choisi Feuille."
                          << std::endl;
            }
            else
            {
                std::cout << "Egalité! L'ordinateur a choisi Ciseaux également."
                          << std::endl;
            }
            break;*/
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