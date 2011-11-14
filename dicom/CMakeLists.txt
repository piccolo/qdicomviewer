cmake_minimum_required(VERSION 2.6)
project(dicom)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  "/opt/local/include"
  ${DCMTK_INCLUDE_DIR}
)


file (GLOB_RECURSE ${PROJECT_NAME}_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file (GLOB_RECURSE ${PROJECT_NAME}_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

set(LINK_LIBRARIES
  ${DCMTK_LIBS}
  ${ZLIB_LIBRARIES}
)

add_definitions(-g -Wall -Wno-deprecated -DHAVE_CONFIG)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRCS})

target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES})

add_subdirectory(test)