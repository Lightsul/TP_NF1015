/* Ayoub Laribi et Edwin Qi Hua Yang
 * Titre du fichier : liste.hpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Travail dirigé 3 — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *	Classe Liste rendu génériques avec constructeur, surcharges d'opérateurs et méthodes
 * =====================================================================
 */

#pragma once
#include <memory>
#include <algorithm>
#include <cassert>

// TODO: Rentdre la liste générique.
template <typename T>
class Liste
{
public:
	// TODO: Constructeurs et surcharges d'opérateurs
	Liste() : nElements_(0), capacite_(0), elements_(nullptr) {};

	Liste(const Liste<T> &autre) : nElements_(autre.nElements_), capacite_(autre.capacite_)
	{
		if (autre.nElements_ > 0)
		{
			elements_ = std::make_unique<std::shared_ptr<T>[]>(nElements_);
			for (unsigned i = 0; i < nElements_; ++i)
			{
				elements_[i] = autre.elements_[i];
			}
		}
		else
		{
			elements_ = nullptr;
		}
	}

	~Liste() = default;

	std::shared_ptr<T> &operator[](unsigned index)
	{
		assert(index < nElements_);
		return elements_[index];
	}

	const std::shared_ptr<T> &operator[](unsigned index) const
	{
		assert(index < nElements_);
		return elements_[index];
	}

	Liste &operator=(const Liste<T> &autre)
	{
		if (this != &autre)
		{
			nElements_ = autre.nElements_;
			capacite_ = autre.nElements_;
			if (nElements_ > 0)
			{
				elements_ = std::make_unique<std::shared_ptr<T>[]>(nElements_);
				for (unsigned i = 0; i < nElements_; ++i)
					elements_[i] = autre.elements_[i];
			}
			else
			{
				elements_ = nullptr;
			}
		}
		return *this;
	}

	// TODO: Méthode pour ajouter un élément à la liste
	void ajouterElement(const std::shared_ptr<T> &element)
	{
		if (nElements_ == capacite_)
		{
			changerCapacite(std::max(1U, capacite_ * 2));
		}
		elements_[nElements_++] = element;
	}

	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const { return nElements_; }
	unsigned getCapacite() const { return capacite_; }

	// TODO: Méthode pour changer la capacité de la liste
	void changerCapacite(unsigned nouvelleCapacite)
	{
		assert(nouvelleCapacite >= nElements_);
		auto nouvelleListe = std::make_unique<std::shared_ptr<T>[]>(nouvelleCapacite);

		for (unsigned i = 0; i < nElements_; ++i)
		{
			nouvelleListe[i] = elements_[i];
		}

		elements_ = std::move(nouvelleListe);
		capacite_ = nouvelleCapacite;
	}
	// TODO: Méthode pour trouver un élément selon un critère (lambda).
	template <typename Critere>
	std::shared_ptr<T> trouver(const Critere &critere) const
	{
		for (unsigned i = 0; i < nElements_; ++i)
		{
			if (critere(*elements_[i]))
			{
				return elements_[i];
			}
		}
		return nullptr;
	}

private:
	unsigned nElements_;
	unsigned capacite_;
	// TODO: Attribut contenant les éléments de la liste.
	std::unique_ptr<std::shared_ptr<T>[]> elements_;
};
