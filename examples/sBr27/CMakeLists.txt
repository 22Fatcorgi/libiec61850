
set(sBr27_SRCS
   sBr27.c
)

IF(MSVC)
set_source_files_properties(${sBr27_SRCS}
                                       PROPERTIES LANGUAGE CXX)
ENDIF(MSVC)

add_executable(sBr27
  ${sBr27_SRCS}
)

target_link_libraries(sBr27
    iec61850
)
