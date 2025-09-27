#include <stdio.h>
#include "audit.h"


long long run_audit_attack(char *hashes_file_path, char *wordlist_file_path) {
    printf("audit mode is running!\n");
    printf("hash file: %s\n", hashes_file_path);
    printf("wordlist file: %s\n", wordlist_file_path);
    return 0;
}
