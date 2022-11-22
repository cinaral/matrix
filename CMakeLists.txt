cmake_minimum_required(VERSION 3.13)

project(
	matrix_op
	VERSION 1.0.3
	LANGUAGES CXX
)



if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	option(SINGLE_PRECISION "Single precision" OFF)
	option(BUILD_TESTS "Build tests" ON)
	option(BUILD_BENCHMARKS "Build bencmarks" ON)

	#* where to look for the project header and source files
	set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
	set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
	set(TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)
	set(BENCHMARK_DIR ${CMAKE_CURRENT_LIST_DIR}/src)

	#* tests, examples, benchmarks to compile
	set(TEST_NAMES
		test-row_operations
		test-elementwise_operations
		test-vector_operations
		test-matrix_operations
	)
	set(BENCHMARK_NAMES
	)

	#* files to package
	set(PACKAGE_FILES 
		include/${PROJECT_NAME}/
		include/${PROJECT_NAME}.hpp 
		CMakeLists.txt 
		LICENSE
	)

	#* set up output directories
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
	file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/dat)

	#* project compile options
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	set(CMAKE_CXX_EXTENSIONS OFF)

	add_compile_options(
		-fdiagnostics-color=always #* colored debug output
		-fmessage-length=0 #* disable line wrapping (default=72 char) 
		-Wall #* all warnings
		-Wextra #* more warnings
		-Wpedantic #* more warnings
	)

	if(SINGLE_PRECISION)
		add_compile_options(-D__USE_SINGLE_PRECISION__) #* use single precision floats
	endif()
	
	#***********#
	#* Testing *#
	#***********#
	if(BUILD_TESTS)
		enable_testing()

		foreach(ELEMENT ${TEST_NAMES})
			add_executable(
				${ELEMENT}-test
				${TEST_DIR}/${ELEMENT}.cpp						
			)
			target_include_directories(
				${ELEMENT}-test PRIVATE 
				${INCLUDE_DIR}
			)
			target_compile_options(
				${ELEMENT}-test PRIVATE
			)
			add_test(
				NAME ${ELEMENT}-test 
				COMMAND ${ELEMENT}-test
				WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
			)
		endforeach(ELEMENT ${TEST_NAMES})
	endif()

	#*************#
	#* Benchmark *#
	#*************#
	if(BUILD_BENCHMARKS)

		foreach(ELEMENT ${BENCHMARK_NAMES})
			add_executable(
				${ELEMENT}-benchmark 
				${BENCHMARK_DIR}/${ELEMENT}.cpp
			)
			target_include_directories(
				${ELEMENT}-benchmark  PRIVATE 
				${INCLUDE_DIR}	
			)
			target_compile_options(
				${ELEMENT}-benchmark PRIVATE
				-O3 #* optimization level
				-m64 #* x64
				-mavx2 #* enable avx2
				#-fno-math-errno #* disable errno 
				#-ffast-math #* feeling brave?
			)
		endforeach(ELEMENT ${BENCHMARK_NAMES})
	endif()

	#************************#
	#* Packaged source code *#
	#************************#
	add_custom_command(
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-src.zip
		COMMAND ${CMAKE_COMMAND} -E tar c ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-src.zip --format=zip -- ${PACKAGE_FILES}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		DEPENDS ${PACKAGE_FILES}
	)
	add_custom_target(
		src_package 
		DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-src.zip
	)
endif()