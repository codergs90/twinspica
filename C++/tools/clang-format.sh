#!/bin/bash

readonly CLANG_FORMAT_BIN="bazel run @llvm_toolchain//:bin/clang-format"

find src -type f -name "*.cc" -o -name "*.hh" | xargs $CLANG_FORMAT_BIN -- --style=file -i
