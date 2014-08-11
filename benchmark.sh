#!/bin/bash

MRUBY=$1

# C extension
time $MRUBY -e "puts CTarai::tarai($2, $3, $4)"

# PureRuby extension
time $MRUBY -e "puts RTarai::tarai($2, $3, $4)"

