# Compiler to use
CC = gcc


# Compiler flags:
#	- Wall => Turn on all warnings
#	- -g => Add debugging information
CFLAGS = -Wall -g -Isrc/dictionary_attack -Isrc/utils -Isrc/brute_force_attack -Isrc/audit

LDFLAGS = -lcrypto


# The name of the executable to create
TARGET = password-strength-auditor

# The source files
SRCS = src/main.c src/dictionary_attack/dictionary_attack.c src/utils/utils.c src/brute_force_attack/brute_force_attack.c src/audit/audit.c


# Default target, executed when just run 'make'
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Target to clean up the project directory
clean: 
	rm -f $(TARGET)
