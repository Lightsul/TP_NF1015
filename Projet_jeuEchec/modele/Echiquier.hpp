/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : Echiquier.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Classe représentant l'échiquier du jeu. Gère l'ajout, la suppression
 *  et la récupération des pièces sur le plateau de 8x8 cases.
 *
 * =====================================================================
 */

#pragma once

#include "Piece.hpp"
#include <vector>
#include <memory>

namespace modele
{

    class Echiquier
    {
    public:
        static const int nColonnes = 8;
        static const int nRangees = 8;

        void ajouterPiece(std::unique_ptr<Piece> piece);
        Piece *obtenirPiece(int colonne, int rangee) const;
        void retirerPiece(int colonne, int rangee);

    private:
        std::vector<std::unique_ptr<Piece>> pieces_;
    };
}