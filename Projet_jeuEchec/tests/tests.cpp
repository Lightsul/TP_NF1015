#include <gtest/gtest.h>
#include "modele/Roi.hpp"
#include "modele/Tour.hpp"
#include "modele/Cavalier.hpp"
#include "modele/Echiquier.hpp"

TEST(RoiTest, mouvementValideUneCase)
{
    modele::Roi::reinitialiserCompteur();
    modele::Roi roi(modele::Couleur::Blanc, 4, 4);
    EXPECT_TRUE(roi.estDeplacementValide(5, 4));
    EXPECT_TRUE(roi.estDeplacementValide(3, 4));
    EXPECT_TRUE(roi.estDeplacementValide(4, 5));
    EXPECT_TRUE(roi.estDeplacementValide(5, 5));
}

TEST(RoiTest, mouvementInvalide)
{
    modele::Roi::reinitialiserCompteur();
    modele::Roi roi(modele::Couleur::Blanc, 4, 4);
    EXPECT_FALSE(roi.estDeplacementValide(6, 4));
    EXPECT_FALSE(roi.estDeplacementValide(4, 4));
}

TEST(RoiTest, maximumDeuxRois)
{
    modele::Roi::reinitialiserCompteur();
    modele::Roi roi1(modele::Couleur::Blanc, 4, 0);
    modele::Roi roi2(modele::Couleur::Noir,  4, 7);
    EXPECT_THROW(modele::Roi roi3(modele::Couleur::Blanc, 0, 0),
                 modele::TropDeRoisException);
}

TEST(TourTest, mouvementValide)
{
    modele::Tour tour(modele::Couleur::Blanc, 0, 0);
    EXPECT_TRUE(tour.estDeplacementValide(7, 0));
    EXPECT_TRUE(tour.estDeplacementValide(0, 7));
}

TEST(TourTest, mouvementInvalide)
{
    modele::Tour tour(modele::Couleur::Blanc, 0, 0);
    EXPECT_FALSE(tour.estDeplacementValide(3, 3));
    EXPECT_FALSE(tour.estDeplacementValide(0, 0));
}

TEST(CavalierTest, mouvementValide)
{
    modele::Cavalier cavalier(modele::Couleur::Blanc, 4, 4);
    EXPECT_TRUE(cavalier.estDeplacementValide(6, 5));
    EXPECT_TRUE(cavalier.estDeplacementValide(5, 6));
    EXPECT_TRUE(cavalier.estDeplacementValide(2, 3));
    EXPECT_TRUE(cavalier.estDeplacementValide(3, 2));
}

TEST(CavalierTest, mouvementInvalide)
{
    modele::Cavalier cavalier(modele::Couleur::Blanc, 4, 4);
    EXPECT_FALSE(cavalier.estDeplacementValide(4, 4));
    EXPECT_FALSE(cavalier.estDeplacementValide(5, 4));
    EXPECT_FALSE(cavalier.estDeplacementValide(6, 6));
}

TEST(EchiquierTest, ajouterEtObtenirPiece)
{
    modele::Echiquier echiquier;
    echiquier.ajouterPiece(
        std::make_unique<modele::Tour>(modele::Couleur::Blanc, 0, 0));
    EXPECT_NE(echiquier.obtenirPiece(0, 0), nullptr);
    EXPECT_EQ(echiquier.obtenirPiece(1, 0), nullptr);
}

TEST(EchiquierTest, retirerPiece)
{
    modele::Echiquier echiquier;
    echiquier.ajouterPiece(
        std::make_unique<modele::Tour>(modele::Couleur::Blanc, 0, 0));
    echiquier.retirerPiece(0, 0);
    EXPECT_EQ(echiquier.obtenirPiece(0, 0), nullptr);
}