#include "IHM.h"
#include "Partie.h"
#include "Symbole.h"
#include <string>
#include <iostream>
#include <stdlib.h>

IHM::IHM() : partie(new Partie(this))
{
}

IHM::~IHM()
{
    delete partie;
}

void IHM::demarrerPartie() const
{
    partie->demarrer();
}

void IHM::quitterJeu() const
{
    std::cout << "        Merci d'avoir joué au Chifoumi, à bientôt ! :)\n"
              << std::endl;
    exit(0);
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

    saisirPseudo();

    for(;;)
    {
        std::cout << R"(
        [1] Lancer une partie
        [2] Afficher l'historique des parties jouées
        [3] Quitter le jeu

        Tapez votre choix : )";

        int choix;
        std::cin >> choix;
        std::cout << "\n";

        switch(choix)
        {
            case 1:
                demarrerPartie();
                break;
            case 2:
                afficherHistorique(partie->getScoreJoueur(),
                                   partie->getScoreOrdinateur());
                break;
            case 3:
                quitterJeu();
                break;
        }
    }
}

void IHM::afficherResultat(std::string          nomJoueurGagnant,
                           Symbole              choixGagnant,
                           Partie::ResultatDuel resultat) const
{
    std::string resultatDuel;
    switch(resultat)
    {
        case Partie::ResultatDuel::EGALITE:
            resultatDuel = "        Égalité ! ";
            break;
        case Partie::ResultatDuel::GAGNE:
            resultatDuel = "        Gagné ! ";
            break;
        case Partie::ResultatDuel::PERDU:
            resultatDuel = "        Perdu ! ";
            break;
        case Partie::ResultatDuel::INDEFINI:
            resultatDuel = "        Indéfini !!! ";
            break;
    }
    std::cout << resultatDuel << nomJoueurGagnant << " a choisi "
              << choixGagnant.getSymboleToString() << "." << std::endl;
}

void IHM::afficherHistorique(int scoreJoueur, int scoreOrdinateur) const
{
    std::cout << R"(
        --------------------------------------------------------------
    )" << std::endl;
    std::cout << "        Le score du joueur est de " << scoreJoueur
              << " point(s)" << std::endl;
    std::cout << "        Et le score de l'ordinateur est de "
              << scoreOrdinateur << " point(s)" << std::endl;
    std::cout << R"(
        --------------------------------------------------------------
    )" << std::endl;
}

std::string IHM::saisirPseudo() const
{
    std::cout << "        Tapez votre pseudo : ";
    std::string pseudo;
    std::cin >> pseudo;
    std::cout << "\n";
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