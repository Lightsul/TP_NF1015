/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : EchiquierWidget.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Widget Qt pour l'affichage et l'interaction avec l'échiquier.
 *  Gère le rendu graphique et les événements souris pour les
 *  déplacements des pièces.
 *
 * =====================================================================
 */

#pragma once

#pragma warning(push, 0)
#include <QWidget>
#include <QMessageBox>
#pragma warning(pop)

#include <vector>
#include <utility>

#include "modele/Echiquier.hpp"
#include "modele/Roi.hpp"
#include "modele/Tour.hpp"
#include "modele/Cavalier.hpp"

namespace vue
{

    class EchiquierWidget : public QWidget
    {
        Q_OBJECT

    public:
        explicit EchiquierWidget(QWidget *parent = nullptr);
        void reinitialiser(int positionDepart = 0);

    protected:
        void paintEvent(QPaintEvent *event) override;
        void mousePressEvent(QMouseEvent *event) override;

    private:
        void ajouterRoi(modele::Couleur couleur, int colonne, int rangee);
        void ajouterTour(modele::Couleur couleur, int colonne, int rangee);
        void ajouterCavalier(modele::Couleur couleur, int colonne, int rangee);

        modele::Echiquier echiquier_;
        modele::Piece *pieceSelectionnee_ = nullptr;
        int colonneSelectionnee_ = 0;
        int rangeeSelectionnee_ = 0;
        static const int tailleCasePixels_ = 80;
        static const int taillePolicePixels_ = 60;

        bool mouvementInvalide_ = false;
        int colonneInvalide_ = 0;
        int rangeeInvalide_ = 0;
        modele::Couleur tourJoueur_ = modele::Couleur::Blanc;
        std::vector<std::pair<int, int>> casesAccessibles_;
    };

}