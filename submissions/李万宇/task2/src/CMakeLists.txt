# 获取所有的源文件
set(SOURCES
    attendance.cpp
    manage.cpp
    person.cpp
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})