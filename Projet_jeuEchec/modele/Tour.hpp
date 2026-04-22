/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : Tour.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Classe spécialisée pour la Tour au jeu d'échecs. Valide les
 *  déplacements horizontaux et verticaux.
 *
 * =====================================================================
 */

#pragma once

#include "Piece.hpp"

namespace modele
{
    class Tour : public Piece
    {
    public:
        Tour(Couleur couleur, int colonne, int rangee);
        ~Tour() = default;

        bool estDeplacementValide(int colonneDestination, int rangeeDestination) const override;
        std::string obtenirSymbole() const override;
    };
}