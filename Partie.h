#ifndef PARTIE_H
#define PARTIE_H

#include <string>

#define DEBUG_PARTIE

class IHM;
class Joueur;

class Partie
{
  private:
    IHM*    ihm;
    Joueur* joueur;

  public:
    Partie(IHM* ihm = nullptr);
    ~Partie();

    void demarrer();
    unsigned int choisirNbOrdinateur();
};

#endif // PARTIE_H