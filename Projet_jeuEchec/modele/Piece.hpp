/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : Piece.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Classe de base abstraite représentant une pièce du jeu d'échecs.
 *  Définit les propriétés communes à toutes les pièces (couleur, position)
 *  et les opérations de déplacement avec validation.
 *
 * =====================================================================
 */

#pragma once

#include <string>

namespace modele
{

    enum class Couleur
    {
        Blanc,
        Noir
    };

    class Piece
    {
    public:
        Piece(Couleur couleur, int colonne, int rangee);

        virtual ~Piece() = default;

        Couleur obtenirCouleur() const;
        int obtenirColonne() const;
        int obtenirRangee() const;

        void deplacerVers(int colonne, int rangee);

        virtual bool estDeplacementValide(int colonneDestination,
                                          int rangeeDestination) const = 0;

        virtual std::string obtenirSymbole() const = 0;

    private:
        Couleur couleur_;
        int colonne_ = 0;
        int rangee_ = 0;
    };

}