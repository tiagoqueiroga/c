#ifndef _ENTITY_H
#define _ENTITY_H

#include <raylib.h>
#include <string.h>
#include <stdio.h>

void CreateEntity(const char *type)
{
    if (strcmp(type, "player"))
    {
        printf("create player entity\n");
    }
}

#endif