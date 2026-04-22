/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : MainWindow.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Classe principale de la fenêtre de l'application. Hérite de QMainWindow
 *  et contient le widget d'affichage de l'échiquier.
 *
 * =====================================================================
 */

#pragma once

#pragma warning(push, 0)
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#pragma warning(pop)

#include "EchiquierWidget.hpp"

namespace vue
{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(int positionDepart = 0, QWidget *parent = nullptr);

    private slots:
        void nouvellePartie();

    private:
        EchiquierWidget *echiquierWidget_ = nullptr;
    };

}