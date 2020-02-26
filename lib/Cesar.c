#include "Cesar.h"

#include <stddef.h>

char* chiffre_Cesar(char* clair, char const cle)
{
    int i=0;
    while(clair[i] != '\0')
    {
        if(clair[i] >= 'A' && clair[i]<='Z'){          //Uppercases
            clair[i] = (((clair[i]-'A') + (cle - 'a'))%26)+'A';
            
        }
        else if(clair[i] >= 'a' && clair[i]<='z'){       //Lowercases
            clair[i] = (((clair[i]-'a') + (cle - 'a'))%26)+'a';
            
        }
        ++i;
    }

    return clair;
}

char* dechiffre_Cesar(char* chiffre, char const cle)
{
    int i=0;
    char c;
    while(chiffre[i] != '\0')
    {
        if(chiffre[i] >= 'A' && chiffre[i]<='Z'){           
            c = chiffre[i];
            c = c - 'A';
            c = c - (cle -'a'); //The key is betwwen 'a' and 'z'
            if (c<0) c+=26; //to avoid wrong decryption
            else c = c %26;
            c = c + 'A'; //(((chiffre[i]-'a') - (cle - 'a'))%26)+'a';
            chiffre[i] = c;        
        }
        else if(chiffre[i] >= 'a' && chiffre[i]<='z'){       
            c = chiffre[i];
            c = c - 'a';
            c = c - (cle -'a');
            if (c<0) c+=26; //to avoid wrong decryption
            else c = c %26;
            c = c + 'a'; //(((chiffre[i]-'a') - (cle - 'a'))%26)+'a';
            chiffre[i] = c;
        }
        ++i;
    }
    return chiffre;
}
