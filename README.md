Pre-requisites
===

[Bazel Install](https://docs.bazel.build/versions/master/install.html)

```
cd C++
bazel build src/hello_world:all
bazel test src/hello_world:all
```


Clang Format
===
```
bazel run @llvm_toolchain//:bin/clang-format -- -style=llvm -dump-config > .clang-format
```

FAQ
===

- Ubuntu 20 support for LLVM Clang is not out, so we patch bazel tool chain to use ubuntu 18 Clang 10 version.

    If you see below error
    ```
    external/llvm_toolchain/bin/clang: error while loading shared libraries: libtinfo.so.5: cannot open shared object file: No such file or directory
    ```
    then try to follow https://github.com/circleci/circleci-images/issues/430
    ```
    sudo apt update && sudo apt install -y libtinfo5
    ```
