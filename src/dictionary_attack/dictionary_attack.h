#ifndef DICTIONARY_ATTACK_H
#define DICTIONARY_ATTACK_H

#include <stdio.h>

long long run_dictionary_attack(const char *hash, const char *wordlist_path);
int search_wordlist_for_hash(FILE *wordlist_file, const char *target_hash, char *found_password_buffer, long long *attempts_counter);

#endif
