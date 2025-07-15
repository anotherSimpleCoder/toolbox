add_library(CLI
    CLI.cc
)

target_link_libraries(CLI
    NewCommand
)