/* Ayoub Laribi et Edwin Qi Hua Yang
 * Titre du fichier : Concepteur.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Travail dirigé 3 — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *	Classe Concepteur avec constructeur, surcharges d'opérateurs et méthodes
 * =====================================================================
 */
#pragma once
#include <string>

class Concepteur
{
public:
	// TODO: Un constructeur par défaut et un constructeur paramétré.
	Concepteur() = default;
	Concepteur(const std::string &nom, int anneeNaissance, const std::string &pays)
		: nom_(nom), anneeNaissance_(anneeNaissance), pays_(pays) {}

	const std::string &getNom() const { return nom_; }
	void setNom(std::string nom) { nom_ = std::move(nom); }
	int getAnneeNaissance() const { return anneeNaissance_; }
	void setAnneeNaissance(int annee) { anneeNaissance_ = annee; }
	const std::string &getPays() const { return pays_; }
	void setPays(std::string pays) { pays_ = std::move(pays); }

private:
	std::string nom_;
	int anneeNaissance_;
	std::string pays_;
};
