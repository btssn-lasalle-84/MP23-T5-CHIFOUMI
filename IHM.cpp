#include "IHM.h"
#include "Joueur.h"
#include <string>
#include <iostream>

IHM::IHM()
{
}

void IHM::menuPrincipal()
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
        ------------------------------------------------------------------------------------
    )" << std::endl;

    std::cout << R"(
        Bienvenue sur le Chifoumi !

        [1] Lancer une partie
        [2] Afficher l'historique des parties jouées
        [3] Quitter le jeu

        Tapez votre choix :
    )"  << std::endl;

int choix;
    std::cin >> choix;

    IHM ihm;

    switch(choix)
    {
        case 1:
            ihm.demarrerPartie();
            break;
        case 2:
            ihm.afficherHistorique();
            break;
        case 3:
            ihm.quitterJeu();
            break;
    }
}

void IHM::demarrerPartie()
{
}
void IHM::choixPseudo()
{
    std::cout << "Tapez votre pseudo : " << std::endl;
    std::string pseudo;
    std::cin >> pseudo;
    Joueur joueur(pseudo);
    std::cout << "Votre pseudo est :" << joueur.getPseudo() << std::endl;
}

void IHM::afficherHistorique()
{
}

void IHM::quitterJeu()
{
}