#include "Vigenere.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

char* chiffre_Vigenere(char* clair, char const* cle)
{
    int i=0, j=0;
    char c;
    while(clair[i] != '\0')
    {   
        j = j% strlen(cle);
        c = cle[j];   
        if(clair[i] >= 'A' && clair[i]<='Z'){   //Uppercases    
            clair[i] = (((clair[i]-'A') + (c - 'a'))%26)+'A';
            ++j;
            
        }
        else if(clair[i] >= 'a' && clair[i]<='z'){       //Lowercases
            clair[i] = (((clair[i]-'a') + (c - 'a'))%26)+'a';
            ++j;

            
        }
        ++i;
    }

    return clair;
}

char* dechiffre_Vigenere(char* chiffre, char const* cle)
{
    int i=0, j=0;
    char c;
    while(chiffre[i] != '\0')
    {   
        j = j% strlen(cle);
        c = cle[j];   
        if(chiffre[i] >= 'A' && chiffre[i]<='Z'){   //Uppercases    
            chiffre[i] = (((chiffre[i]-'A') - (c - 'a') +26)%26)+'A';
            ++j;
            
        }
        else if(chiffre[i] >= 'a' && chiffre[i]<='z'){       //Lowercases
            chiffre[i] = (((chiffre[i]-'a') - (c - 'a') +26)%26)+'a';
            ++j;

            
        }
        ++i;
    }

    return chiffre;
}

void chiffre_Vigenere_flux_texte(FILE* chiffre, FILE* clair, char const* cle)
{
    char* readChar =NULL;
    int size = 0;

    if (clair)
	{   // File Size
		fseek(clair, 0L, SEEK_END);
		size = ftell(clair);
		rewind(clair);

		readChar = (char *)malloc((size + 1) * sizeof(char));

		//Char read one by one
		for (int i = 0; i < size; i++)
		{
			readChar[i] = (char)fgetc(clair); 
		}													
		readChar[size] = '\0';

		fclose(clair);
	}else{
		printf("Error File Reading\n");
	}

    readChar = chiffre_Vigenere(readChar,cle);
    fwrite(readChar, sizeof(char), size, chiffre);
    fclose(chiffre);


    return;
}

void dechiffre_Vigenere_flux_texte(FILE* clair, FILE* chiffre, char const* cle)
{   
    char* readChar =NULL;
    int size = 0;

    if (chiffre)
	{   // File Size
		fseek(chiffre, 0L, SEEK_END);
		size = ftell(chiffre);
		rewind(chiffre);

		readChar = (char *)malloc((size + 1) * sizeof(char));

		//Char read one by one
		for (int i = 0; i < size; i++)
		{
			readChar[i] = (char)fgetc(chiffre);
		}												
		readChar[size] = '\0';

		fclose(chiffre);
	}else{
		printf("Error Reading File\n");
	}

    readChar = dechiffre_Vigenere(readChar,cle);
    fwrite(readChar, sizeof(char), size, clair);
    fclose(clair);
    return;
}

void chiffre_Vigenere_flux_binaire(FILE* chiffre, FILE* clair, char const* cle)
{
    return;
}

void dechiffre_Vigenere_flux_binaire(FILE* clair, FILE* chiffre, char const* cle)
{
    return;
}

