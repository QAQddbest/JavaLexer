aux_source_directory (. SRC_LIST)

include_directories (../../include/auto_lex)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

if (AUTOLEX)
	add_executable (auto_lex ${SRC_LIST})
else()
	message(STATUS "已取消编译auto_lex")
endif()
