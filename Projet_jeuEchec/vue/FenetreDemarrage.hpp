/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : FenetreDemarrage.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * =====================================================================
 */
#pragma once

#pragma warning(push, 0)
#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#pragma warning(pop)

namespace vue
{

    class FenetreDemarrage : public QDialog
    {
        Q_OBJECT

    public:
        explicit FenetreDemarrage(QWidget *parent = nullptr);

        int obtenirPositionChoisie() const;

    private slots:
        void demarrerPartie();

    private:
        QComboBox *positionsComboBox_ = nullptr;
        QPushButton *demarrerBouton_ = nullptr;
        QLabel *titreLabel_ = nullptr;

        int positionChoisie_ = 0;
    };

}