[![CircleCI](https://circleci.com/gh/codergs90/twinspica.svg?style=shield&circle-token=869671f47dc4c8469337f5d942f59a554f869b87)](<LINK>)

Pre-requisites
===

[Bazel Install](https://docs.bazel.build/versions/master/install.html)

```
bazel build src/hello_world/cpp:all
bazel test src/hello_world/cpp:all
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
