
set(sBrN1_SRCS
   sBrN1.c
)

IF(MSVC)
set_source_files_properties(${sBrN1_SRCS}
                                       PROPERTIES LANGUAGE CXX)
ENDIF(MSVC)

add_executable(sBrN1
  ${sBrN1_SRCS}
)

target_link_libraries(sBrN1
    iec61850
)
