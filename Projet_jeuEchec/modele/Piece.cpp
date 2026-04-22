/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : Piece.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Implémentation des méthodes de la classe Piece. Gère les propriétés
 *  communes aux pièces et les opérations de déplacement.
 *
 * =====================================================================
 */

#include "Piece.hpp"

namespace modele
{

    Piece::Piece(Couleur couleur, int colonne, int rangee)
        : couleur_(couleur), colonne_(colonne), rangee_(rangee)
    {
    }

    Couleur Piece::obtenirCouleur() const
    {
        return couleur_;
    }

    int Piece::obtenirColonne() const
    {
        return colonne_;
    }

    int Piece::obtenirRangee() const
    {
        return rangee_;
    }

    void Piece::deplacerVers(int colonne, int rangee)
    {
        colonne_ = colonne;
        rangee_ = rangee;
    }

}