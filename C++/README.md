Pre-requisites
===

[Bazel Install](https://docs.bazel.build/versions/master/install.html)

```
bazel build hello_world:all
bazel test hello_world:all
```


Clang Format
```
bazel run @llvm_toolchain//:bin/clang-format -- -style=llvm -dump-config > .clang-format
```