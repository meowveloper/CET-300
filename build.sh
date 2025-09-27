#!/bin/sh

echo "--- Cleaning project ---"
make clean

echo "--- Building and generating compile_commands.json ---"
bear -- make
