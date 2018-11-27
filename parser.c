#include <bytecode/bytecode.h>
#include <bytecode/generator.h>
#include <stdlib.h>
#include <stdio.h>
/*
 * Canary VM bytecode compilation example,
 * contains type definitions of VM calls
 */
#include "cvmc.h"

int main ( int argc, char **argv )
{
    static int check = -300;
    bytecode m = new_bytecode();
    push_byte(&m, 2, 0x02, 0x04);
    bytecode e = escape_byte(check);
    printf("Dumping equation for %d\n", check);
    printf("%d = ", check);
    for ( int i = 0; i < e.length; ++ i )
    {
        printf("%d ", e.content[i]);
    }
    printf("\n");
}
