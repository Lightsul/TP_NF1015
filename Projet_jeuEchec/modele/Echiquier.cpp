/*
 * Edwin Qi Hua Yang
 * Titre du fichier : Echiquier.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Implémentation de la classe Echiquier. Gère le stockage des pièces
 *  et les opérations sur le plateau de jeu.
 *
 * =====================================================================
 */

#include "Echiquier.hpp"
#include <algorithm>

namespace modele
{

    void Echiquier::ajouterPiece(std::unique_ptr<Piece> piece)
    {
        pieces_.push_back(std::move(piece));
    }

    Piece *Echiquier::obtenirPiece(int colonne, int rangee) const
    {
        for (const auto &piece : pieces_)
        {
            if (piece->obtenirColonne() == colonne &&
                piece->obtenirRangee() == rangee)
            {
                return piece.get();
            }
        }
        return nullptr;
    }

    void Echiquier::retirerPiece(int colonne, int rangee)
    {
        auto it = std::remove_if(pieces_.begin(), pieces_.end(),
                                 [colonne, rangee](const std::unique_ptr<Piece> &piece)
                                 {
                                     return piece->obtenirColonne() == colonne && piece->obtenirRangee() == rangee;
                                 });

        pieces_.erase(it, pieces_.end());
    }
}