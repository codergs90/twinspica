load("@io_bazel_rules_go//go:def.bzl", "go_binary")
#load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar")

go_binary(
    name = "hello",
    srcs = ["hello.go"],
)

# pkg_tar(
#     name = "hellotar",
#     srcs = [":hello"],
#     mode = "0755",
#     package_dir = "/usr/bin"
# )
