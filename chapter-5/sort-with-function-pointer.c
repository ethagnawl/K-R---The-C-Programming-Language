#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

char *lineptr[MAXLINES];

/* K&R2 p29 */
int my_getline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

// stolen: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_5:Exercise_14
/* K&R2 p109 */
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = my_getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = malloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0';  /* delete the newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

// stolen: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_5:Exercise_14
/* K&R2 p109 */
void writelines(char *lineptr[], int nlines) {
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

void swap(void *v[], int, int);
void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// void my_qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *));
void my_qsort(void *v[], int left, int right, int (*comp) (void *, void *)) {
    int i,
        last;

    if (left >= right) {
        return;
    } else {
        swap(v, left, (left + right)/2);
        last = left;
        for (i = left + 1; i <= right; i += 1) {
            if ((*comp)(v[i], v[left]) < 0) {
                swap(v, ++last, i);
            }
        }
        swap(v, left, last);
        my_qsort(v, left, last - 1, comp);
        my_qsort(v, last + 1, right, comp);
    }
}

// stolen: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_5:Exercise_14
int my_numcmp(char *s1, char *s2) {
    double v1,
           v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

// stolen: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_5:Exercise_14
int my_rev_numcmp(char *n1, char *n2) {
    return my_numcmp((char*)n2, (char*)n1);
}

// *_wrapper functions avoid "pointer type mismatch in conditional expression"
// warning in call to `my_qsort`.
// https://stackoverflow.com/a/665035/382982
static int numcmp_wrapper(void* n1, void* n2) {
  return my_numcmp((char*)n1, (char*)n2);
}

static int strcmp_wrapper(void* s1, void* s2) {
  return strcmp((char*)s1, (char*)s2);
}

static int rev_numcmp_wrapper(void* n1, void* n2) {
  return my_rev_numcmp((char*)n1, (char*)n2);
}

static int rev_strcmp_wrapper(void* s1, void* s2) {
  return strcmp((char*)s2, (char*)s1);
}

int main(int argc, char *argv[]) {
    int nlines;
    int numeric = 0;
    int reverse = 0;
    static int (*sort_function) (void* n1, void* n2);

    if (argc > 1) {
        for (char **flag = ++argv; *flag; ++flag) {
            if (strcmp(*flag, "-n") == 0) {
                numeric = 1;
            } else if (strcmp(*flag, "-r") == 0) {
                reverse = 1;
            } else {
                printf("Unknown option: %s\n", *flag);
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (numeric == 1 && reverse == 0) {
            sort_function = numcmp_wrapper;
        } else if (numeric == 1 && reverse == 1) {
            sort_function = rev_numcmp_wrapper;
        } else if (numeric == 0 && reverse == 0) {
            sort_function = strcmp_wrapper;
        } else if (numeric == 0 && reverse == 1) {
            sort_function = rev_strcmp_wrapper;
        }

        my_qsort((void **) lineptr, 0, (nlines - 1),
                (int (*)(void *, void *))(sort_function));

        writelines(lineptr, nlines);

        return 0;
    }  else {
        printf("input is too big to sort\n");
        return 1;
    }

    return 0;
}
