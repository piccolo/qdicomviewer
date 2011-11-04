cmake_minimum_required(VERSION 2.8)
project(qdicomviewer)


message("Searching Qt Library")
find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
if(QT_FOUND)
	include(${QT_USE_FILE})
	message(" Qt include path: " ${QT_INCLUDE_DIR})
	message(" Qt library path: " ${QT_LIBRARIES})
	message(" Qt OpenGL include path: " ${QT_QTOPENGL_INCLUDE_DIR})
	message(" Qt OpenGL library path: " ${QT_QTOPENGL_LIBRARY})
endif(QT_FOUND)

message("Searching DCMTK Library")
find_package(DCMTK REQUIRED )
if(DCMTK_FOUND)
  message("DCMTK FOUND")
  message(" DCMTK LIBRARY PATH " ${DCMTK_LIBRARIES})
  message(" DCMTK INCLUDE PATH " ${DCMTK_INCLUDE_DIR})  
endif(DCMTK_FOUND)

find_package(ZLIB REQUIRED)

MESSAGE(${CMAKE_SYSTEM_NAME})
IF("${CMAKE_SYSTEM_NAME}" MATCHES "Darwin") 
  SET(DCMTK_LIBS 
    #${DCMTK_LIBRARIES}
     ${DCMTK_ijg16_LIBRARY}
     ${DCMTK_ijg12_LIBRARY}
     ${DCMTK_ijg8_LIBRARY}
     ${DCMTK_dcmjpeg_LIBRARY}
     ${DCMTK_dcmimgle_LIBRARY}  
     ${DCMTK_dcmimage_LIBRARY}
     ${DCMTK_oflog_LIBRARY}
     ${DCMTK_ofstd_LIBRARY}
     ${DCMTK_dcmdata_LIBRARY}
	  )
ENDIF("${CMAKE_SYSTEM_NAME}" MATCHES "Darwin")

IF("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
  SET(DCMTK_LIBS 
   ${DCMTK_dcmdata_LIBRARY}
   ${DCMTK_oflog_LIBRARY}    
   ${DCMTK_ofstd_LIBRARY}
   ${DCMTK_dcmimage_LIBRARY}
   ${DCMTK_dcmimgle_LIBRARY}  
   ${DCMTK_dcmjpeg_LIBRARY}
   ${DCMTK_ijg8_LIBRARY}
   ${DCMTK_ijg12_LIBRARY}
   ${DCMTK_ijg16_LIBRARY}
   )
ENDIF("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")

IF(WIN32)
  MESSAGE("WIN32")
  SET(DCMTK_LIBS 
    ${DCMTK_dcmdata_LIBRARY}
    ${DCMTK_oflog_LIBRARY}    
    ${DCMTK_ofstd_LIBRARY}
    ${DCMTK_dcmimage_LIBRARY}
    ${DCMTK_dcmimgle_LIBRARY}  
    ${DCMTK_dcmjpeg_LIBRARY}
    ${DCMTK_ijg8_LIBRARY}
    ${DCMTK_ijg12_LIBRARY}
    ${DCMTK_ijg16_LIBRARY}
    "netapi32.lib"
    "wsock32.lib"
    )
ENDIF(WIN32)

#add_subdirectories(dicom)

add_subdirectory(qdicomimagewidget)

#add_subdirectories(test)

add_custom_target(distclean COMMAND rm -rf *) 