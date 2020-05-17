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
    urls = ["https://github.com/abseil/abseil-cpp/archive/20200225.2.zip"],
    strip_prefix = "abseil-cpp-20200225.2",
    sha256 = "f342aac71a62861ac784cadb8127d5a42c6c61ab1cd07f00aef05f2cc4988c42",
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

#
# Protobuf Rules for bazel - Commit 
#
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_proto",
    sha256 = "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
    strip_prefix = "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
    ],
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

#
# gRPC C++ - Commit cb81fe0dfaa424eb50de26fb7c904a27a78c3f76
#
http_archive(
    name = "com_github_grpc_grpc",
    urls = [
        "https://github.com/grpc/grpc/archive/v1.28.1.zip",
    ],
    patch_args = ["-p1"],
    patches = [ 
        "//third_party/grpc:grpc_1_28_1.patch",
    ],
    strip_prefix = "grpc-1.28.1",
    sha256 = "b0d3b876d85e4e4375aa211a52a33b7e8ca9f9d6d97a60c3c844070a700f0ea3",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

# https://github.com/grpc/grpc/issues/22436
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()
