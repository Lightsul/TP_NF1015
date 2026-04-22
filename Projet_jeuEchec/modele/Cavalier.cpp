/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : Cavalier.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Implémentation de la classe Cavalier. Valide les déplacements en L
 *  et fournit le symbole Unicode du cavalier.
 *
 * =====================================================================
 */

#include "Cavalier.hpp"
#include <cstdlib>

namespace modele
{

    Cavalier::Cavalier(Couleur couleur, int colonne, int rangee) : Piece(couleur, colonne, rangee) {}

    bool Cavalier::estDeplacementValide(int colonneDestination, int rangeeDestination) const
    {
        int deltaColonne = std::abs(colonneDestination - obtenirColonne());
        int deltaRangee = std::abs(rangeeDestination - obtenirRangee());

        return ((deltaColonne == 2) && (deltaRangee == 1)) || ((deltaColonne == 1) && (deltaRangee == 2));
    }
    std::string Cavalier::obtenirSymbole() const
    {
        return obtenirCouleur() == Couleur::Blanc ? "\u2658" : "\u265E";
    }
}