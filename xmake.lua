add_rules("mode.debug", "mode.release")
add_requires("opencv")

target("mango")
    set_kind("shared")
    add_includedirs("src/include")
    add_files("src/**.cpp")
    add_packages("opencv")

target("Dome")
    set_kind("binary")
    add_includedirs("src/include")
    add_files("Dome/*.cpp")
    add_deps("mango")
    add_packages("opencv")

