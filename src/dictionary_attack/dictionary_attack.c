#include "dictionary_attack.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>


long long run_dictionary_attack(const char *hash, const char *wordlist_path) {
    printf("[INFO] dictionary attack initiated!!!\n");

    FILE *wordlist_file = fopen(wordlist_path, "r");

    if (wordlist_file == NULL) {
        printf("ERROR:: could not open file at the path %s\n", wordlist_path);
        return 0;
    }

    char found_password[256] = {0};
    long long attempts = 0;

    int found = search_wordlist_for_hash(wordlist_file, hash, found_password, &attempts);


    printf("\r                                                          \r");

    fclose(wordlist_file);

    if (!found) {
        printf("\npassword not found in the word list\n");
    } else {
        printf("\nsuccess!, password found\n");
        printf("hash: %s\n", hash);
        printf("password: %s\n", found_password);
    }

    return attempts;
}


int search_wordlist_for_hash(FILE *wordlist_file, const char *target_hash, char *found_password_buffer, long long *attempts_counter) {
    const int PROGRESS_INTERVAL = 10;
    char line[256];
    int found = 0;

    rewind(wordlist_file);
    
    while(fgets(line, sizeof(line), wordlist_file)) {
        (*attempts_counter)++;
        line[strcspn(line, "\n")] = '\0';

        if(*attempts_counter % PROGRESS_INTERVAL == 0) {
            printf("\r[INFO] current attempt: [%s]", line);
            fflush(stdout);
        }

        if(hash_and_compare(line, target_hash)) {
            strncpy(found_password_buffer, line, 256);
            found = 1;
            break;
        }
    }

    return found;
}
