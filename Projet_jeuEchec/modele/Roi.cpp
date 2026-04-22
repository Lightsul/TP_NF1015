/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : Roi.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Implémentation de la classe Roi. Gère la validation des mouvements
 *  du roi (une case dans toutes les directions) et l'allocation/libération
 *  des instances avec contrôle du nombre maximum.
 *
 * =====================================================================
 */

#include "Roi.hpp"
#include <cstdlib>

namespace modele
{
	int Roi::nInstances_ = 0;

	Roi::Roi(Couleur couleur, int colonne, int rangee) : Piece(couleur, colonne, rangee)
	{
		nInstances_++;
		if (nInstances_ > nMaxInstances)
		{
			throw TropDeRoisException();
		}
	}

	Roi::~Roi()
	{
		nInstances_--;
	}

	bool Roi::estDeplacementValide(int colonneDestination, int rangeeDestination) const
	{
		int deltaColonne = std::abs(colonneDestination - obtenirColonne());
		int deltaRangee = std::abs(rangeeDestination - obtenirRangee());

		return deltaColonne <= 1 && deltaRangee <= 1 && (deltaColonne != 0 || deltaRangee != 0);
	}

	std::string Roi::obtenirSymbole() const
	{
		return obtenirCouleur() == Couleur::Blanc ? "\u2654" : "\u265A";
	}

}