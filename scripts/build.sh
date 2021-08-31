#!/bin/sh

meson build
cd build
meson compile || ninja