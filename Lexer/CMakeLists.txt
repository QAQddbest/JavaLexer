cmake_minimum_required (VERSION 2.8)

project(Lexer)

option(AUTOLEX "编译auto_lex" OFF)

add_subdirectory(src/man_lex)
	
add_subdirectory(src/auto_lex)