Pre-requisites
===

[Bazel Install](https://docs.bazel.build/versions/master/install.html)

```
cd C++
bazel build src/hello_world:all
bazel test src/hello_world:all
```


Clang Format
```
bazel run @llvm_toolchain//:bin/clang-format -- -style=llvm -dump-config > .clang-format
```