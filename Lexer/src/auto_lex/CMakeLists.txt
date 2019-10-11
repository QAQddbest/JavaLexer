aux_source_directory (. SRC_LIST)

include_directories (../../include/auto_lex)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable (auto_lex ${SRC_LIST})
