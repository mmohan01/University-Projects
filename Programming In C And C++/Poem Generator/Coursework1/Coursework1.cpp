#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//Michael Mohan 40020843
//this piece of coursework creates a 3 line poem with a title and that is generated randomly each time the program is run 
int main(void)
{
	//arrays of strings are declared and filled to store a number of nouns, adjectives, verbs, adverbs and prepositional phrases
	//3 complimentary arrays are also created to store the capitalised versions of the strings in the noun, adjective and adverb arrays, for the title and the first words of each line
	char nouns			  [15][10] = {"book", "cup", "goldfish", "tongue", "drug", "snake", "wrist", "computer", "watch", "fist", "volcano", "mountain", "stranger", "statement", "tiger"};
	char adjectives		  [15][11] = {"elegant", "red", "important", "lazy", "proud", "greasy", "swift", "dangerous", "accidental", "rapid", "boundless", "acrid", "illegal", "itchy", "mellow"};
	char verbs			  [15][12] = {"add", "fix", "jump", "kick", "being", "sound", "yell", "zoom", "hurt", "communicate", "desert", "dissect", "drown", "head", "vanish"};
	char adverbs		  [15][14] = {"carefully", "patiently", "abroad", "underground", "accidentally", "often", "finally", "abnormally", "carefully", "defiantly", "hopelessly", "vivaciously", "morally", "unfortunately", "fast"};
	char prepositions	  [15][21] = {"at a glance", "at risk of", "by profession", "by law", "for fear of", "from memory", "in flames", "in theory", "in unison", "on horseback", "on reflection", "out of pity", "to ones astonishment", "under arrest", "within grasp"};
	char capitalNouns	  [15][10];
	char capitalAdjectives[15][11];
	char capitalAdverbs	  [15][14];
	
	//fills the "capitalNouns" array and capitalises the initial character of each string using a for loop 
	for (int i = 0; i < 15; i++)
	{
		strcpy(capitalNouns[i], nouns[i]);
		char temp = capitalNouns[i][0];

		//converts the character to uppercase
		capitalNouns[i][0] = toupper(temp);
	}

	//fills the "capitalAdjectives" array and capitalises the initial character of each string using a for loop 
	for (int i = 0; i < 15; i++)
	{
		strcpy(capitalAdjectives[i], adjectives[i]);
		char temp = capitalAdjectives[i][0];

		//converts the character to uppercase
		capitalAdjectives[i][0] = toupper(temp);
	}

	//fills the "capitalAdverbs" array and capitalises the initial character of each string using a for loop 
	for (int i = 0; i < 15; i++)
	{
		strcpy(capitalAdverbs[i], adverbs[i]);
		char temp = capitalAdverbs[i][0];

		//converts the character to uppercase
		capitalAdverbs[i][0] = toupper(temp);
	}

	//the srand() function is used to seed the randomizer gears in the computer
	//this changes the random values each time the program is run. the value used is the time
	srand((unsigned)time(NULL));
	
	//a set of variables are declared and initialised as random numbers between 0 and 14
	//these will be used to reference the components of the numerous arrays when printing the poem
	int adjectiveR1   = rand()%15;
	int adjectiveR2   = rand()%15;
	int adjectiveR3   = rand()%15;
	int nounR1	    = rand()%15;
	int nounR2	    = rand()%15;
	int nounR3	    = rand()%15;
	int verbR1	    = rand()%15;
	int verbR2	    = rand()%15;
	int verbR3	    = rand()%15;
	int prepositionR1 = rand()%15;
	int prepositionR2 = rand()%15;
	int adverbR	    = rand()%15;

	//the poem is printed out onto the screen, using 3 adjectives, 3 nouns, 3 verbs, 2 prepositional phrases and an adverb
	//these words will be different each time the program is run, creating a different poem
	printf("\t\t\t\tA %s %s\n", capitalAdjectives[adjectiveR1], capitalNouns[nounR1]);
	printf("--------------------------------------------------------------------------------\n");
	printf("\t\tA %s %s %s %s the %s %s.\n", adjectives[adjectiveR1], nouns[nounR1], verbs[verbR1], prepositions[prepositionR1], adjectives[adjectiveR2], nouns[nounR2]);
	printf("\t\t\t%s the %s %s.\n", capitalAdverbs[adverbR], nouns[nounR1], verbs[verbR2]);
	printf("\t\tThe %s %s %s a %s %s.\n\n", nouns[nounR2], verbs[verbR3], prepositions[prepositionR2], adjectives[adjectiveR3], nouns[nounR3]);	

	// Keeps the command window open
	system ("PAUSE");
	return 0;
}