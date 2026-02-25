/* Ayoub Laribi et Edwin Qi Hua Yang
 * Titre du fichier : lectureFichierJeux.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Travail dirigé 3 — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *	Fonctions du TP2 avec des pointeurs intelligents.
 *
 * =====================================================================
 */

// Fonctions pour lire le fichier binaire.
#include "lectureFichierJeux.hpp"
#include <fstream>
#include <cstdint>
#include "cppitertools/range.hpp"
using namespace std;

using UInt8 = uint8_t;
using UInt16 = uint16_t;

#pragma region "Fonctions de lecture de base"
// TODO: Remplacer lireUint8 et lireUint16 par une seule fonction générique qui permet les deux, mais permettre uniquement des types qui sont is_trivially_copyable_v (un trait de type).
template <typename T>
T lireValeur(istream &fichier)
{
	static_assert(is_trivially_copyable_v<T>, "Le type doit etre trivialement copiable.");
	T valeur = 0;
	fichier.read(reinterpret_cast<char *>(&valeur), sizeof(T));
	return valeur;
}

string lireString(istream &fichier)
{
	string texte;
	texte.resize(lireValeur<uint16_t>(fichier));
	fichier.read(reinterpret_cast<char *>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
#pragma endregion

shared_ptr<Concepteur> chercherConcepteur(ListeJeux &listeJeux, const string &nom)
{
	// TODO: Compléter la fonction (équivalent de trouverDesigner du TD2).
	for (unsigned i = 0; i < listeJeux.size(); ++i)
	{
		auto trouve = listeJeux[i]->getConcepteurs().trouver([&](const Concepteur &c)
															 { return c.getNom() == nom; });
		if (trouve != nullptr)
			return trouve;
	}
	return nullptr;
}

shared_ptr<Concepteur> lireConcepteur(ListeJeux &lj, istream &f)
{
	string nom = lireString(f);
	unsigned anneeNaissance = lireValeur<uint16_t>(f);
	;
	string pays = lireString(f);

	// TODO: Compléter la fonction (équivalent de lireDesigner du TD2).
	shared_ptr<Concepteur> concepteur = chercherConcepteur(lj, nom);
	if (concepteur == nullptr)
	{
		concepteur = make_shared<Concepteur>(nom, anneeNaissance, pays);
	}
	return concepteur;
}

shared_ptr<Jeu> lireJeu(istream &f, ListeJeux &lj)
{
	string titre = lireString(f);
	unsigned anneeSortie = lireValeur<uint16_t>(f);
	;
	string developpeur = lireString(f);
	unsigned nConcepteurs = lireValeur<uint8_t>(f);
	;
	// TODO: Compléter la fonction (équivalent de lireJeu du TD2).
	auto jeu = make_shared<Jeu>(titre, anneeSortie, developpeur);

	for (unsigned int i = 0; i < nConcepteurs; i++)
		jeu->getConcepteurs().ajouterElement(lireConcepteur(lj, f));

	return jeu;
}

ListeJeux creerListeJeux(const string &nomFichier)
{
	ifstream f(nomFichier, ios::binary);
	f.exceptions(ios::failbit);
	int nElements = lireValeur<uint16_t>(f);
	// TODO: Compléter la fonction.
	ListeJeux listeJeux;
	for ([[maybe_unused]] int i : iter::range(nElements))
		listeJeux.ajouterElement(lireJeu(f, listeJeux));

	return listeJeux;
}
