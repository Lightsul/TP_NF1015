/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : FenetreDemarrage.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * =====================================================================
 */
#pragma warning(push, 0)
#include <QVBoxLayout>
#include <QHBoxLayout>
#pragma warning(pop)

#include "FenetreDemarrage.hpp"

namespace vue
{

    FenetreDemarrage::FenetreDemarrage(QWidget *parent)
        : QDialog(parent)
    {
        setWindowTitle("Jeu d'échecs — Démarrage");
        setMinimumWidth(300);

        auto layoutPrincipal = new QVBoxLayout(this);

        titreLabel_ = new QLabel("Bienvenue au jeu d'échecs !", this);
        titreLabel_->setAlignment(Qt::AlignCenter);
        layoutPrincipal->addWidget(titreLabel_);

        auto positionLabel = new QLabel("Choisir une position de départ :", this);
        layoutPrincipal->addWidget(positionLabel);

        positionsComboBox_ = new QComboBox(this);
        positionsComboBox_->addItem("Position classique");
        positionsComboBox_->addItem("Roi et Tour vs Roi");
        positionsComboBox_->addItem("Roi et Cavalier vs Roi");
        layoutPrincipal->addWidget(positionsComboBox_);

        demarrerBouton_ = new QPushButton("Nouvelle partie", this);
        layoutPrincipal->addWidget(demarrerBouton_);

        QObject::connect(demarrerBouton_, &QPushButton::clicked,
                         this, &FenetreDemarrage::demarrerPartie);
    }

    int FenetreDemarrage::obtenirPositionChoisie() const
    {
        return positionChoisie_;
    }

    void FenetreDemarrage::demarrerPartie()
    {
        positionChoisie_ = positionsComboBox_->currentIndex();
        accept();
    }

}