/*
 * Edwin Qi Hua Yang
 * Titre du fichier : main.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Point d'entrée du programme. Initialise l'application Qt et affiche
 *  la fenêtre principale du jeu d'échecs.
 *
 * =====================================================================
 */

#pragma warning(push, 0)
#include <QApplication>
#pragma warning(pop)

#include "vue/MainWindow.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	vue::MainWindow fenetre;
	fenetre.show();
	return app.exec();
}