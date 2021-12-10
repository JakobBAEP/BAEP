
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uni.h"



int main(void) {
	char opt;
	int ret;
	university *pinkafeld = (university*) malloc(sizeof(university));
	pinkafeld->groupList = NULL;
	pinkafeld->age = 0;

	do {
		while (1) {
			char *optset = "usgnx";
			printf("\n" "Choose action: university (u), semester (s), group (g), new (n), exit (x):");
			fflush(stdout);
			ret = scanf("%c", &opt);
			fflush(stdin);
			if (ret != 1 || strchr(optset, opt)==NULL) {
				printf("\n" "Invalid Selection\n");
			} else {
				break;
			}
		}
		switch (opt) {
		case 'u':
			printUniversity(pinkafeld);
			break;
		case 's':
			printSemester(pinkafeld);
			break;
		case 'g':
			printGroup(pinkafeld);
			break;
		case 'n':
			addSemester(pinkafeld);
			break;
		}


	} while (opt != 'x');

	freegroups(pinkafeld);
	free(pinkafeld);
	return EXIT_SUCCESS;

}


