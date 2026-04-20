/*
 * Edwin Qi Hua Yang
 * Titre du fichier : MainWindow.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Implémentation de la fenêtre principale. Initialise l'interface
 *  Qt et affiche le widget de l'échiquier.
 *
 * =====================================================================
 */

#pragma warning(push, 0)
#include <QVBoxLayout>
#pragma warning(pop)


#include "MainWindow.hpp"

namespace vue
{

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
    {
        auto widgetPrincipal = new QWidget(this);
        auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);

        echiquierWidget_ = new EchiquierWidget(this);
        layoutPrincipal->addWidget(echiquierWidget_);

        setCentralWidget(widgetPrincipal);
        setWindowTitle("Jeu d'échecs");
    }

}