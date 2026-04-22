/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : EchiquierWidget.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
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
#include <QTimer>
#pragma warning(pop)

#include "EchiquierWidget.hpp"

namespace vue
{

    EchiquierWidget::EchiquierWidget(QWidget *parent) : QWidget(parent)
    {
        setFixedSize(modele::Echiquier::nColonnes * tailleCasePixels_,
                     modele::Echiquier::nRangees * tailleCasePixels_);

        reinitialiser(0);
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
    void EchiquierWidget::ajouterTour(modele::Couleur couleur,
                                      int colonne, int rangee)
    {
        echiquier_.ajouterPiece(
            std::make_unique<modele::Tour>(couleur, colonne, rangee));
    }

    void EchiquierWidget::ajouterCavalier(modele::Couleur couleur,
                                          int colonne, int rangee)
    {
        echiquier_.ajouterPiece(
            std::make_unique<modele::Cavalier>(couleur, colonne, rangee));
    }

    void EchiquierWidget::paintEvent(QPaintEvent *)
    {
        QString tour = (tourJoueur_ == modele::Couleur::Blanc)
                           ? "Tour : Blanc \u2654"
                           : "Tour : Noir \u265A";
        window()->setWindowTitle("Jeu d'echecs - " + tour);

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

                if (mouvementInvalide_ &&
                    col == colonneInvalide_ &&
                    ran == rangeeInvalide_)
                {
                    painter.fillRect(
                        col * tailleCasePixels_,
                        ran * tailleCasePixels_,
                        tailleCasePixels_,
                        tailleCasePixels_,
                        QColor(255, 0, 0, 150));
                }

                for (const auto &caseAccess : casesAccessibles_)
                {
                    if (caseAccess.first == col && caseAccess.second == ran)
                    {
                        painter.fillRect(
                            col * tailleCasePixels_,
                            ran * tailleCasePixels_,
                            tailleCasePixels_,
                            tailleCasePixels_,
                            QColor(0, 255, 0, 100));
                    }
                }

                modele::Piece *piece = echiquier_.obtenirPiece(col, ran);
                if (piece != nullptr)
                {
                    QFont police("Apple Symbols", taillePolicePixels_);
                    painter.setFont(police);

                    QString symbole = QString::fromStdString(piece->obtenirSymbole());

                    painter.setPen(Qt::black);
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            painter.drawText(
                                col * tailleCasePixels_ + dx,
                                ran * tailleCasePixels_ + dy,
                                tailleCasePixels_,
                                tailleCasePixels_,
                                Qt::AlignCenter,
                                symbole);
                        }
                    }

                    painter.setPen(piece->obtenirCouleur() == modele::Couleur::Blanc
                                       ? Qt::white
                                       : Qt::black);
                    painter.drawText(
                        col * tailleCasePixels_,
                        ran * tailleCasePixels_,
                        tailleCasePixels_,
                        tailleCasePixels_,
                        Qt::AlignCenter,
                        symbole);
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
        int colonne = event->position().x() / tailleCasePixels_;
        int rangee = event->position().y() / tailleCasePixels_;

        modele::Piece *pieceCible = echiquier_.obtenirPiece(colonne, rangee);

        if (pieceSelectionnee_ == nullptr)
        {
            if (pieceCible != nullptr &&
                pieceCible->obtenirCouleur() == tourJoueur_)
            {
                pieceSelectionnee_ = pieceCible;
                colonneSelectionnee_ = colonne;
                rangeeSelectionnee_ = rangee;

                casesAccessibles_.clear();
                for (int c = 0; c < modele::Echiquier::nColonnes; c++)
                {
                    for (int r = 0; r < modele::Echiquier::nRangees; r++)
                    {
                        modele::Piece *cible = echiquier_.obtenirPiece(c, r);
                        bool allie = (cible != nullptr) &&
                                     (cible->obtenirCouleur() == tourJoueur_);
                        if (pieceSelectionnee_->estDeplacementValide(c, r) && !allie)
                            casesAccessibles_.push_back({c, r});
                    }
                }
            }
        }
        else
        {
            bool caseOccupeeParAllie = (pieceCible != nullptr) &&
                                       (pieceCible->obtenirCouleur() ==
                                        pieceSelectionnee_->obtenirCouleur());

            if (pieceSelectionnee_->estDeplacementValide(colonne, rangee) &&
                !caseOccupeeParAllie)
            {
                echiquier_.retirerPiece(colonne, rangee);
                pieceSelectionnee_->deplacerVers(colonne, rangee);

                tourJoueur_ = (tourJoueur_ == modele::Couleur::Blanc)
                                  ? modele::Couleur::Noir
                                  : modele::Couleur::Blanc;
            }
            else
            {
                mouvementInvalide_ = true;
                colonneInvalide_ = colonne;
                rangeeInvalide_ = rangee;
                QTimer::singleShot(500, this, [this]()
                                   {
                mouvementInvalide_ = false;
                update(); });
            }

            pieceSelectionnee_ = nullptr;
            casesAccessibles_.clear();
        }

        update();
    }

    void EchiquierWidget::reinitialiser(int positionDepart)
    {
        echiquier_ = modele::Echiquier();
        pieceSelectionnee_ = nullptr;
        colonneSelectionnee_ = 0;
        rangeeSelectionnee_ = 0;

        if (positionDepart == 0)
        {
            ajouterRoi(modele::Couleur::Blanc, 4, 7);
            ajouterRoi(modele::Couleur::Noir, 4, 0);
            ajouterTour(modele::Couleur::Blanc, 0, 7);
            ajouterTour(modele::Couleur::Noir, 0, 0);
            ajouterCavalier(modele::Couleur::Blanc, 1, 7);
            ajouterCavalier(modele::Couleur::Noir, 1, 0);
        }
        else if (positionDepart == 1)
        {
            ajouterRoi(modele::Couleur::Blanc, 4, 7);
            ajouterRoi(modele::Couleur::Noir, 4, 0);
            ajouterTour(modele::Couleur::Blanc, 0, 7);
        }
        else if (positionDepart == 2)
        {
            ajouterRoi(modele::Couleur::Blanc, 4, 7);
            ajouterRoi(modele::Couleur::Noir, 4, 0);
            ajouterCavalier(modele::Couleur::Blanc, 1, 7);
        }

        update();
    }
}