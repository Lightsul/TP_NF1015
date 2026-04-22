/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : Roi.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Classe spécialisée pour le Roi au jeu d'échecs. Valide les mouvements
 *  d'une case dans toutes les directions et limite à 2 rois maximum
 *  sur le plateau via un compteur d'instances statique.
 *
 * =====================================================================
 */

#pragma once

#include "Piece.hpp"
#include <stdexcept>

namespace modele
{

	class TropDeRoisException : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "Erreur : plus de 2 rois sur l'échiquier.";
		}
	};

	class Roi : public Piece
	{
	public:
		Roi(Couleur couleur, int colonne, int rangee);
		~Roi();

		bool estDeplacementValide(int colonneDestination, int rangeeDestination) const override;
		std::string obtenirSymbole() const override;
		static void reinitialiserCompteur() { nInstances_ = 0; }

	private:
		static int nInstances_;
		static const int nMaxInstances = 2;
	};

}