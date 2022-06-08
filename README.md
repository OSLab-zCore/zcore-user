# zCore-user

Simple user programs for [zCore OS](https://github.com/rcore-os/zCore) (riscv64). This repo is mainly built upon [rCore-user](https://github.com/rcore-os/rcore-user) and [lmbench](http://lmbench.sourceforge.net).

## Prepare for the environment

First, download prebuilt musl toolchain from [musl.cc](https://musl.cc/), for example `riscv64-linux-musl-cross.tgz`. Untar it into root directory.

After that, run the following command in your work shell:

```bash
export PATH=PATH_TO_YOUR_DIR/riscv64-linux-musl-cross/bin:$PATH
```

## Write user programs

```bash
cd user
```

Then, you may write your own user programs in `src` directory. If you have any problems, please refer to several written ones.

After writing user programs, run the following command to build the executable ones:

```bash
cmake -DARCH=riscv64 .
make YOUR_PROGRAM_NAME
```

Finally, put the executable programs in `riscv64` directory into your zCore rootfs.

## Run lmbench

We modify the original lmbench code and Makefile to fit riscv64. If you want to make another testcase, please imitate our command in Makefile.

```bash
cd lmbench-3.0-a9/src
make lat_ctx
```

Finally, put the executable programs in `bin/unknown` directory (there already exist prebuilt ones) into your zCore rootfs.
