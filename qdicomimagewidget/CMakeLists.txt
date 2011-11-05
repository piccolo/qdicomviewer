cmake_minimum_required(VERSION 2.6)
project(qdicomimagewidget)

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
  "/opt/local/include"
  ${DCMTK_INCLUDE_DIR}
  #${ZLIB_INCLUDE_DIRS}
)

message(${CMAKE_SOURCE_DIR})

IF(WIN32)	
  #REMOVE_DEFINITIONS(-DIM_EXPORTS)
  ADD_DEFINITIONS(-D_UWIN /MTd)	
  #INCLUDE_DIRECTORIES(${DCMTK_DIR}/include)
ENDIF(WIN32)

file (GLOB_RECURSE ${PROJECT_NAME}_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file (GLOB_RECURSE ${PROJECT_NAME}_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

set(${PROJECT_NAME}_RCS
   src/application.qrc
 )

set(${PROJECT_NAME}_QT_HEADER
  include/qdicomimagewidget.h
  include/mainwindow.h
 )

set(LINK_LIBRARIES
  ${QT_LIBRARIES}
  ${QT_QTOPENGL_LIBRARY}
 # ${DCMTK_LIBS}
 dicom
  ${ZLIB_LIBRARIES}
)
#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}/src)
add_definitions(-g -Wall -Wno-deprecated -DQT_DEBUG) # -DHAVE_CONFIG)

# this command will generate rules that will run rcc on all files from VisualTiff_RCS
# in result VisualTiff_RC_SRCS variable will contain paths to files produced by rcc
qt4_add_resources(${PROJECT_NAME}_RC_SRCS ${${PROJECT_NAME}_RCS} )

# tell cmake to create .moc files for all files in the variable VisualTiff_SRCS that require such a file.
qt4_wrap_cpp(${PROJECT_NAME}_MOC_SRCS ${${PROJECT_NAME}_QT_HEADER})

if (APPLE) 
  add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${${PROJECT_NAME}_SRCS} ${${PROJECT_NAME}_MOC_SRCS} ${${PROJECT_NAME}_RC_SRCS})
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND mkdir ARGS ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Resources
    )
  set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.app)
  #ADD_CUSTOM_COMMAND(TARGET clean POST_BUILD
   # COMMAND rm ARGS -rf ${CMAKE_CURRENT_BINARY_DIR}/qdicomwidget.app
   # )
  
else(APPLE)
   add_executable(${PROJECT_NAME}  ${${PROJECT_NAME}_SRCS} ${${PROJECT_NAME}_MOC_SRCS} ${${PROJECT_NAME}_RC_SRCS})
endif(APPLE)  

target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES})
