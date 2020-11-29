# execution_root=$(bazel info execution_root) || exit

# readonly CLANG_TIDY_BIN="bazel run @llvm_toolchain//:bin/clang-tidy"

# # $CLANG_TIDY_BIN\
# #   --warnings-as-errors=* \

# #   --checks="-*,clang-analyzer-*,-clang-analyzer-cplusplus*,modernize-*" \
# #   "src/"*.cc \
# #   -- \
# #     -I "${execution_root}/external/googletest/googletest/include/" \
# #     -I "${execution_root}/external/absl/" \
# #     -I .


# for f in $(find src -type f -name "*.cc"); do
#     $CLANG_TIDY_BIN -- \
#       --warnings-as-errors=* \
#       -header-filter=src/.* \
#       --checks="-*,modernize-*,abseil-*" \
#       --system-headers   \
#       $f \
#         -- \
#         -I "${execution_root}/bazel-out/k8-opt/bin/external/com_google_googletest/googletest/include/" \
#         -I "${execution_root}/bazel-out/k8-opt/bin/external/com_google_absl/absl/" \
#         -I "${execution_root}/bazel-out/k8-opt/bin/external/com_github_grpc_grpc/include/" \
#         -I "${execution_root}/bazel-out/k8-opt/bin/external/com_google_protobuf/include/" \
#         -I .
# done


BAZEL_TARGET=$1
TITLE="Clang analyzer report for Bazel Target $1"
REPO_ROOT=$PWD
EXECUTION_ROOT=`bazel info execution_root`

bazel clean
bazel build --experimental_action_listener tools/actions:generate_compile_commands_listener $BAZEL_TARGET
./tools/actions/generate_compile_commands_json.py
echo "Performing static analysis..."

cd $EXECUTION_ROOT
analyze-build --cdb $REPO_ROOT/compile_commands.json -o $REPO_ROOT/clang-analysis --html-title "$TITLE" --use-analyzer external/llvm_toolchain/bin/clang-format
cd -