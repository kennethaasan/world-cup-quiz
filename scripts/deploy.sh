#!/usr/bin/env bash

set -ex

export CI=true

yarn build
# yarn test
cd build
URL=$(now --name world-cup-quiz)
now alias ${URL} vm.kennethaasan.no