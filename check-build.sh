#!/bin/bash

make ARCH=riscv CROSS_COMPILE=riscv64-linux-gnu- openeuler_defconfig

make ARCH=riscv CROSS_COMPILE=riscv64-linux-gnu- -j8
