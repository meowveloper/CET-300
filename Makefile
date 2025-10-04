# Compiler to use
CC = zig cc

# Compiler flags
CFLAGS = -Wall -g -I/usr/include -I/usr/include/x86_64-linux-gnu -Isrc/dictionary_attack -Isrc/utils -Isrc/brute_force_attack -Isrc/audit

# Linker flags for Linux
LDFLAGS_LINUX = -lcrypto -L/usr/lib/x86_64-linux-gnu

# The name of the executable to create
TARGET = password-strength-auditor
BIN_DIR = bin

# The source files
SRCS = src/main.c src/dictionary_attack/dictionary_attack.c src/utils/utils.c src/brute_force_attack/brute_force_attack.c src/audit/audit.c

# Object files - replace .c with .o
OBJS = $(SRCS:.c=.o)

# Default target, executed when just run 'make'
all: build-linux

# --- Build Targets ---

build-linux: $(BIN_DIR)/$(TARGET)-linux-amd64

$(BIN_DIR)/$(TARGET)-linux-amd64: $(OBJS)
	@mkdir -p $(@D)
	$(CC) -target x86_64-linux-gnu -o $@ $(OBJS) $(LDFLAGS_LINUX)

build-windows:
	@echo "Windows build is not yet supported due to OpenSSL dependency."

build-macos:
	@echo "macOS build is not yet supported due to OpenSSL dependency."

build-all: build-linux

# --- Compilation Rule ---

# Generic rule to compile a .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# --- Housekeeping ---

clean:
	rm -f $(OBJS)
	rm -rf $(BIN_DIR)
