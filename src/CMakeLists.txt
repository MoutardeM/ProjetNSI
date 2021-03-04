file(GLOB_RECURSE source *.c)
file(GLOB_RECURSE header *.h)

add_executable(MarsMap ${source} ${header})
target_link_libraries(MarsMap GL GLEW glfw m)

#
# Ajouter les commentaires sur tt le programme
#

