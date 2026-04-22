/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : Cavalier.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Classe spécialisée pour le Cavalier au jeu d'échecs. Valide les
 *  déplacements en forme de L.
 *
 * =====================================================================
 */

#pragma once

#include "Piece.hpp"

namespace modele
{

    class Cavalier : public Piece
    {
    public:
        Cavalier(Couleur couleur, int colonne, int rangee);
        ~Cavalier() = default;

        bool estDeplacementValide(int colonneDestination,
                                  int rangeeDestination) const override;

        std::string obtenirSymbole() const override;
    };

}