set(lms_root ${PROJECT_ROOT_PATH}/src/lms)

SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_ROOT_PATH}/bin/")

include_directories("${lms_root}/base")
include_directories("${lms_root}/rtmp")
include_directories("${lms_root}/http")
include_directories("${lms_root}/verify")
include_directories("${lms_root}/hls")
include_directories("${lms_root}/dvr")
include_directories("${lms_root}/monitor")

FILE(GLOB_RECURSE SOURCE "${PROJECT_ROOT_PATH}/src/lms/*.cpp")
FILE(GLOB_RECURSE SOURCE_BASE "${PROJECT_ROOT_PATH}/src/lms/base/*.cpp")
FILE(GLOB_RECURSE SOURCE_BASE "${PROJECT_ROOT_PATH}/src/lms/http/*.cpp")
FILE(GLOB_RECURSE SOURCE_RTMP "${PROJECT_ROOT_PATH}/src/lms/rtmp/*.cpp")
FILE(GLOB_RECURSE SOURCE_RTMP "${PROJECT_ROOT_PATH}/src/lms/verify/*.cpp")
FILE(GLOB_RECURSE SOURCE_RTMP "${PROJECT_ROOT_PATH}/src/lms/hls/*.cpp")
FILE(GLOB_RECURSE SOURCE_RTMP "${PROJECT_ROOT_PATH}/src/lms/dvr/*.cpp")
FILE(GLOB_RECURSE SOURCE_RTMP "${PROJECT_ROOT_PATH}/src/lms/monitor/*.cpp")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/library/gperftools/include/")
LINK_DIRECTORIES("${PROJECT_ROOT_PATH}/library/gperftools/lib/")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/library/unwind/include/")
LINK_DIRECTORIES("${PROJECT_ROOT_PATH}/library/unwind/lib/")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/library/codec/include/")
LINK_DIRECTORIES("${PROJECT_ROOT_PATH}/library/codec/lib/")

ADD_EXECUTABLE(lms ${SOURCE_RTMP} ${SOURCE_BASE} ${SOURCE})
TARGET_LINK_LIBRARIES(lms core kernel rtmp http profiler unwind codec tcmalloc)

set(ENABLE_GPERF FALSE CACHE BOOL "enbale gperf true/false")
if(ENABLE_GPERF)
	add_definitions("-DENABLE_GPERF")
endif(ENABLE_GPERF)

install(TARGETS lms RUNTIME DESTINATION bin)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--rpath,../library/gperftools/lib:../library/cares/lib:../library/pcre/lib:../library/unwind/lib:../library/codec/lib")

set_target_properties(lms PROPERTIES INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/library/gperftools/lib:${CMAKE_INSTALL_PREFIX}/library/cares/lib:${CMAKE_INSTALL_PREFIX}/library/pcre/lib:${CMAKE_INSTALL_PREFIX}/library/unwind/lib:${CMAKE_INSTALL_PREFIX}/library/codec/lib)
