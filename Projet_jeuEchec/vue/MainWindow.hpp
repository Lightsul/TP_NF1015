/*
 * Edwin Qi Hua Yang
 * Titre du fichier : MainWindow.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Projet final — Hiver 2026
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
#pragma warning(pop)

#include "EchiquierWidget.hpp"

namespace vue
{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);

    private:
        EchiquierWidget *echiquierWidget_ = nullptr;
    };
}