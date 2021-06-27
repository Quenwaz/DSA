

# TARGET_NAME 目标名称
# SRC_PATH	源码路径
# COMPILE_TYPE 0 编译exe目标  1 编译静态库 2 编译动态库
function(__compile_target TARGET_NAME SRC_PATH COMPILE_TYPE)
	message(STATUS "--------------begin compile ${TARGET_NAME}----------------------")
	message(STATUS "SRC_PATH=${SRC_PATH}")

	if(ARGC EQUAL 4)
		set(NORECURSE ${ARGV3})
	endif(ARGC EQUAL 4)

	if(NORECURSE)
		file(GLOB ${TARGET_NAME}_SRC "${SRC_PATH}/*.cpp" "${SRC_PATH}/*.cc" "${SRC_PATH}/*.h" "${SRC_PATH}/*.hpp")
	else(NORECURSE)
		message(STATUS "Search source file is recurse")
		file(GLOB_RECURSE ${TARGET_NAME}_SRC "${SRC_PATH}/*.cpp" "${SRC_PATH}/*.cc" "${SRC_PATH}/*.h" "${SRC_PATH}/*.hpp")
	endif(NORECURSE)
	
	foreach(source ${${TARGET_NAME}_SRC})
		string(REGEX REPLACE "(.*)/.*" "\\1" dir ${source})
		list(APPEND ${TARGET_NAME}_INCLUDES ${dir})
	endforeach(source ${${TARGET_NAME}_SRC})

	if(COMPILE_TYPE EQUAL 0)
		add_executable(${TARGET_NAME} ${${TARGET_NAME}_SRC})
	elseif(COMPILE_TYPE EQUAL 1)
		add_library(${TARGET_NAME} STATIC ${${TARGET_NAME}_SRC})
	elseif(COMPILE_TYPE EQUAL 2)
		add_library(${TARGET_NAME} SHARED ${${TARGET_NAME}_SRC})
		if(UNIX)
			target_compile_options(${TARGET_NAME} PRIVATE -fPIC)
		endif(UNIX)
	endif(COMPILE_TYPE EQUAL 0)
	message(STATUS ${TARGET_NAME}_SRC=${${TARGET_NAME}_SRC})

	target_include_directories(${TARGET_NAME} PRIVATE ${${TARGET_NAME}_INCLUDES})
	message(STATUS ${TARGET_NAME}_INCLUDES=${${TARGET_NAME}_INCLUDES})

	target_link_directories(${TARGET_NAME} PRIVATE ${${TARGET_NAME}_LIBRARY_DIR})
	message(STATUS ${TARGET_NAME}_LIBRARY_DIR=${${TARGET_NAME}_LIBRARY_DIR})

	target_link_libraries(${TARGET_NAME} PRIVATE ${${TARGET_NAME}_LIBRARIES})
	message(STATUS ${TARGET_NAME}_LIBRARIES=${${TARGET_NAME}_LIBRARIES})

	target_compile_options(${TARGET_NAME} PRIVATE ${${TARGET_NAME}_C_OPTIONS})
	message(STATUS ${TARGET_NAME}_C_OPTIONS=${${TARGET_NAME}_C_OPTIONS})

	if(UNIX)
		string(REGEX MATCH ".*/" CXX_COMPILER_DIR ${CMAKE_CXX_COMPILER})
		string(REGEX MATCH ".*[^bin/]" CXX_COMPILER_DIR ${CXX_COMPILER_DIR})
		message(STATUS CXX_COMPILER_DIR=${CXX_COMPILER_DIR})
		target_link_options(${TARGET_NAME} PRIVATE "-Wl,-rpath=${CXX_COMPILER_DIR}/lib64")
	endif(UNIX)
	target_link_options(${TARGET_NAME} PRIVATE ${${TARGET_NAME}_L_OPTIONS})
	message(STATUS ${TARGET_NAME}_L_OPTIONS=${${TARGET_NAME}_L_OPTIONS})
endfunction(__compile_target TARGET_NAME SRC_PATH)


macro(compile_to_exe TARGET_NAME SRC_PATH)
	__compile_target(${TARGET_NAME} ${SRC_PATH} 0 ${ARGN})
endmacro(compile_to_exe)


macro(compile_to_static_library TARGET_NAME SRC_PATH)
	__compile_target(${TARGET_NAME} ${SRC_PATH} 1 ${ARGN})
endmacro(compile_to_static_library)


macro(compile_to_dynamic_library TARGET_NAME SRC_PATH)
	__compile_target(${TARGET_NAME} ${SRC_PATH} 2 ${ARGN})
endmacro(compile_to_dynamic_library)