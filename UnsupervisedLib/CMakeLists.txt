﻿# CMakeList.txt : CMake project for UnsupervisedLib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (UnsupervisedLib "UnsupervisedLib.cpp" "UnsupervisedLib.h" "algos/KMeans.cpp" "util/Printer.cpp" "util/FileReader.cpp" "algos/Hierarchical.cpp" "util/algo.cpp" "algos/bagglomerative.cpp"  "algos/kbase.cpp" "algos/lsr.cpp" "algos/dbscan.cpp" "tests/apptests.cpp" "tests/agglomerativetests.cpp" "tests/dbscantests.cpp" "tests/prep.cpp" "tests/kalgorithmtests.cpp")

# TODO: Add tests and install targets if needed.
