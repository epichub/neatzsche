PROJECT(EXPERIMENTS)
cmake_minimum_required(VERSION 2.6)
SET(CMAKE_INSTALL_PREFIX "$ENV{HOME}/local/")
SUBDIRS(cppn dataset eyeexperiment goexperiment hyperneat random)