#!/bin/sh

VIS_DIR=$(pwd)/visualizer-template-public
WASM_DIR=$VIS_DIR/wasm

if [ -z $YARN_INIT ]; then
    yarn
fi

cd $WASM_DIR
wasm-pack build --target web --out-dir ../public/wasm
cd $VIS_DIR
yarn dev