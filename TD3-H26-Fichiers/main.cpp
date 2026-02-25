/*
 * Ayoub Laribi et Edwin Qi Hua Yang
 * Titre du fichier : main.cpp
 *
 * ===================== COURS ET TRAVAIL ==============================
 *
 * INF1015 – Programmation orientée objet avancée
 * Travail dirigé 3 — Hiver 2026
 *
 * ===================== DESCRIPTION DU FICHIER ========================
 *
 *  Fichier faisant partie de l’implémentation du TD3.
 *  Contient les structures, classes ou fonctions nécessaires
 *  à la gestion des jeux, concepteurs et listes génériques.
 *
 * =====================================================================
 */

#include <iostream>
#include <fstream>
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
using namespace std;

// TODO: Vos surcharges d'opérateur <<

std::ostream &operator<<(std::ostream &os, const Concepteur &concepteur)
{
	os << concepteur.getNom() << "," << concepteur.getAnneeNaissance() << "," << concepteur.getPays();
	return os;
}

std::ostream &operator<<(std::ostream &os, const Jeu &jeu)
{
	os << "Titre: " << jeu.getTitre() << endl;
	os << "Date de sortie: " << jeu.getAnneeSortie() << endl;
	os << "Developpeur: " << jeu.getDeveloppeur() << endl;
	os << "Concepteurs: " << endl;

	const auto &concepteurs = jeu.getConcepteurs();
	for (unsigned i = 0; i < concepteurs.size(); ++i)
	{
		os << *concepteurs[i] << endl;
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, const ListeJeux &lj)
{
	for (unsigned i = 0; i < lj.size(); ++i)
	{
		os << *lj[i] << endl;
		os << "----------------------------------------" << endl;
	}
	return os;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
#pragma endregion

	ListeJeux listeJeux = creerListeJeux("jeux.bin");
	static const string ligneSeparation = "\n\033[92m"
										  "══════════════════════════════════════════════════════════════════════════"
										  "\033[0m\n";

	// TODO: L'affichage de listeJeux et l'écriture dans le fichier devraient fonctionner.

	// Test 4
	cout << ligneSeparation << "--- TEST POINT 4 : Acces par index ---" << endl;

	cout << "Titre du jeu à l'indice 2 : " << listeJeux[2]->getTitre() << endl;
	cout << "Concepteur à l'indice 1 du jeu 2 : " << listeJeux[2]->getConcepteurs()[1]->getNom() << endl;

	cout << ligneSeparation << endl;

	// Test 5
	cout << "--- TEST POINT 5 : Recherche par Lambda ---" << endl;

	auto critere = [](const Concepteur &c)
	{ return c.getNom() == "Yoshinori Kitase"; };

	shared_ptr<Concepteur> concepteur0 = listeJeux[0]->trouverConcepteur(critere);
	shared_ptr<Concepteur> concepteur1 = listeJeux[1]->trouverConcepteur(critere);

	cout << "Nom trouve : " << concepteur0->getNom() << endl;
	cout << "Adresse J0 : " << concepteur1.get() << " | Adresse J1 : " << concepteur1.get() << endl;

	cout << ligneSeparation;

	// Test 6
	cout << "--- TEST POINT 6 : Affichage console ---" << endl;
	cout << listeJeux;

	ofstream fichier("sortie.txt");
	fichier << listeJeux;
	fichier.close();

	cout << ligneSeparation;
	// TODO: Compléter le main avec les tests demandés.
	// Test 7
	cout << "--- TEST POINT 7 ---" << endl;

	Jeu copieJeu = *listeJeux[2];
	copieJeu.getConcepteurs()[1] = listeJeux[0]->getConcepteurs()[0];

	cout << "Original (Jeu 2) :" << endl
		 << *listeJeux[2] << endl;
	cout << "Copie modifiee :" << endl
		 << copieJeu << endl;
	cout << "Adresse original : " << listeJeux[2]->getConcepteurs()[0].get() << endl;
	cout << "Adresse copie    : " << copieJeu.getConcepteurs()[0].get() << endl;

	cout << ligneSeparation;
	// TODO: S'assurer qu'aucune ligne de code est non couverte.
	// NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	// NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.
}