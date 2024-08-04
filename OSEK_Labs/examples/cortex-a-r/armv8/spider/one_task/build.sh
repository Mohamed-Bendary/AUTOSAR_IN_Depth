#!/usr/bin/env bash

#stop on errors
set -e

echo "*** Run Goil ***"
goil --target=cortex-a-r/armv8/spider --templates=../../../../../goil/templates/ one_task.oil

echo "*** Run Make ***"
./make.py
