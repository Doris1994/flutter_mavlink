cmake_minimum_required (VERSION 2.6)

project(flutter_mavlink)

aux_source_directory(${PROJECT_SOURCE_DIR}/../src SRC_FILES)

add_library(flutter_mavlink STATIC ${SRC_FILES})
# add_library(flutter_mavlink SHARED ${SRC_FILES})

install (TARGETS flutter_mavlink DESTINATION lib)