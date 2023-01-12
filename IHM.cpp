#include "IHM.h"
#include "Partie.h"
#include "Symbole.h"
#include <string>
#include <iostream>

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
        ----------------------------------------------------------------
    )" << std::endl;

    std::cout << R"(
        Bienvenue sur le Chifoumi !

        [1] Lancer une partie
        [2] Afficher l'historique des parties jouées
        [3] Quitter le jeu

        Tapez votre choix : )";

    // TODO gérer le menu avec une boucle
    int choix;
    std::cin >> choix;

    switch(choix)
    {
        case 1:
            demarrerPartie();
            break;
        case 2:
            afficherHistorique();
            break;
        case 3:
            quitterJeu();
            break;
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
            resultatDuel = "Égalité ! ";
            break;
        case Partie::ResultatDuel::GAGNE:
            resultatDuel = "Gagné ! ";
            break;
        case Partie::ResultatDuel::PERDU:
            resultatDuel = "Perdu ! ";
            break;
        case Partie::ResultatDuel::INDEFINI:
            resultatDuel = "Indéfini !!! ";
            break;
    }
    std::cout << resultatDuel << nomJoueurGagnant << " a choisi "
              << choixGagnant.getSymboleToString() << "." << std::endl;
}

void IHM::afficherHistorique() const
{
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
    std::cout << "Vous avez le choix entre :" << std::endl;
    std::cout << "La Pierre   [1]" << std::endl;
    std::cout << "La Feuille  [2]" << std::endl;
    std::cout << "Le Ciseaux  [3]" << std::endl;
}

Symbole IHM::saisirSymbole() const
{
    int choixJoueur;
    // TODO valider le choix du symbole
    std::cin >> choixJoueur;
    return Symbole(choixJoueur - 1);
}
