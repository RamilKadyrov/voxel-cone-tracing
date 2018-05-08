cmake_minimum_required(VERSION 3.5)
project(VoxelConeTracing VERSION 0.1 LANGUAGES CXX)

##############################################
# Declare dependencies

find_package(OpenGL 4.4 REQUIRED)

##############################################
# Create target and set properties

set( CPP_FILES
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
   Source/Utility/External/tiny_obj_loader.cpp
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
   Source/Utility/External/tiny_obj_loader.h
)

add_executable(${PROJECT_NAME} ${CPP_FILES} ${HEADER_FILES})

#Set target properties
target_include_directories(${PROJECT_NAME}
    PUBLIC
    Includes
    Includes/AntTweakBar
    Includes/GL
    Includes/glm
    Includes/GLFW
    Includes/SOIL
)

target_link_libraries(${PROJECT_NAME}
        ${OPENGL_LIBRARY}
    )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_auto_type)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)


##############################################
# Installation instructions

install(TARGETS ${PROJECT_NAME} DESTINATION bin)