FUNCTION(LINK_THIRDPARTY_GLUT project)
  TARGET_LINK_LIBRARIES(${project} ${OPENGL_LIBRARIES} ${GLUT_glut_LIBRARY})
ENDFUNCTION(LINK_THIRDPARTY_GLUT)

FUNCTION(LINK_THIRDPARTY_TICPP project)
  IF (WIN32)
    TARGET_LINK_LIBRARIES(${project} debug libticpp_d optimized libticpp)
  ELSE()
    TARGET_LINK_LIBRARIES(${project} ticpp)
  ENDIF()
ENDFUNCTION(LINK_THIRDPARTY_TICPP)
