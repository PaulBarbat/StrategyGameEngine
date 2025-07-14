#create ENgine as static library
add_library(Engine)

#collect all cpp files from src
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp)

#set source files
target_sources(Engine PRIVATE ${ENGINE_SRC})

#include path
target_include_directories(Engine PUBLIC 
    include
    include/Components
    include/Entities
    include/Map
)

#copy resources to build dir
file(GLOB_RECURSE JSON_FILES resources/*.json)
foreach(json ${JSON_FILES})
    configure_file(${json} ${CMAKE_CURRENT_BINARY_DIR}/resources COPYONLY)
endforeach()