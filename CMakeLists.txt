cmake_minimum_required(VERSION 2.8)

PROJECT(live-media-server)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall -pthread -D__STDC_FORMAT_MACROS -ldl")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

SET(PROJECT_ROOT_PATH "${CMAKE_SOURCE_DIR}/")
SET(LIBRARY_OUTPUT_PATH "${PROJECT_ROOT_PATH}/lib/")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/src/crypto/rapidjson")
INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/src/core")
INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/src/rtmp")
INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/src/http")
INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/src/kernel")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/library/cares/include/")
LINK_DIRECTORIES("${PROJECT_ROOT_PATH}/library/cares/lib/")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/library/pcre/include/")
LINK_DIRECTORIES("${PROJECT_ROOT_PATH}/library/pcre/lib/")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/library/openssl/include/")
LINK_DIRECTORIES("${PROJECT_ROOT_PATH}/library/openssl/lib/")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/library/http-parser")
LINK_DIRECTORIES("${PROJECT_ROOT_PATH}/library/http-parser")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/library/zlib/include/")
LINK_DIRECTORIES("${PROJECT_ROOT_PATH}/library/zlib/lib/")

ADD_SUBDIRECTORY(src)

install(DIRECTORY ${PROJECT_ROOT_PATH}/library DESTINATION .)
install(DIRECTORY ${LIBRARY_OUTPUT_PATH} DESTINATION lib)
install(DIRECTORY ${PROJECT_ROOT_PATH}/conf DESTINATION .)

