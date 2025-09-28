#include <stdio.h>
#include <string.h>
#include "audit.h"
#include "dictionary_attack.h"


long long run_audit_attack(char *hashes_file_path, char *wordlist_file_path) {
    printf("[INFO] audit mode is initiated!\n");
    

    FILE *hashes_file = fopen(hashes_file_path, "r");
    
    if(hashes_file == NULL) {
        printf("ERROR:: could not open file at the path %s\n", hashes_file_path);
        return 0;
    }

    FILE *wordlist_file = fopen(wordlist_file_path, "r");

    if(wordlist_file == NULL) {
        printf("ERROR:: could not open file at the path %s\n", wordlist_file_path);
        fclose(hashes_file);
        return 0;
    }

    printf("[INFO] auditing hashes from %s\n", hashes_file_path);
    printf("[INFO] using wordlist from %s\n", wordlist_file_path);


    char target_hash[256];
    long long total_attempts = 0;
    int hashes_cracked = 0;
    int hashes_total = 0;

    while(fgets(target_hash, sizeof(target_hash), hashes_file)) {
        hashes_total++;
        target_hash[strcspn(target_hash, "\n")] = '\0';

        char found_password[256] = {0};
        long long attempts_for_this_hash = 0;

        printf("\n[INFO] attacking hash: %s\n", target_hash);

        int found = search_wordlist_for_hash(wordlist_file, target_hash, found_password, &attempts_for_this_hash);

        total_attempts += attempts_for_this_hash;

        printf("\r                                              \r");

        if(found) {
            hashes_cracked++;
            printf("\r[SUCCESS] Password found for hash %s -> %s\n", target_hash, found_password);
        } else {
            printf("\r[FAIL] Password not found for hash %s\n", target_hash);
        }
    }

    fclose(wordlist_file);
    fclose(hashes_file);

    printf("\n----- audit summary -----\n");
    printf("total hashes: %d\n", hashes_total);
    printf("cracked hashes: %d\n", hashes_cracked);
    if(hashes_total > 0) {
        printf("success rate: %.2f%%\n", ((double)hashes_cracked / hashes_total) * 100);
    }
    printf("--------------\n");

    return total_attempts;
}
