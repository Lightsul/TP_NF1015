/*
 * Edwin Qi Hua Yang
 * Titre du fichier : DeplacementTemporaire.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Classe RAII qui effectue un déplacement temporaire d'une pièce.
 *  Restaure automatiquement la position initiale lors de la destruction.
 *  Utilisée pour tester les mouvements sans modification définitive.
 *
 * =====================================================================
 */

#pragma once

#include "Piece.hpp"

namespace modele
{

	class DeplacementTemporaire
	{
	public:
		DeplacementTemporaire(Piece &piece, int colonneDestination, int rangeeDestination)
			: piece_(piece), colonneOriginale_(piece.obtenirColonne()), rangeeOriginale_(piece.obtenirRangee())
		{
			piece_.deplacerVers(colonneDestination, rangeeDestination);
		}

		~DeplacementTemporaire()
		{
			piece_.deplacerVers(colonneOriginale_, rangeeOriginale_);
		}

		DeplacementTemporaire(const DeplacementTemporaire &) = delete;
		DeplacementTemporaire &operator=(const DeplacementTemporaire &) = delete;

	private:
		Piece &piece_;
		int colonneOriginale_ = 0;
		int rangeeOriginale_ = 0;
	}
}