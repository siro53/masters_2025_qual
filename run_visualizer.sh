#!/bin/sh

if [ -z $YARN_INIT ]; then
    yarn
fi

cd wasm && wasm-pack build --target web --out-dir ../public/wasm && cd ..
yarn dev