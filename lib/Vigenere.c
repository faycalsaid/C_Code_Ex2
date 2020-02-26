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
    return;
}

void dechiffre_Vigenere_flux_texte(FILE* clair, FILE* chiffre, char const* cle)
{
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
