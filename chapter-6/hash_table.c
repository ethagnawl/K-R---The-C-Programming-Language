#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *key;
    char *value;
};

static struct nlist *hash_table[HASHSIZE];

unsigned hash(char *key) {
    unsigned hashed_key;
    for (hashed_key = 0; *key != '\0'; key++) {
        hashed_key = *key + 31 * hashed_key;
    }
    return hashed_key % HASHSIZE;
}

struct nlist *lookup(char *key) {
    struct nlist *result;

    // I wish the authors were more clear about the _why_ of this hash collision
    // handling code.
    for (result = hash_table[hash(key)]; result != NULL; result = result->next) {
        if (strcmp(key, result->key) == 0) {
            return result;
        }
    }

    return NULL;
}

struct nlist *install(char *key, char *value) {
    struct nlist *result;
    unsigned hashed_key;

    if ((result = lookup(key)) == NULL) {
        result = (struct nlist *) malloc(sizeof(*result));
        if (result == NULL || (result->key = strdup(key)) == NULL) {
            return NULL;
        }
        hashed_key = hash(key);
        result->next = hash_table[hashed_key];
        hash_table[hashed_key] = result;
    } else {
        free((void *) result->value);
    }

    if ((result->value = strdup(value)) == NULL) {
        return NULL;
    }

    return result;
}

// with assistance from:
// http://www.eng.uerj.br/~fariasol/disciplinas/LABPROG/C_language/Kernighan_and_Ritchie/solved-exercises/solved-exercises.html/krx605.html
int uninstall(char *key) {
    struct nlist * np1,
                 * np2;

    // not found, nothing to do
    if ((np1 = lookup(key)) == NULL) {
        return 1;
    } else {
        for (np1 = np2 = hash_table[hash(key)];
             np1 != NULL;
             np2 = np1, np1 = np1->next) {

            //  key found
            if (strcmp(key, np1->key) == 0) {
                // Remove node from list
                // I'm unclear as to when this `if` wouldn't be the case.
                // Perhaps in the case of a hash collision?
                if (np1 == np2) {
                    hash_table[hash(key)] = np1->next;
                } else {
                    np2->next = np1->next;
                }

                free(np1->key);
                free(np1->value);
                free(np1);

                return 0;
            }
        }
    }

    return 1;
}

int main() {
    install("food", "brood");
    install("foo", "bar");
    install("foobar", "baz");

    int result = uninstall("foo");
    printf("result: %d\n", result);

    return 0;
}
