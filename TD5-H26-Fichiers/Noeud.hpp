#pragma once
#include <gsl/pointers>
template <typename T>
class ListeLiee;
template <typename T>
class Iterateur;

template <typename T>
class Noeud
{
	friend class ListeLiee<T>;
	friend class Iterateur<T>;

public:
	// TODO: Constructeur(s).
	Noeud(const T &valeur) : valeur_(valeur) {}

private:
	// TODO: Attributs d'un noeud.
	T valeur_;
	Noeud *suivant_ = nullptr;
	Noeud *precedent_ = nullptr;
};
