#include "ROT13.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <Cesar.h>

char* chiffre_ROT13(char* clair)
{
    return chiffre_Cesar(clair, 'n');
}

char* dechiffre_ROT13(char* chiffre)
{
    return dechiffre_Cesar(chiffre, 'n');
}
