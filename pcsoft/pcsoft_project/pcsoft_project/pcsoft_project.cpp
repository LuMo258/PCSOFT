// by MOREL Ludovic

#include <iostream>
#include <Windows.h>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>



using namespace std;


//methode permettant d'afficher les occurrences
void display_occurrence(vector<int>  occurrence, vector<char>  letter)
{
	cout << endl;
	for (size_t i = 0; i < letter.size() && i < occurrence.size(); i++)
	{
		cout << letter[i]; cout << "=" << occurrence[i] << endl;
	}
}

//fonction inversant les mots, on trie les phrases par mots grace à istringstream et on insert simplement ces mots dans un nouveau string 
string invert_sentence(string sentence) 
{
	cout << endl << "Inversion de phrase:" << endl;
	istringstream selector(sentence);
	string word;
	string newword = "";
	while (selector >> word) {
		newword.insert(0, word + " ");
	}

	return newword;
}

//partie qui permet de traiter les occurrences
void stage2_occurrence(string newword)
{


	vector<int>  occurrence;
	vector<char> letter;


	int compt = 0;

	cout << endl << endl << "Afficher le nombre d'occurrence de chaque lettre: Triage par lettre" << endl;

	for (char charac = 33; charac <= 126 ; charac++) // on parcourt les characters 33 à 126 pour tester les occurrences présentent dans newword
	{
		size_t oc = count(newword.begin(), newword.end(), charac);
		if (oc > 0) {

			//on insert oc et charac dans deux vecteurs pour pouvoir l'afficher et pouvoir manipuler leur valeur plus facilement
			occurrence.push_back(oc);
			letter.push_back(charac);
			

		}

	}

	display_occurrence(occurrence, letter); //affichage des occurrences par lettres

	cout << endl << endl;

	cout << "Triage par occurrence" << endl;

	bool changement = true;
	while (changement == true)
	{
		changement = false;
		compt = 0;
		for (int x : occurrence) //pour toutes les valeurs comprises dans occurrences on fait:
		{
			if (compt != 0) {
				if (occurrence[compt] > occurrence[compt - 1]) // un test pour savoir si la valeur en dessous et plus grande, dans ce cas on inverse ces valeurs
				{
					changement = true; // on indique qu'on a effectué un changement permettant de repeter notre boucle jusqu'a ce qu'on est un triage opérationnel
					int octmp = occurrence[compt];
					int octmp1 = occurrence[compt - 1];
					occurrence[compt] = octmp1;
					occurrence[compt - 1] = octmp;

					char letmp = letter[compt];
					char letmp1 = letter[compt - 1];
					letter[compt] = letmp1;
					letter[compt - 1] = letmp;
				}
			}
			compt++;
		}
	}
	display_occurrence(occurrence, letter); // on affiche le resultat =)

}



int main(int)
{

	// on appelle les méthode de façon à avoir ce qu'y est demandé.
	cout << "Entrez une phrase > ";
	string sentence;
	
	getline(std::cin, sentence);
	string newword = invert_sentence(sentence);
	cout << newword; 

	stage2_occurrence(newword);

	while (cin >> sentence) { // une boucle infini pour ne pas quitter le programme accidentellement
		cout << "END";

	}
	return 0;
}

