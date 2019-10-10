aux_source_directory (. SRC_LIST)

include_directories (../../include/man_lex)

add_executable (man_lex ${SRC_LIST})

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)