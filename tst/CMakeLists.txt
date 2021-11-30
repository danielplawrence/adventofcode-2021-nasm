cmake_minimum_required(VERSION 3.14)
project (cmake-cpp-nasm-test)
set(CMAKE_CXX_STANDARD 17)
enable_language(ASM_NASM)
if(APPLE)
	#Add leading underscore when building macho64 object files
	string(APPEND CMAKE_ASM_NASM_FLAGS "--prefix _")
endif(APPLE)
add_executable(cmake-cpp-nasm-test test.cpp ../src/asm.asm ../src/library.asm ../lib/library.hpp)