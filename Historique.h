#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <string>

class Historique
{
  private:
    unsigned int nbDeParties;

  public:
    Historique();
    Historique(unsigned int nbDeParties);
    unsigned int getHistorique() const;
};

#endif // HISTORIQUE_H