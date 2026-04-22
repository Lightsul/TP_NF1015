/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : main.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
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

#include "vue/FenetreDemarrage.hpp"
#include "vue/MainWindow.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	vue::FenetreDemarrage fenetreDemarrage;
	if (fenetreDemarrage.exec() != QDialog::Accepted)
		return 0;

	int positionChoisie = fenetreDemarrage.obtenirPositionChoisie();

	vue::MainWindow fenetre(positionChoisie);
	fenetre.show();

	return app.exec();
}