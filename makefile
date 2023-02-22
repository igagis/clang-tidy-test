include $(d)prorab.mk

this_name := test

this_srcs := $(call prorab-src-dir, src)

this_cxxflags += -save-temps=obj
this_cxxflags += -std=c++17
this_cxxflags += -Werror
this_cxxflags += -Wall

this_ldlibs += -lstdc++

this_lint_cmd = $(prorab_lint_cmd_clang_tidy)

$(eval $(prorab-build-app))
