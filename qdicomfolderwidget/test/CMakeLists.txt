cmake_minimum_required(VERSION 2.8)
project(test)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  "/opt/local/include"
  ${DCMTK_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
  ${QT_QTOPENGL_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/dicom/include
)


file (GLOB_RECURSE ${PROJECT_NAME}_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file (GLOB_RECURSE ${PROJECT_NAME}_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

set(LINK_LIBRARIES
  ${DCMTK_LIBS}
  dicom
  qdicomfolderwidget
  ${ZLIB_LIBRARIES}
  ${QT_LIBRARIES}
  ${QT_QTOPENGL_LIBRARY}
)

add_definitions(-g -Wall -Wno-deprecated -DHAVE_CONFIG -DQT_DEBUG)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS})

target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES})