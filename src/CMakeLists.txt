set(S4_ECS_INCLUDE ${CMAKE_CURRENT_LIST_DIR})

# gather source files list
file(GLOB_RECURSE S4_ECS_SRCS RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    ${S4_ECS_INCLUDE}/*.cpp 
    ${S4_ECS_INCLUDE}/*.hpp 
    ${S4_ECS_INCLUDE}/*.hpp)
GenerateSourceGoups("${S4_ECS_SRCS}")

add_library(${S4_ECS_TARGET} STATIC ${S4_ECS_SRCS})
target_compile_features(${S4_ECS_TARGET} PUBLIC cxx_std_20)
target_include_directories(${S4_ECS_TARGET} PUBLIC ${S4_ECS_INCLUDE})

target_link_libraries(${S4_ECS_TARGET} PUBLIC stduuid)