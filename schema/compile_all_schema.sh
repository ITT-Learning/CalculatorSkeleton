#!/bin/bash

echo "If this isn't working, make sure you run cmake and build everything again"

./../third-party/flatbuffers/flatbuffers-build/flatc --cpp --gen-object-api --gen-mutable *.fbs