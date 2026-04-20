/*
 * Edwin Qi Hua Yang
 * Titre du fichier : EchiquierWidget.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Projet final — Hiver 2026
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

#include "modele/Echiquier.hpp"
#include "modele/Roi.hpp"

namespace vue
{

    class EchiquierWidget : public QWidget
    {
        Q_OBJECT

    public:
        explicit EchiquierWidget(QWidget *parent = nullptr);

    protected:
        void paintEvent(QPaintEvent *event) override;
        void mousePressEvent(QMouseEvent *event) override;

    private:
        void ajouterRoi(modele::Couleur couleur, int colonne, int rangee);

        modele::Echiquier echiquier_;
        modele::Piece *pieceSelectionnee_ = nullptr;
        int colonneSelectionnee_ = 0;
        int rangeeSelectionnee_ = 0;
        static const int tailleCasePixels_ = 80;
    };

}