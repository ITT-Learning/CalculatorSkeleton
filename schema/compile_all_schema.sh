#!/bin/bash

echo "Not working? Make sure you run CMake and build everything"

./../third-party/flatbuffers/flatbuffers-build/flatc --cpp --gen-object-api --gen-mutable *.fbs
