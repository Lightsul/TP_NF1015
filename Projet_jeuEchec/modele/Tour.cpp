/*
 * Edwin Qi Hua Yang
 * Ayoub Laribi
 * Titre du fichier : Tour.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * TP6 + Projet final — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Implémentation de la classe Tour. Valide les déplacements horizontaux
 *  et verticaux ainsi que l'affichage du symbole de la tour.
 *
 * =====================================================================
 */

#include "Tour.hpp"

namespace modele
{
    Tour::Tour(Couleur couleur, int colonne, int rangee) : Piece(couleur, colonne, rangee) {}

    bool Tour::estDeplacementValide(int colonneDestination, int rangeeDestination) const
    {
        bool memeColonne = (obtenirColonne() == colonneDestination);
        bool memeRangee = (obtenirRangee() == rangeeDestination);

        return (memeColonne || memeRangee) && !(memeColonne && memeRangee);
    }
    std::string Tour::obtenirSymbole() const
    {
        return obtenirCouleur() == Couleur::Blanc ? "\u2656" : "\u265C";
    }
}