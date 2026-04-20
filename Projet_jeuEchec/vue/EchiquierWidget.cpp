/*
 * Edwin Qi Hua Yang
 * Titre du fichier : EchiquierWidget.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Implémentation du widget d'affichage de l'échiquier. Assure le
 *  rendu graphique des pièces et la gestion des événements
 *  d'interaction utilisateur.
 *
 * =====================================================================
 */

#pragma warning(push, 0)
#include <QPainter>
#include <QMouseEvent>
#pragma warning(pop)


#include "EchiquierWidget.hpp"

namespace vue
{

    EchiquierWidget::EchiquierWidget(QWidget *parent) : QWidget(parent)
    {
        setFixedSize(modele::Echiquier::nColonnes * tailleCasePixels_,
                     modele::Echiquier::nRangees * tailleCasePixels_);

        ajouterRoi(modele::Couleur::Blanc, 4, 0);
        ajouterRoi(modele::Couleur::Noir, 4, 7);
    }

    void EchiquierWidget::ajouterRoi(modele::Couleur couleur,
                                     int colonne, int rangee)
    {
        try
        {
            echiquier_.ajouterPiece(
                std::make_unique<modele::Roi>(couleur, colonne, rangee));
        }
        catch (const modele::TropDeRoisException &e)
        {
            QMessageBox::critical(this, "Erreur", e.what());
        }
    }

    void EchiquierWidget::paintEvent(QPaintEvent *)
    {
        QPainter painter(this);

        for (int col = 0; col < modele::Echiquier::nColonnes; col++)
        {
            for (int ran = 0; ran < modele::Echiquier::nRangees; ran++)
            {
                bool casePaire = (col + ran) % 2 == 0;
                painter.fillRect(
                    col * tailleCasePixels_,
                    ran * tailleCasePixels_,
                    tailleCasePixels_,
                    tailleCasePixels_,
                    casePaire ? Qt::white : Qt::gray);

                modele::Piece *piece = echiquier_.obtenirPiece(col, ran);
                if (piece != nullptr)
                {
                    painter.drawText(
                        col * tailleCasePixels_,
                        ran * tailleCasePixels_,
                        tailleCasePixels_,
                        tailleCasePixels_,
                        Qt::AlignCenter,
                        piece->obtenirCouleur() == modele::Couleur::Blanc ? "RB" : "RN");
                }
            }
        }

        if (pieceSelectionnee_ != nullptr)
        {
            painter.setPen(QPen(Qt::red, 3));
            painter.drawRect(
                colonneSelectionnee_ * tailleCasePixels_,
                rangeeSelectionnee_ * tailleCasePixels_,
                tailleCasePixels_,
                tailleCasePixels_);
        }
    }

    void EchiquierWidget::mousePressEvent(QMouseEvent *event)
    {
        int colonne = event->x() / tailleCasePixels_;
        int rangee = event->y() / tailleCasePixels_;

        modele::Piece *pieceCible = echiquier_.obtenirPiece(colonne, rangee);

        if (pieceSelectionnee_ == nullptr)
        {
            if (pieceCible != nullptr)
            {
                pieceSelectionnee_ = pieceCible;
                colonneSelectionnee_ = colonne;
                rangeeSelectionnee_ = rangee;
            }
        }
        else
        {
            if (pieceSelectionnee_->estDeplacementValide(colonne, rangee))
            {
                echiquier_.retirerPiece(colonne, rangee);
                pieceSelectionnee_->deplacerVers(colonne, rangee);
            }
            pieceSelectionnee_ = nullptr;
        }

        update();
    }
}