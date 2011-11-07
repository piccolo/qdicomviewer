cmake_minimum_required(VERSION 2.6)
project(qdicomfolderwidget)

# Idem pour les lib

include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src
  ${QT_INCLUDE_DIR}
  ${QT_QTOPENGL_INCLUDE_DIR}
)

include_directories(
  #${DCMTK_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/dicom/include
  ${qdicomimagewidget_SOURCE_DIR}/include
  "/opt/local/include"
  ${DCMTK_INCLUDE_DIR}
  #${ZLIB_INCLUDE_DIRS}
)


set(LINK_LIBRARIES
  ${QT_LIBRARIES}
  ${QT_QTOPENGL_LIBRARY}
  qdicomimagewidget
  ${ZLIB_LIBRARIES}
)

file (GLOB_RECURSE ${PROJECT_NAME}_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file (GLOB_RECURSE ${PROJECT_NAME}_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

set(${PROJECT_NAME}_QT_HEADER
  include/qdicomfolderwidget.h
  #include/mainwindow.h
 )


#qt4_add_resources(${PROJECT_NAME}_RC_SRCS ${${PROJECT_NAME}_RCS} )

qt4_wrap_cpp(${PROJECT_NAME}_MOC_SRCS ${${PROJECT_NAME}_QT_HEADER})

add_definitions(-g -Wall -Wno-deprecated -DHAVE_CONFIG -DQT_DEBUG)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRCS} ${${PROJECT_NAME}_MOC_SRCS})

target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES})

add_subdirectory(test)