
set(goose_cswi_SRCS
   goose_cswi.c
)

IF(MSVC)

set_source_files_properties(${goose_cswi_SRCS}
                                       PROPERTIES LANGUAGE CXX)
ENDIF(MSVC)                                       
                                       
add_executable(goose_publisher_example
  ${goose_cswi_SRCS}
)

target_link_libraries(goose_cswi
    iec61850
)


