cmake_minimum_required(VERSION 3.5)
project(VoxelConeTracing VERSION 0.1 LANGUAGES CXX)

##############################################
# Declare dependencies
find_package(Git REQUIRED)
find_package(OpenGL 4.4 REQUIRED)
#TODO: git -C {path} pull || git clone https://... {path}

set (git_cmd "git")
set (git_arg1 "clone")
set (git_arg2 "https://github.com/glfw/glfw.git")
set (git_arg3 "external/glfw/src")
message(STATUS "git cmd: ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3}")
execute_process(COMMAND ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3})

set (git_arg2 "https://github.com/RamilKadyrov/AntTweakBar.git")
set (git_arg3 "external/AntTweakBar/src")
message(STATUS "git cmd: ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3}")
execute_process(COMMAND ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3})

set(git_arg2 "-b")
set(git_arg3 "v0.9.x")
set (git_arg4 "https://github.com/syoyo/tinyobjloader.git")
set (git_arg5 "external/tinyobjloader/src")
message(STATUS "git cmd: ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3} ${git_arg4} ${git_arg5}")
execute_process(COMMAND ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3} ${git_arg4} ${git_arg5})

set (git_arg2 "https://github.com/kbranigan/Simple-OpenGL-Image-Library.git")
set (git_arg3 "external/SOIL/src")
message(STATUS "git cmd: ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3}")
execute_process(COMMAND ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3})

set (git_arg2 "https://github.com/RamilKadyrov/glew.git")
set (git_arg3 "external/glew/src")
message(STATUS "git cmd: ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3}")
execute_process(COMMAND ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3})

set (git_arg2 "https://github.com/g-truc/glm.git")
set (git_arg3 "external/glm")
message(STATUS "git cmd: ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3}")
execute_process(COMMAND ${git_cmd} ${git_arg1} ${git_arg2} ${git_arg3})

add_subdirectory(${CMAKE_BINARY_DIR}/external/glew/src/build/cmake external/glew/build)
add_subdirectory(${CMAKE_BINARY_DIR}/external/glfw/src external/glfw/build)
add_subdirectory(${CMAKE_BINARY_DIR}/external/AntTweakBar/src external/AntTweakBar/build)
add_subdirectory(${CMAKE_BINARY_DIR}/external/SOIL/src external/SOIL/build)
add_subdirectory(${CMAKE_BINARY_DIR}/external/tinyobjloader/src external/tinyobjloader/build)
##############################################
# Create symbolic link to assets and shaders
if(WIN32)
STRING(REGEX REPLACE "/" "\\\\" BINARY_DIR ${CMAKE_BINARY_DIR} )
STRING(REGEX REPLACE "/" "\\\\" SOURCE_DIR ${CMAKE_SOURCE_DIR} )

set (SYMLINK_CMD "cmd.exe")
set (SYMLINK_ARG1 "/U")
set (SYMLINK_ARG2 "/C")
set (SYMLINK_ARG3 "mklink")
set (SYMLINK_ARG4 "/J")
set (SYMLINK_ARG5 "${BINARY_DIR}\\Assets")
set (SYMLINK_ARG6 "${SOURCE_DIR}\\Assets")
message(STATUS "symlink cmd: ${SYMLINK_CMD} ${SYMLINK_ARG1} ${SYMLINK_ARG2} ${SYMLINK_ARG3} ${SYMLINK_ARG4} ${SYMLINK_ARG5} ${SYMLINK_ARG6}")
execute_process(COMMAND ${SYMLINK_CMD} ${SYMLINK_ARG1} ${SYMLINK_ARG2} ${SYMLINK_ARG3} ${SYMLINK_ARG4} ${SYMLINK_ARG5} ${SYMLINK_ARG6})

set (SYMLINK_ARG5 "${BINARY_DIR}\\Shaders")
set (SYMLINK_ARG6 "${SOURCE_DIR}\\Shaders")
message(STATUS "symlink cmd: ${SYMLINK_CMD} ${SYMLINK_ARG1} ${SYMLINK_ARG2} ${SYMLINK_ARG3} ${SYMLINK_ARG4} ${SYMLINK_ARG5} ${SYMLINK_ARG6}")
execute_process(COMMAND ${SYMLINK_CMD} ${SYMLINK_ARG1} ${SYMLINK_ARG2} ${SYMLINK_ARG3} ${SYMLINK_ARG4} ${SYMLINK_ARG5} ${SYMLINK_ARG6})

elseif(UNIX)
#TODO
endif()

##############################################
# Create target and set properties

set( CPP_FILES
   voxel-cone-tracing.cpp 
   Source/Application.cpp
   Source/Graphic/Graphics.cpp
   Source/Graphic/Texture2D.cpp
   Source/Graphic/Texture3D.cpp
   Source/Graphic/Camera/Camera.cpp
   Source/Graphic/Camera/OrthographicCamera.cpp
   Source/Graphic/Camera/PerspectiveCamera.cpp
   Source/Graphic/FBO/FBO.cpp
   Source/Graphic/Material/Material.cpp
   Source/Graphic/Material/MaterialStore.cpp
   Source/Graphic/Material/Shader.cpp
   Source/Graphic/Renderer/MeshRenderer.cpp
   Source/Scene/Scenes/CornellScene.cpp
   Source/Scene/Scenes/DragonScene.cpp
   Source/Scene/Scenes/GlassScene.cpp
   Source/Scene/Scenes/MultipleObjectsScene.cpp
   Source/Shape/Mesh.cpp
   Source/Shape/StandardShapes.cpp
   Source/Shape/Transform.cpp
   Source/Time/Time.cpp
   Source/Utility/ObjLoader.cpp
)
set( HEADER_FILES
   Source/Application.h
   Source/Graphic/Graphics.h
   Source/Graphic/Texture2D.h
   Source/Graphic/Texture3D.h
   Source/Graphic/Camera/Camera.h
   Source/Graphic/Camera/OrthographicCamera.h
   Source/Graphic/Camera/PerspectiveCamera.h
   Source/Graphic/Camera/Controllers/FirstPersonController.h
   Source/Graphic/FBO/FBO.h
   Source/Graphic/Lighting/PointLight.h
   Source/Graphic/Material/Material.h
   Source/Graphic/Material/MaterialStore.h
   Source/Graphic/Material/MaterialSetting.h
   Source/Graphic/Material/Shader.h
   Source/Graphic/Renderer/MeshRenderer.h
   Source/Scene/Scene.h
   Source/Scene/ScenePack.h
   Source/Scene/Scenes/CornellScene.h
   Source/Scene/Scenes/DragonScene.h
   Source/Scene/Scenes/GlassScene.h
   Source/Scene/Scenes/MultipleObjectsScene.h
   Source/Shape/Mesh.h
   Source/Shape/Shape.h
   Source/Shape/StandardShapes.h
   Source/Shape/Transform.h
   Source/Shape/VertexData.h
   Source/Time/Time.h
   Source/Utility/ObjLoader.h
)

add_executable(${PROJECT_NAME} ${CPP_FILES} ${HEADER_FILES})

#Set target properties
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_BINARY_DIR}/external/glm
    ${CMAKE_BINARY_DIR}/external/SOIL/src/src
#    ${CMAKE_BINARY_DIR}/external/glfw/src/include
    ${CMAKE_BINARY_DIR}/external/glew/src/include
#    ${CMAKE_BINARY_DIR}/external/AntTweakBar/src/include
    ${CMAKE_BINARY_DIR}/external/tinyobjloader/src
)

target_link_libraries(${PROJECT_NAME}
        ${OPENGL_LIBRARY}
	SOIL
        ${SOIL_LIBRARIES}
        glew_s
        ${GLEW_LIBRARY}
        glfw
        ${GLFW_LIBRARIES}
        AntTweakBar
        ${AntTweakBar_LIBRARIES}
        tinyobjloader
        ${tinyobjloader_LIBRARIES}
    )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_auto_type)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)


##############################################
# Installation instructions

install(TARGETS ${PROJECT_NAME} DESTINATION bin)