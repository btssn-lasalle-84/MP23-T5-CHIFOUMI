#include "IHM.h"
#include "Partie.h"
#include "Symbole.h"
#include <string>
#include <iostream>
#include <stdlib.h>

IHM::IHM() : joueur(new Joueur), partie(new Partie(this, joueur))
{
}

IHM::~IHM()
{
    delete partie;
}

void IHM::demarrerPartie() const
{
    partie->demarrer();
    retournerAuMenu();
}

void IHM::quitterJeu() const
{
    std::cout << "        Merci d'avoir joué au Chifoumi "
              << joueur->getPseudo() << ", à bientôt ! :)\n"
              << std::endl;
    exit(0);
}

void IHM::afficherRegles() const
{
    std::cout << R"(
        Deux joueurs choisissent simultanément un des trois coups possibles en le symbolisant de la main. Ils ont le choix entre la pierre, la feuille, et les ciseaux :
            - La pierre bat les ciseaux en les émoussant
            - La feuille bat la pierre en l’enveloppant
            - Les ciseaux battent la feuille en la coupant
        Ainsi chaque coup bat un autre coup, fait match nul contre le deuxième (son homologue) et est battu par le troisième.

	    Il existe plusieurs versions du Chifoumi mais pierre-feuille-ciseaux est la version classique du jeu  )" << std::endl;
    retournerAuMenu();
}

void IHM::afficherMenuPrincipal() const
{
    std::cout << R"(
         _____  _      _   __                           _
        /  __ \| |    (_) / _|                         (_)
        | /  \/| |__   _ | |_   ___   _   _  _ __ ___   _
        | |    | '_ \ | ||  _| / _ \ | | | || '_ ` _ \ | |
        | \__/\| | | || || |  | (_) || |_| || | | | | || |
         \____/|_| |_||_||_|   \___/  \__,_||_| |_| |_||_|

        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠶⣆⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣸⣏⣀⣀⣽⣄⣀⡉⣿⠿⢿⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠛⠉⠀⠀⠀⠀⢈⡟⢿⠀⠀⢸⣿⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣾⣿⣿⣿⡀⠀⢠⡤⠤⢴⠏⠀⢸⠀⠀⢸⠀⠈⠙⢿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⣠⣄⠀⢀⣾⣿⣿⣿⣿⣿⡇⠀⠀⣷⡤⠾⣤⣀⣼⣄⡀⢸⠀⠀⡆⠘⣿⣿⣿⣿⣦⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀
        ⠀⣠⠶⣾⠁⠈⠓⢿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠘⠋⠙⠓⢦⣄⠈⠉⠉⠓⠾⠁⢰⣿⣿⣿⣿⣿⣧⠀⢀⡼⠁⠉⡦⠀⠀⠀⠀
        ⠰⣇⠀⠀⠙⢦⡀⠀⠙⢿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠈⠓⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣷⠋⠀⢀⠞⠁⠀⠀⠀⠀
        ⢀⡜⠳⣄⠀⠀⠙⢦⡀⠀⠙⢿⣿⣿⠿⠿⣧⣀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⣿⣿⣿⣿⣿⣿⠟⠁⢀⡴⠋⠀⠀⠀⠀⠀⠀
        ⠸⣄⠀⠈⠳⣄⠀⠀⠙⠦⠀⠀⠈⠻⣄⠀⠀⠈⠹⣄⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⣠⡞⠀⠀⣀⣀⡤⠤⠔⡄
        ⠀⣸⠷⣄⠀⠈⠳⠄⠀⠀⠀⠀⠀⠀⠈⠓⠀⠀⠀⠘⣦⠀⠀⠀⣠⠏⠁⠉⠛⠿⣟⠉⠀⠀⠀⠸⠿⠓⠊⠉⠁⠀⠀⠀⢀⡷
        ⠀⠻⣆⡈⠙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⢀⡼⠁⠀⠀⠀⢸⣄⡀⠙⢲⠀⠀⠀⣀⣀⡠⠤⠤⠒⠒⠋⠁⠀
        ⠀⠀⠈⠙⢦⡀⠙⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⠀⢸⠀⠀⠀⠀⠀⡸⠈⡇⠀⣸⠋⠉⠉⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⡇⠀⠈⣇⠀⠀⠀⠰⠁⡸⠛⠲⠷⠖⠒⢶⠾⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠻⣦⣀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠀⠙⢦⡴⠋⠀⠀⠀⠀⠀⠉⠒⠒⠦⠤⢀⡼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣦⣄⣀⣠⡤⠖⠋⠀⠀⠀⠀⠙⠦⠀⠀⠀⢀⣀⣀⣀⣀⣤⡶⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⢿⣿⣧⣀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠛⠛⠛⠛⠛⠛⠋⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        --------------------------------------------------------------
    )" << std::endl;

    std::cout << R"(
        Bienvenue sur le Chifoumi !)";
    std::cout << "        Version 1.2\n";

    std::string pseudo = saisirPseudo();
    joueur->setPseudo(pseudo);

    for(;;)
    {
        std::cout << R"(
        [1] Lancer une partie
        [2] Afficher l'historique des parties jouées
        [3] Afficher les règles
        [4] Quitter le jeu

        Tapez votre choix : )";

        int choix;
        std::cin >> choix;
        std::cout << "\n";

        switch(choix)
        {
            case 1:
                demarrerPartie();
                effacerEcran();
                break;
            case 2:
                afficherHistorique(partie->getScoreJoueur(),
                                   partie->getScoreOrdinateur(),
                                   partie->getNbEgalite());
                effacerEcran();
                break;
            case 3:
                afficherRegles();
                effacerEcran();
                break;
            case 4:
                quitterJeu();
                break;
        }
    }
}

void IHM::afficherResultat(std::string          nomJoueurGagnant,
                           Symbole              choixJoueur,
                           Symbole              choixOrdinateur,
                           Partie::ResultatDuel resultat) const
{
    std::string resultatDuel;
    switch(resultat)
    {
        case Partie::ResultatDuel::EGALITE:
            resultatDuel = "\n        Égalité ! ";
            break;
        case Partie::ResultatDuel::GAGNE:
            resultatDuel = "\n        Gagné, ";
            break;
        case Partie::ResultatDuel::PERDU:
            resultatDuel = "\n        Perdu, ";
            break;
        case Partie::ResultatDuel::INDEFINI:
            resultatDuel = "\n        Indéfini !!! ";
            break;
    }
    std::cout
      << "\n        "
         "--------------------------------------------------------------"
      << std::endl;
    std::cout << "\n        " << joueur->getPseudo() << " a joué "
              << choixJoueur.getSymboleToString() << std::endl;
    std::cout << "        "
              << "L'ordinateur a joué " << choixOrdinateur.getSymboleToString();

    if(resultat == Partie::ResultatDuel::GAGNE)
    {
        std::cout << "\n"
                  << resultatDuel << choixJoueur.getSymboleToString() << " bat "
                  << choixOrdinateur.getSymboleToString() << " !!!";
    }
    else if(resultat == Partie::ResultatDuel::PERDU)
    {
        std::cout << "\n"
                  << resultatDuel << choixOrdinateur.getSymboleToString()
                  << " bat " << choixJoueur.getSymboleToString() << " :(";
    }
    else
        std::cout << "\n"
                  << resultatDuel << joueur->getPseudo()
                  << " et l'ordinateur ont tous les deux choisi "
                  << choixJoueur.getSymboleToString() << " ! " << std::endl;

    std::cout
      << "\n        "
         "--------------------------------------------------------------";
}

void IHM::afficherHistorique(int scoreJoueur,
                             int scoreOrdinateur,
                             int nbEgalites) const
{
    std::cout << R"(
        --------------------------------------------------------------
    )" << std::endl;
    std::cout << "        Le score de " <<joueur->getPseudo() <<" est de " << scoreJoueur
              << " point(s)" << std::endl;
    std::cout << "        Le score de l'ordinateur est de " << scoreOrdinateur
              << " point(s)" << std::endl;
    std::cout << "        Le nombre d'égalité(s) est de " << nbEgalites
              << std::endl;
    std::cout << R"(
        --------------------------------------------------------------
    )" << std::endl;
    retournerAuMenu();
}

std::string IHM::saisirPseudo() const
{
    std::cout << "        Tapez votre pseudo : ";
    std::string pseudo;
    std::cin >> pseudo;
    // TODO valider la saisie (pas vide, ...)
    return pseudo;
}

void IHM::afficherChoixSymbole() const
{
    // TODO formater l'affichage
    std::cout << "        Vous avez le choix entre :" << std::endl;
    std::cout << "        La Pierre   [1]" << std::endl;
    std::cout << "        La Feuille  [2]" << std::endl;
    std::cout << "        Le Ciseaux  [3]" << std::endl;
    std::cout << "\n        Tapez votre choix : ";
}

Symbole IHM::saisirSymbole() const
{
    int choixJoueur;
    // TODO valider le choix du symbole
    std::cin >> choixJoueur;
    return Symbole(choixJoueur - 1);
}

void IHM::retournerAuMenu() const
{
    std::cout << "\n        Appuyez sur n'importe quelle touche, puis 'Entrée' "
                 ", pour retourner au menu principal : ";
    std::string retourAuMenu;
    std::cin >> retourAuMenu;
}

void IHM::effacerEcran() const
{
    system("clear");
}