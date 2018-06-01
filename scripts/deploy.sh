#!/usr/bin/env bash

set -ex

export CI=true

yarn build
# yarn test
cd build
now --name world-cup-quiz
