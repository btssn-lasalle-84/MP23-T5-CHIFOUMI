#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur
{
    private:
    std::string pseudo;

    public:
    Joueur();
    Joueur(std::string pseudo);

    std::string getPseudo() const;
    void setPseudo(std::string pseudo);
};

#endif // JOUEUR_H