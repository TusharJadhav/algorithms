include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms
)

set(SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/recency_map.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/quick_union_with_path_compression.cc
)

add_library(algorithms SHARED ${SRCS})

# Specify here the include directories exported
# by this library
target_include_directories(algorithms PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms
)

add_subdirectory( tests )
