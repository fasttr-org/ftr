
OS    ?= $(shell uname)
ARCH  ?= $(shell arch)
OUT   := ../out/$(OS).$(ARCH)/test2
CXX   ?= g++
NAME  ?= test2

# -ffunction-sections -fdata-sections 
FLAGS 		= -Wall -g -O0 -I. '-DDEBUG' '-D_DEBUG'
CXXFLAGS 	= -std=c++0x -fexceptions -frtti
LINKFLAGS = -lGLESv2 -lEGL -lX11 -pthread

SOURCES = test2.cc  \
					test2-xim.cc \
					test2-x11.cc \
					test2-thread.cc \

OBJECTS = $(addsuffix .o,$(basename $(SOURCES)))

.SECONDEXPANSION:

.PHONY: all

flags = $(FLAGS) $(if $(shell sh -c "if [ -f $(basename $@).c ]; then echo ok; fi"),,$(CXXFLAGS))

all: $(OBJECTS)
	@$(CXX) -o $(OUT)/$(NAME) \
	-Wl,--whole-archive $(addprefix $(OUT)/,$(OBJECTS)) -Wl,--no-whole-archive $(LINKFLAGS)
	@echo LINK $(OUT)/$(NAME)

$(OBJECTS): $$(basename $$@).c*
	@mkdir -p $(dir $(OUT)/$@)
	@$(CXX) $(flags) -MMD -MF $(OUT)/$@.d.raw -c -o $(OUT)/$@ $(basename $@).c*
	@echo CXX $(OUT)/$@
