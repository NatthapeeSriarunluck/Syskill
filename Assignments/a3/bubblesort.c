/* Name: Natthapee Sriarunluck
 * ID: 6480266
 */
#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"
#include <string.h>

void sort(Entry *in, int nL, void *comparator) {
    for (int i = 0; i< nL-1; i++) {
        for (int j = 0; j < nL-i-1; j++) {
             if (((int (*)(Entry, Entry))comparator)(in[j], in[j+1]) > 0) {
                Entry tmp = in[j];
                in[j] = in[j+1];
                in[j+1] = tmp;
            }
        }
    }
}

int compare(Entry a, Entry b) {
   return strcmp(a.name,b.name);
}

int main(void) {
    int nL = 0;
    scanf("%d", &nL);
    Entry *inputArray = (Entry*) malloc(nL * sizeof(Entry));
    for (int i = 0; i<nL; i++) {
        inputArray[i].name = (char*) malloc(MAX_NAME_LENGTH * sizeof(char));
        scanf("%d %s", &inputArray[i].data, inputArray[i].name);
    }

    sort(inputArray, nL, &compare);

    for (int i = 0; i<nL; i++) {
        printf("%d %s\n", inputArray[i].data, inputArray[i].name);
    }
    for (int i = 0; i < nL ; i++) {
        free(inputArray[i].name);
    }
    free(inputArray);
}
