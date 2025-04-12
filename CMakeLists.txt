cmake_minimum_required(VERSION 3.10)
project(main)                                          #必须

find_package(Protobuf 3 REQUIRED)

# add_subdirectory(子文件夹名称)                         #父目录必须，子目录不必

# 获取路径下所有的.cpp/.c/.cc文件，并赋值给变量中
aux_source_directory(${PROJECT_SOURCE_DIR}/ APPS)

# add_library(库文件名称 STATIC 文件)                    #通常子目录(二选一)
add_executable(${PROJECT_NAME}                         #通常父目录(二选一)
    ${APPS} 
    )                     

# include_directories(路径)                              #必须
# link_directories(路径)                                 #必须

target_link_libraries(${PROJECT_NAME} PUBLIC

    ${Protobuf_LIBRARIES}
)       #必须
