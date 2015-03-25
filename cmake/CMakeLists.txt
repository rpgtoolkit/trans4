# Copyright (c) 2015, Chris Hutchinson
#
# See LICENSE.md in the distribution for the full license text including,
# but not limited to, a notice of warranty and distribution rights.

cmake_minimum_required(VERSION 2.8.11)
enable_testing()

set(CMAKE_MODULE_PATH   ${CMAKE_SOURCE_DIR})

project(rpgtoolkit)

set(RPGTOOLKIT_VERSION_MAJOR      4)
set(RPGTOOLKIT_VERSION_MINOR      0)
set(RPGTOOLKIT_VERSION_PATCH      0)
set(RPGTOOLKIT_VERSION_RELEASE    "alpha")
set(RPGTOOLKIT_VERSION_METADATA   "")

set(RPGTOOLKIT_HEADERS ${CMAKE_SOURCE_DIR}/../include)
set(RPGTOOLKIT_SOURCES ${CMAKE_SOURCE_DIR}/../source)

# Projects

include(projects/clio)
include(projects/trans4)
