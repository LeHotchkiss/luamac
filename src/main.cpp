#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"

#define CMP(_short, _long) (strcmp(current, _short) == 0 || strcmp(current, _long) == 0) 

static const char* g_helpMessage = "";

void ParseArgs(int argc, char** argv) {
    for(int i = 1; i < argc; i++) {
	const char* current = argv[i];
	const char* next = (i < argc) ? argv[i+1] : NULL;
        
	bool goodOption = false;

	if(current[0] == '-') {
	    if(CMP("-h", "--help")) {     // Options without arguments
		goodOption = true;
		puts(g_helpMessage);
	        exit(RET_OK);
	    } else if("-v", "--verbose") {
	        goodOption = true;
		g_state.verbose = true;
	    }
	    
	    if(next != NULL) {            // Options with an argument
		if(CMP("-o", "--output")) {
		    goodOption = true;
		    g_state.output = next;
		    continue; 
		}
	    }

	    if(goodOption == false) {
	        fprintf(stderr, "Unknown cmd option: '%s'\n", current);
		exit(RET_BAD_ARGS);
	    }

	} else {                      // Files input
	    g_state.filesInput.PushBack(current);    
	}
    }

    g_state.filesInput.Shrink();
}

#undef CMP

int main(int argc, char** argv) {
    ParseArgs(argc, argv);

    printf("Input files:\n");
    for(size_t i = 0; i < g_state.filesInput.Length(); i++) {
        printf("\t+ %s\n", g_state.filesInput[i].String());
    }

    return 0;
}

