cmake_minimum_required(VERSION 2.8.2)

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

# Trivial example using gtest and gmock
add_executable(quick_union_with_path_compression_tests quick_union_with_path_compression_tests.cc)
target_link_libraries(quick_union_with_path_compression_tests gtest gmock_main algorithms)

add_executable(singly_link_list_tests singly_link_list_tests.cc)
target_link_libraries(singly_link_list_tests gtest gmock_main algorithms)

add_executable(doubly_link_list_tests doubly_link_list_tests.cc)
target_link_libraries(doubly_link_list_tests gtest gmock_main algorithms)

add_executable(stack_using_link_list_tests stack_using_link_list_tests.cc)
target_link_libraries(stack_using_link_list_tests gtest gmock_main algorithms)

add_executable(stack_using_resizing_array_tests stack_using_resizing_array_tests.cc)
target_link_libraries(stack_using_resizing_array_tests gtest gmock_main algorithms)

add_executable(queue_using_link_list_tests queue_using_link_list_tests.cc)
target_link_libraries(queue_using_link_list_tests gtest gmock_main algorithms)

add_executable(queue_using_resizing_array_tests queue_using_resizing_array_tests.cc)
target_link_libraries(queue_using_resizing_array_tests gtest gmock_main algorithms)

add_executable(selection_sort_tests selection_sort_tests.cc)
target_link_libraries(selection_sort_tests gtest gmock_main algorithms)

add_executable(insertion_sort_tests insertion_sort_tests.cc)
target_link_libraries(insertion_sort_tests gtest gmock_main algorithms)

add_executable(shell_sort_tests shell_sort_tests.cc)
target_link_libraries(shell_sort_tests gtest gmock_main algorithms)

add_executable(shuffle_tests shuffle_tests.cc)
target_link_libraries(shuffle_tests gtest gmock_main algorithms)

add_executable(merge_sort_tests merge_sort_tests.cc)
target_link_libraries(merge_sort_tests gtest gmock_main algorithms)