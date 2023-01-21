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
    afficherChoixVariante();
    int numeroVariante = saisirVariante();
    partie->setNumeroVariante(numeroVariante);
    unsigned int nbManches = saisirNbManches();
    partie->setNbManches(nbManches);
    effacerEcran();
    partie->demarrer();
    appuyerPourRetournerMenu();
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
    std::cout << "\n                        Variante Classique : \n";

    std::cout << R"(
        Deux joueurs choisissent simultanément un des trois coups possibles en le symbolisant de la main. Ils ont le choix entre la pierre, la feuille, et les ciseaux :
            - La pierre bat les ciseaux en les émoussant
            - La feuille bat la pierre en l’enveloppant
            - Les ciseaux battent la feuille en la coupant
        Ainsi chaque coup bat un autre coup, fait match nul contre le deuxième (son homologue) et est battu par le troisième.

        Il existe plusieurs versions du Chifoumi mais pierre-feuille-ciseaux est la version classique du jeu  )" << std::endl;
    appuyerPourRetournerMenu();
}

void IHM::afficherRegleVariante() const
{
    std::cout << "\n                        Variante Galaxie Acarien : \n";
    std::cout << R"(
        Deux joueurs choisissent simultanément un des cinq coups possibles en le symbolisant de la main. Ils ont le choix entre la pierre, la feuille, les ciseaux, la galaxie, l'acarien
            - La pierre bat les ciseaux en les émoussant
            - La feuille bat la pierre en l’enveloppant
            - Les ciseaux battent la feuille en la coupant
            - La galaxie détruit la totalité des objets sauf l'acarien
            - L'acarien Bat la galaxie mais se fait tuer par tout les objets
         )" << std::endl;
    appuyerPourRetournerMenu();
}

void IHM::afficherChoixVariante() const
{
    std::cout << R"(
        [1] Variante Classique
        [2] Variante Galaxie Acarien

        Tapez votre choix : )";
}
void IHM::afficherChoixSymbole() const
{
    std::cout << "\n\n        Manche " << partie->getNumeroManche() + 1 << " :"
              << std::endl;
    std::cout << "\n        Vous avez le choix entre :" << std::endl;
    std::cout << "        La Pierre   [1]" << std::endl;
    std::cout << "        La Feuille  [2]" << std::endl;
    std::cout << "        Le Ciseaux  [3]" << std::endl;
    std::cout << "\n        Tapez votre choix : ";
}

void IHM::afficherChoixSymboleVariante() const
{
    std::cout << "\n\n        Manche " << partie->getNumeroManche() + 1 << " :"
              << std::endl;
    std::cout << "\n        Vous avez le choix entre :" << std::endl;
    std::cout << "        La Pierre   [1]" << std::endl;
    std::cout << "        La Feuille  [2]" << std::endl;
    std::cout << "        Le Ciseaux  [3]" << std::endl;
    std::cout << "        La Galaxie  [4]" << std::endl;
    std::cout << "        L'Acarien   [5]" << std::endl;
    std::cout << "\n        Tapez votre choix : ";
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

    std::cout << "        Version : " << NUMERO_VERSION << std::endl;
    std::cout << R"(
        Bienvenue sur le Chifoumi !)";

    std::string pseudo = saisirPseudo();
    joueur->setPseudo(pseudo);

    bool continuerJeu = true;

    while(continuerJeu == true)
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
                effacerEcran();
                afficherHistorique(partie->getScoreManchesJoueur(),
                                   partie->getScoreManchesOrdinateur(),
                                   partie->getNbEgalitesManches(),
                                   partie->getScorePartiesJoueur(),
                                   partie->getScorePartiesOrdinateur(),
                                   partie->getNbEgalitesParties());
                effacerEcran();
                break;
            case 3:
                determinerRegleAMontrer();
                effacerEcran();
                break;
            case 4:
                quitterJeu();
                continuerJeu = false;
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
            resultatDuel = "\n        Manche gagnée, ";
            break;
        case Partie::ResultatDuel::PERDU:
            resultatDuel = "\n        Manche perdue, ";
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
                  << choixOrdinateur.getSymboleToString() << " !!!\n";
    }
    else if(resultat == Partie::ResultatDuel::PERDU)
    {
        std::cout << "\n"
                  << resultatDuel << choixOrdinateur.getSymboleToString()
                  << " bat " << choixJoueur.getSymboleToString() << " :(\n";
    }
    else
        std::cout << "\n"
                  << resultatDuel << joueur->getPseudo()
                  << " et l'ordinateur ont tous les deux choisi "
                  << choixJoueur.getSymboleToString() << " ! \n"
                  << std::endl;

    std::cout
      << "\n        "
         "--------------------------------------------------------------";
}

void IHM::afficherHistorique(int scoreManchesJoueur,
                             int scoreManchesOrdinateur,
                             int nbEgalitesManches,
                             int scorePartiesJoueur,
                             int scorePartiesOrdinateur,
                             int nbEgalitesParties) const
{
    std::cout << R"(
        --------------------------------------------------------------
    )" << std::endl;
    std::cout << "        Sur la dernière partie :\n\n";
    std::cout << "        " << joueur->getPseudo() << " a gagné "
              << scoreManchesJoueur << " manche(s)" << std::endl;
    std::cout << "        L'ordinateur a gagné " << scoreManchesOrdinateur
              << " manche(s)" << std::endl;
    std::cout << "        Et il y a eu " << nbEgalitesManches << " égalité(s)"
              << std::endl;
    std::cout << R"(
        --------------------------------------------------------------
    )" << std::endl;

    std::cout << R"(
        --------------------------------------------------------------
    )" << std::endl;
    std::cout << "        " << joueur->getPseudo() <<" a gagné " << scorePartiesJoueur
              << " partie(s)" << std::endl;
    std::cout << "        L'ordinateur a gagné " << scorePartiesOrdinateur
              << " partie(s)" << std::endl;
    std::cout << "        Vous avez fait " << nbEgalitesParties << " égalité(s)"
              << std::endl;
    std::cout << R"(
        --------------------------------------------------------------
    )" << std::endl;

    appuyerPourRetournerMenu();
}

std::string IHM::saisirPseudo() const
{
    std::cout << "        Tapez votre pseudo : ";
    std::string pseudo;
    std::cin >> pseudo;
    return pseudo;
}

Symbole IHM::saisirSymbole() const
{
    int choixJoueur;
    std::cin >> choixJoueur;
    return Symbole(choixJoueur - 1);
}

int IHM::saisirNbManches() const
{
    std::cout
      << "\n        Tapez le nombre de manches que vous voulez jouer : ";
    unsigned int nbManches = 0;
    std::cin >> nbManches;
    return nbManches;
}

int IHM::saisirVariante() const
{
    int numeroVariante;
    std::cin >> numeroVariante;
    return numeroVariante;
}

void IHM::determinerRegleAMontrer() const
{
    std::cout << R"(
        [1] Les règles classique (Pierre,Feuille,Ciseaux)
        [2] Les règles de la variante (Pierre,Feuille,Ciseaux,Galaxie,Acarien)

        Tapez votre choix : )";

    int regleAMontrer;
    std::cin >> regleAMontrer;
    switch(regleAMontrer)
    {
        case 1:
            afficherRegles();
            break;
        case 2:
            afficherRegleVariante();
            break;
        default:
            afficherMenuPrincipal();
    }
}

void IHM::appuyerPourRetournerMenu() const
{
    std::cout << "\n        Appuyez sur n'importe quelle touche, puis 'Entrée'"
                 ", pour retourner au menu principal : ";
    std::string retourAuMenu;
    std::cin >> retourAuMenu;
}

void IHM::effacerEcran() const
{
    system("clear");
}