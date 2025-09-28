#include <stdio.h>
#include <string.h>
#include "audit.h"


long long run_audit_attack(char *hashes_file_path, char *wordlist_file_path) {
    printf("audit mode is running!\n");
    

    FILE *hashes_file = fopen(hashes_file_path, "r");
    
    if(hashes_file == NULL) {
        printf("ERROR:: could not open file at the path %s\n", hashes_file_path);
        return 0;
    }

    char line[256];
    
    while (fgets(line, sizeof(line), hashes_file)) {
        line[strcspn(line, "\n")] = '\0';

        printf("%s\n", line);
    }

    fclose(hashes_file);

    return 0;
}
