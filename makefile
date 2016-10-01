# ------------------------------------------------------------------------------
# name:   C/C++ makefile
# author: chenyao
# mail:   cheny@meizu.com
# date:   2016年 09月 29日 星期四 22:51:27 CST
# 
# directory:
# 	bin/
# 		main
# 	obj/
# 		*.o
# 		*.d
# 	include/
# 		*.h
# 	source/
# 		*.cpp
#
# ------------------------------------------------------------------------------
#
#
# ------------------------------------------------------------------------------
TARGET   :=main
LIBS     :=

PATH_LIB :=
PATH_INC :=include
PATH_SRC :=source
PATH_OBJ :=obj/
PATH_BIN :=bin/

CXX      :=g++
CPPFLAGS :=-g -Wall -O3
CPPFLAGS +=$(addprefix -I,$(PATH_INC))
CPPFLAGS +=-MMD

RM :=rm -f

BINS :=$(addprefix $(PATH_BIN),$(TARGET))
SRCS :=$(foreach n,$(PATH_SRC),$(wildcard $(addsuffix .cpp,$(n)/*))) 
OBJS :=$(addprefix $(PATH_OBJ),$(addsuffix .o,$(basename $(notdir $(SRCS))))) 
DEPS :=$(patsubst %.o,%.d,$(OBJS))
DEPS_MISS :=$(filter-out $(wildcard $(DEPS)),$(DEPS))

vpath %.h   $(PATH_INC)
vpath %.cpp $(PATH_SRC)


.PHONY: all clean rebuild info

all: $(PATH_BIN) $(PATH_OBJ) $(BINS)

$(PATH_BIN): ; -mkdir $(PATH_BIN)
$(PATH_OBJ): ; -mkdir $(PATH_OBJ)

$(PATH_OBJ)%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

ifneq ($(DEPS_MISS),)
$(DEPS_MISS):
	@$(RM) $(patsubst %.d,%.o,$@)
endif

$(BINS): $(OBJS)
	$(CXX) -o $(BINS) $(OBJS) $(addprefix -l,$(LIBS))

clean:
	@$(RM) $(BINS)
	@$(RM) $(OBJS)
	@$(RM) $(DEPS)

rebuild: clean all

info:
	@echo binexe:$(BINS)
	@echo source:$(SRCS)
	@echo object:$(OBJS)
	@echo depend:$(DEPS)
	@echo depend_missing:$(DEPS_MISS)
