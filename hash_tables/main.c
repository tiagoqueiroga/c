#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100000

typedef struct entry_t{
    char *key;
    char *value;
    struct entry_t *next;
} entry_t;


typedef struct {
    entry_t **entries;
} ht_t;


unsigned int hash(const char *key){
    unsigned long int value =0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for(; i < key_len; ++i){
        value = value * 37 + key[i];
        printf("i:%d\n",i);
    }


    printf("value before module:%ld\n",value);

    value = value % TABLE_SIZE;

    return value;

}


ht_t *ht_create(void){
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);

    hashtable->entries = malloc(sizeof(ht_t*) * TABLE_SIZE);

    for(int i = 0; i < TABLE_SIZE; ++i){
        hashtable->entries[i] = NULL;
    }

    return hashtable;

}

void ht_set(ht_t *hashtable, const char* key, const char*value)
{
    unsigned int slot = hash(key);

    entry_t *entry = hashtable->entries[slot];

    if(entry == NULL){
        //hashtable->entries = ht_pair(key,value);
        return;
    }

}

int main(int argc, char **argv)
{
    ht_t *hash_table = ht_create();

    return 0;
}
