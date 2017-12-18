#ifndef MUSHER_H
#define MUSHER_H

#include <QString>

class Musher
{
    public:
        Musher();
        ~Musher();

    protected:

    private:
        QString nom;
        QString prenom;
        QString adresseMail;
        QString numeroAssurance;

        QString nomAssurance;
        QString adresse;
        QString codePostal;
        QString ville;
        QString nLicence;
        QChar sexe;
        QString pays;
        QString club;
        QString numeroTelephone;
        int nbRepasSuppAdultes;
        int nbRepasSuppEnfants;
        QString commentaires;


};

#endif // MUSHER_H
