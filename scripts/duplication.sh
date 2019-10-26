#!/bin/bash

set -ex

jscpd --mode "weak" --format "cpp" --ignore "*build*/**,tests" .
