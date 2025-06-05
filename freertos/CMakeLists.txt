# 이 명령어는 이미 정의된 ${PROJECT_NAME}이라는 이름의 타겟에 컴파일할 소스 파일들을 추가합니다. 
# ${PROJECT_NAME}은 보통 add_executable()이나 add_library() 명령어로 먼저 생성된 타겟의 이름입니다.
# PRIVATE 키워드:
# 여기에 나열된 소스 파일들은 ${PROJECT_NAME} 타겟을 빌드하는 데에만 사용된다는 것을 의미합니다. 
# 만약 ${PROJECT_NAME}이 라이브러리라면, 이 소스 파일들은 해당 라이브러리를 사용하는 다른 타겟에게는 직접적인 빌드 정보로 전파되지 않습니다 
# (즉, 이 소스 파일들이 다른 타겟의 컴파일에 직접 영향을 주지 않음). 실행 파일의 경우, 이 키워드는 주로 "이 소스들은 이 실행 파일의 내부 구현용이다"라는 의미로 사용됩니다.

target_sources(${PROJECT_NAME}
    PRIVATE
    # {{BEGIN_TARGET_SOURCES}}
    ${CMAKE_CURRENT_LIST_DIR}/portable/${FREERTOS_TOOLCHAIN}/RH850/port.c
    ${CMAKE_CURRENT_LIST_DIR}/portable/${FREERTOS_TOOLCHAIN}/RH850/portasm.s
    ${CMAKE_CURRENT_LIST_DIR}/portable/MemMang/heap_1.c
    ${CMAKE_CURRENT_LIST_DIR}/croutine.c
    ${CMAKE_CURRENT_LIST_DIR}/event_groups.c
    ${CMAKE_CURRENT_LIST_DIR}/list.c
    ${CMAKE_CURRENT_LIST_DIR}/queue.c
    ${CMAKE_CURRENT_LIST_DIR}/stream_buffer.c
    ${CMAKE_CURRENT_LIST_DIR}/tasks.c
    ${CMAKE_CURRENT_LIST_DIR}/timers.c
    # {{END_TARGET_SOURCES}}
)


# 이 명령어는 ${PROJECT_NAME} 타겟을 컴파일할 때 컴파일러가 헤더 파일(예: #include "my_header.h")을 찾기 위해 
# 검색할 디렉토리 목록을 지정합니다.
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/portable/${FREERTOS_TOOLCHAIN}/RH850
)
