#include "modele/Roi.hpp"
#include "modele/Tour.hpp"
#include "modele/Cavalier.hpp"
#include "modele/Echiquier.hpp"

#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

namespace
{
    void assertTest(bool condition, const std::string &message)
    {
        if (!condition)
        {
            throw std::runtime_error(message);
        }
    }

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
        assertTest(roi.obtenirColonne() == 4, "colonne du roi invalide");
        assertTest(roi.obtenirRangee() == 4, "rangee du roi invalide");
        return true; }))
    {
        nombreSucces++;
    }

    nombreTests++;
    if (executerTest("maximum deux rois", []()
                     {
        modele::Roi::reinitialiserCompteur();
        modele::Roi roi1(modele::Couleur::Blanc, 4, 0);
        modele::Roi roi2(modele::Couleur::Noir, 4, 7);
        (void)roi1;
        (void)roi2;

        try
        {
            modele::Roi roi3(modele::Couleur::Blanc, 0, 0);
            (void)roi3;
            assertTest(false, "une 3e instance de roi a ete creee");
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
        assertTest(tour.estDeplacementValide(0, 5), "deplacement de tour invalide");
        return true; }))
    {
        nombreSucces++;
    }

    nombreTests++;
    if (executerTest("mouvement cavalier", []()
                     {
        modele::Cavalier cavalier(modele::Couleur::Blanc, 4, 4);
        assertTest(cavalier.estDeplacementValide(6, 5), "deplacement de cavalier invalide");
        return true; }))
    {
        nombreSucces++;
    }

    nombreTests++;
    if (executerTest("ajouter piece", []()
                     {
        modele::Echiquier echiquier;
        echiquier.ajouterPiece(
            std::make_unique<modele::Tour>(modele::Couleur::Blanc, 0, 0));
        assertTest(echiquier.obtenirPiece(0, 0) != nullptr, "piece non ajoutee");
        return true; }))
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
        assertTest(echiquier.obtenirPiece(0, 0) == nullptr, "piece non retiree");
        return true; }))
    {
        nombreSucces++;
    }

    std::cout << "\nResume: " << nombreSucces << "/" << nombreTests << " tests OK" << std::endl;
    return (nombreSucces == nombreTests) ? 0 : 1;
}