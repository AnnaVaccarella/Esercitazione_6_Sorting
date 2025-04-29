# Imposta lo standard C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Inizializza le variabili per sicurezza
set(src_sources "")
set(src_headers "")
set(src_includes "")

# Aggiungi i file sorgenti e header
list(APPEND src_sources ${CMAKE_CURRENT_SOURCE_DIR}/sorts.cpp)
list(APPEND src_headers ${CMAKE_CURRENT_SOURCE_DIR}/sorts.hpp)
list(APPEND src_includes ${CMAKE_CURRENT_SOURCE_DIR})


if(NOT "${src_sources}" STREQUAL "")
    add_library(sorts STATIC ${src_sources})
    target_include_directories(sorts PUBLIC ${src_includes})
endif()

# Esporta le variabili al livello superiore
set(src_sources ${src_sources} PARENT_SCOPE)
set(src_headers ${src_headers} PARENT_SCOPE)
set(src_includes ${src_includes} PARENT_SCOPE)





