# MIT License
#
# Copyright (c) 2020 Twinspica Authors
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

workspace(name = "twinspica_cpp")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


#
# Go support - No gazelle
#
http_archive(
    name = "io_bazel_rules_go",
    sha256 = "dd926a88a564a9246713a9c00b35315f54cbd46b31a26d5d8fb264c07045f05d",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v0.38.1/rules_go-v0.38.1.zip",
        "https://github.com/bazelbuild/rules_go/releases/download/v0.38.1/rules_go-v0.38.1.zip",
    ],
)

load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains", "go_rules_dependencies")
go_rules_dependencies()

# (TODO) codergs90: Registering go toolchain here conflicts with com_github_grpc_grpc. Not sure how to fix it atm.
#       fail("go_register_toolchains: version set after go sdk rule declared ({})".format(", ".join([r["name"] for r in sdk_rules])))
#        Error in fail: go_register_toolchains: version set after go sdk rule declared (go_sdk)
# go_register_toolchains(go_version = "1.19.5")

#
# Protobuf
#
http_archive(
    name = "com_google_protobuf",
    sha256 = "d0f5f605d0d656007ce6c8b5a82df3037e1d8fe8b121ed42e536f569dec16113",
    strip_prefix = "protobuf-3.14.0",
    urls = [
        "https://mirror.bazel.build/github.com/protocolbuffers/protobuf/archive/v3.14.0.tar.gz",
        "https://github.com/protocolbuffers/protobuf/archive/v3.14.0.tar.gz",
    ],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

#
# Toolchain: Bring's in the C++ LLVM compiler toolchain
# grailbio/bazel-toolchain - Commit f4c17a3ae40f927ff62cc0fb8fe22b1530871807
#
http_archive(
    name = "com_grail_bazel_toolchain",
    strip_prefix = "bazel-toolchain-master",
    urls = ["https://github.com/codergs/bazel-toolchain/archive/master.tar.gz"],
    # waiting for a new release, for now disabling SHA256 checks on master as
    # it keeps moving
    # sha256 = "17ce24a4c70f9397578a690e3b38d74a33cdcf78c34b4d2a0e70867dacf4f159"
)

load("@com_grail_bazel_toolchain//toolchain:deps.bzl", "bazel_toolchain_dependencies")
bazel_toolchain_dependencies()

load("@com_grail_bazel_toolchain//toolchain:rules.bzl", "llvm_toolchain")
llvm_toolchain(
    name = "llvm_toolchain",
    llvm_version = "10.0.0",
)

load("@llvm_toolchain//:toolchains.bzl", "llvm_register_toolchains")
llvm_register_toolchains()

#
# Google's Abesil Cpp Library - Commit c51510d1d87ebce8615ae1752fd5aca912f6cf4c
#
http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/refs/tags/20230125.0.zip"],
  strip_prefix = "abseil-cpp-20230125.0",
  sha256 = "70a2e30f715a7adcf5b7fcd2fcef7b624204b8e32ede8a23fd35ff5bd7d513b0",
)

#
# GoogleTest/GoogleMock - Commit 703bd9caab50b139428cea1aaff9974ebee5742e
#
http_archive(
     name = "com_google_googletest",
     urls = ["https://github.com/google/googletest/archive/release-1.10.0.zip"],
     strip_prefix = "googletest-release-1.10.0",
     sha256 = "94c634d499558a76fa649edb13721dce6e98fb1e7018dfaeba3cd7a083945e91",
)

# bazel 4.0.0 breaking fixes - https://github.com/bazelbuild/bazel/issues/12887
# Protobuf Rules for bazel - Commit
#
http_archive(
    name = "rules_proto",
    sha256 = "96cfb2191f8b383d5470a57361745565510e7389c01f9be1a64db2e792901c3b",
    strip_prefix = "rules_proto-cfdc2fa31879c0aebe31ce7702b1a9c8a4be02d2",
    urls = [
        "https://github.com/bazelbuild/rules_proto/archive/cfdc2fa31879c0aebe31ce7702b1a9c8a4be02d2.zip",
    ],
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

#
# gRPC C++ - Commit 257d0045ab958eb767a3591c88e9d0c2bdf4b916
#
http_archive(
    name = "com_github_grpc_grpc",
    urls = [
        "https://github.com/grpc/grpc/archive/v1.52.0.zip",
    ],
    #patch_args = ["-p1"],
    #patches = [
    #    "//third_party/grpc:grpc_1_28_1.patch",
    #],
    strip_prefix = "grpc-1.52.0",
    sha256 = "e2b6ff55a5a1acf5c2de6fc5e977ae8f77249cae978f09a28520a7d8d8d8a750",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()
