/* Ayoub Laribi et Edwin Qi Hua Yang
 * Titre du fichier : Jeu.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Travail dirigé 3 — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *	Classe Jeu
 * =====================================================================
 */
#pragma once
#include <string>
#include <memory>
#include "Liste.hpp"

class Concepteur;

class Jeu
{
public:
	// TODO: un constructeur par défaut et un constructeur paramétré.
	Jeu(const std::string &titre, unsigned annee, const std::string &dev)
		: titre_(titre), anneeSortie_(annee), developpeur_(dev) {}

	const std::string &getTitre() const { return titre_; }
	void setTitre(std::string titre) { titre_ = std::move(titre); }
	unsigned getAnneeSortie() const { return anneeSortie_; }
	void setAnneeSortie(unsigned annee) { anneeSortie_ = annee; }
	const std::string &getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(std::string developpeur) { developpeur_ = std::move(developpeur); }

	// TODO: Pouvoir accéder à la liste de concepteurs.
	Liste<Concepteur> &getConcepteurs() { return concepteurs_; }
	const Liste<Concepteur> &getConcepteurs() const { return concepteurs_; }

	// TODO: Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.
	template <typename Critere>
	std::shared_ptr<Concepteur> trouverConcepteur(const Critere &critere) const
	{
		return concepteurs_.trouver(critere);
	}

private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	// TODO: Attribut de la liste des concepteurs du jeu
	Liste<Concepteur> concepteurs_;
};

using ListeJeux = Liste<Jeu>; // TODO: Remplacer cette définition (qui est ici juste pour que le code fourni compile) pour que ListeJeux soit une Liste<Jeu> .