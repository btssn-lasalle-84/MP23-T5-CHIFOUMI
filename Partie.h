#ifndef PARTIE_H
#define PARTIE_H

#include <string>

class Partie
{
  private:
    unsigned int nbParties;

  public:
    Partie();
    Partie(unsigned int nbParties);

    unsigned int getNbParties();
    void         setNbParties(unsigned int nbParties);

    void demarrer();
};

#endif // PARTIE_H