#ifndef IHM_H
#define IHM_H

#include <string>

class Partie;

class IHM
{
  private:
    Partie *partie;

  public:
    IHM();
    ~IHM();
    void        afficherMenuPrincipal() const;
    void        demarrerPartie() const;
    std::string saisirPseudo() const;
    void        afficherHistorique() const;
    void        quitterJeu() const;
};

#endif // IHM_H