#!/bin/sh

echo "--- Cleaning project ---"
make clean

echo "--- Generating compile_commands.json for the language server ---"
compiledb make

echo "--- Building executables for all platforms (Linux, Windows, macOS) ---"
make build-all

echo "--- Build complete ---"
