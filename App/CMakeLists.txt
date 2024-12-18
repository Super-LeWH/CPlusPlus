# 为源文件设置变量
SET(SRCS
AllInOne.cpp
)

# 为头文件设置变量
SET(HEADERS
AllInOne.h
)

# 创建共享库
add_library(App ${SRCS})

# 设置头文件的包含路径
target_include_directories(App PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 设置安装规则
install(FILES ${HEADERS} DESTINATION include)
install(TARGETS App DESTINATION lib)
