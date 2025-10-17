#-------------------------------------------------------------------------------
# Zephyr Example Application
#
# Copyright (c) 2021 Nordic Semiconductor ASA
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(app LANGUAGES C)
<<<<<<< HEAD

=======
>>>>>>> 30b7fef1dd8bc25bad74a973b0466c4e8314c692
target_sources(app PRIVATE src/main.c)
