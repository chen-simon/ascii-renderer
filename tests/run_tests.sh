#!/usr/bin/env bash

# Setup
mkdir tests/temp

# Build
g++ -o tests/temp/geometryTest tests/geometryTest.cpp

# Run tests
tests/temp/geometryTest

# Clean up
rm tests/temp/geometryTest
