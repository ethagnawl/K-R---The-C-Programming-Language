#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 999
#define MAX_WORDS 999

int get_line(char input[], int maximum_line_length) {
    int c,
        i;

    for (i = 0; i < maximum_line_length &&
                (c = getchar()) != EOF &&
                c != '\n'; ++i) {
        input[i] = c;
    }

    if (c == '\n') {
        input[i++] = c;
    }

    input[i] = '\0';

    return i;
}

char *my_strdup(char *s) {
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

struct variable_grouping {
    char *prefix;
    char *words[MAX_WORDS];
    int count;
    struct variable_grouping *left;
    struct variable_grouping *right;
};

struct variable_grouping* talloc() {
    return (struct variable_grouping *) malloc(sizeof(struct variable_grouping));
}

struct variable_grouping *add_to_tree(char *prefix,
                                     char *word,
                                     struct variable_grouping *root) {

    if (root == NULL) {
        root = talloc();
        root->prefix = my_strdup(prefix);
        root->words[0] = my_strdup(word);
        root->count = 1;
        root->left = NULL;
        root->right = NULL;
    } else {
        int match = strcmp(prefix, root->prefix);
        if (match == 0) {
            int i;
            for (i = 0; i < MAX_WORDS; i += 1) {
                if (root->words[i] == NULL) {
                    root->words[i] = my_strdup(word);
                    root->count++;
                    break;
                }
            }
        } else if (match < 0) {
            root->left = add_to_tree(prefix, word, root->left);
        } else {
            root->right = add_to_tree(prefix, word, root->right);
        }
    }

    return root;
}

void print_words(char **words) {
    for (; *words; words++) {
        char *word = *words;
        while (*word) {
            putchar(*word++);
        }
     }
}

void print_prefix(char *prefix) {
    printf("prefix: %s\n", prefix);
}

void print_count(int count) {
    printf("count: %d\n", count);
}

void print_tree(struct variable_grouping *tree) {
    if (tree != NULL) {
        print_tree(tree->left);

        print_prefix(tree->prefix);
        print_words(tree->words);
        print_count(tree->count);
        printf("----\n");

        print_tree(tree->right);
    } else {
        // printf("{}\n");
    }
}

int main(int argc, char *argv[]) {
    int i = 0,
        prefix_length = 3,
        line_length;
    char line[MAX_LINE_LENGTH];
    char word[MAX_LINE_LENGTH];
    struct variable_grouping *root;
    root = NULL;

    if (argc > 1 &&
        (strcmp("-p", argv[1]) == 0) &&
        argv[2]) {
        prefix_length = atoi(argv[2]);
        prefix_length = prefix_length <= 0 ? prefix_length : prefix_length;
    }

    char prefix[prefix_length];

    while ((line_length = get_line(line, MAX_LINE_LENGTH)) > 0) {
        i = 0;
        while (i < line_length) {
            word[i] = line[i];
            if (i < prefix_length) {
                prefix[i] = line[i];
            }
            i += 1;
        }
        prefix[i] = '\0';
        word[i] = '\0';

        root = add_to_tree(prefix, word, root);
    }

    print_tree(root);

    return 0;
}
