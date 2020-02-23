#include "ROT13.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

char* chiffre_ROT13(char* clair)
{
    int i=0;
    while(clair[i] != '\0')
    {
        if(clair[i]>='A' && clair[i]<='Z')
            clair[i] = (clair[i] - 'A' + 13) % 26 + 'A';
        if(clair[i]>='a' && clair[i]<='z')
            clair[i]= (clair[i] - 'a' + 13) % 26 + 'a';

        i++;
    }

  return clair;
}

char* dechiffre_ROT13(char* chiffre)
{
    return chiffre_ROT13(chiffre);
}
