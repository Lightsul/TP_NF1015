#include "modele/Roi.hpp"
#include "modele/Tour.hpp"
#include "modele/Cavalier.hpp"
#include "modele/Echiquier.hpp"

#include <functional>
#include <iostream>
#include <string>

namespace
{
    bool executerTest(const std::string &nom, const std::function<bool()> &test)
    {
        try
        {
            if (test())
            {
                std::cout << "TEST " << nom << " : OK" << std::endl;
                return true;
            }

            std::cout << "TEST " << nom << " : ECHEC" << std::endl;
            return false;
        }
        catch (const std::exception &e)
        {
            std::cout << "TEST " << nom << " : ECHEC (" << e.what() << ")" << std::endl;
            return false;
        }
        catch (...)
        {
            std::cout << "TEST " << nom << " : ECHEC (exception inconnue)" << std::endl;
            return false;
        }
    }
}

int main()
{
    int nombreSucces = 0;
    int nombreTests = 0;

    nombreTests++;
    if (executerTest("creation roi", []()
                     {
        modele::Roi::reinitialiserCompteur();
        modele::Roi roi(modele::Couleur::Blanc, 4, 4);
        return roi.obtenirColonne() == 4 && roi.obtenirRangee() == 4; }))
    {
        nombreSucces++;
    }

    nombreTests++;
    if (executerTest("maximum deux rois", []()
                     {
        modele::Roi::reinitialiserCompteur();
        modele::Roi roi1(modele::Couleur::Blanc, 4, 0);
        modele::Roi roi2(modele::Couleur::Noir, 4, 7);

        try
        {
            modele::Roi roi3(modele::Couleur::Blanc, 0, 0);
            (void)roi3;
            return false;
        }
        catch (const modele::TropDeRoisException &)
        {
            return true;
        } }))
    {
        nombreSucces++;
    }

    nombreTests++;
    if (executerTest("mouvement tour", []()
                     {
        modele::Tour tour(modele::Couleur::Blanc, 0, 0);
        return tour.estDeplacementValide(0, 5); }))
    {
        nombreSucces++;
    }

    nombreTests++;
    if (executerTest("mouvement cavalier", []()
                     {
        modele::Cavalier cavalier(modele::Couleur::Blanc, 4, 4);
        return cavalier.estDeplacementValide(6, 5); }))
    {
        nombreSucces++;
    }

    nombreTests++;
    if (executerTest("ajouter piece", []()
                     {
        modele::Echiquier echiquier;
        echiquier.ajouterPiece(
            std::make_unique<modele::Tour>(modele::Couleur::Blanc, 0, 0));
        return echiquier.obtenirPiece(0, 0) != nullptr; }))
    {
        nombreSucces++;
    }

    nombreTests++;
    if (executerTest("retirer piece", []()
                     {
        modele::Echiquier echiquier;
        echiquier.ajouterPiece(
            std::make_unique<modele::Tour>(modele::Couleur::Blanc, 0, 0));
        echiquier.retirerPiece(0, 0);
        return echiquier.obtenirPiece(0, 0) == nullptr; }))
    {
        nombreSucces++;
    }

    std::cout << "\nResume: " << nombreSucces << "/" << nombreTests << " tests OK" << std::endl;
    return (nombreSucces == nombreTests) ? 0 : 1;
}