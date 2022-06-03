# zCore-user
Simple user programs for [zCore OS](https://github.com/rcore-os/zCore) (riscv64). This repo is mainly built upon [rCore-user](https://github.com/rcore-os/rcore-user).

First, download prebuilt musl toolchain from [musl.cc](https://musl.cc/), for example `riscv64-linux-musl-cross.tgz`. Untar it into root directory.

After that, run the following command in your work shell:

```bash
export riscv64-linux-musl-cross/*
cd user
```

Then, you may write your own user programs in `src` directory. If you have any problems, please refer to several written ones.

After writing user programs, run the following command to build the executable ones:

```bash
cmake . -DARCH=riscv64
make YOUR_PROGRAM_NAME
```

Finally, put the executable programs (in `riscv64` directory) into your zCore rootfs.
