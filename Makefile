#############
# Functions #
#############

uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))

#############
# Variables #
#############

NAME	:= term3d
B_NAME	:= term3d
CC		:= gcc
LIBFTDIR:= ./Libft
LIBFT	:= $(LIBFTDIR)/libft.a
INCLUDE	:= -I./includes -I$(LIBFTDIR)
CFLAGS	:= -g -Wall -Werror -Wextra $(INCLUDE)
LIBS	:= -lm -L$(LIBFTDIR) -lft
VPATH	:= srcs/

SRCS	:= main.c error.c key_action.c rotation.c draw.c object.c translation.c shade.c utils.c
SRCDIRS	:= $(call uniq, $(dir $(SRCS)))

OBJDIR	:= build/
OBJDIRS	:= $(addprefix $(OBJDIR), $(SRCDIRS))
OBJS	:= $(addprefix $(OBJDIR), $(SRCS:%.c=%.o))

B_SRCS	:= $(SRCS)
B_OBJS	:= $(B_SRCS:%.c=$(SRCDIR)%.o)
B_FLG	:= .bonus_flg

DEPS	:= $(addprefix $(OBJDIR), $(SRCS:%.c=%.d))

DSTRCTR	:= ./destructor.c

#################
# General rules #
#################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

bonus: $(B_FLG)

$(B_FLG): $(LIBFT) $(OBJDIRS) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(NAME) $(LIBS)
	touch $(B_FLG)

clean: FORCE
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS) $(B_OBJS) $(DEPS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME) $(B_NAME)
	$(RM) -r $(NAME).dSYM $(B_NAME).dSYM

re: fclean all

norm: FORCE
	@printf "$(RED)"; norminette | grep -v ": OK!" \
	&& exit 1 \
	|| printf "$(GREEN)%s\n$(END)" "Norm OK!"

$(LIBFT):
	$(MAKE) bonus -C $(LIBFTDIR)

$(OBJDIRS):
	mkdir -p $@

$(OBJDIR)%.o: %.c
	@printf "$(THIN)$(ITALIC)"
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
	@printf "$(END)"

-include $(DEPS)

.PHONY: FORCE
FORCE:

###############
# Debug rules #
###############

$(DSTRCTR):
	curl https://gist.githubusercontent.com/ywake/793a72da8cdae02f093c02fc4d5dc874/raw/destructor.c > $(DSTRCTR)

sani: $(LIBFT) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME) $(LIBS)

Darwin_leak: $(LIBFT) $(DSTRCTR) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DSTRCTR) -o $(NAME) $(LIBS)

Linux_leak: sani

leak: $(shell uname)_leak

bonus_sani: $(LIBFT) $(OBJDIRS) $(B_OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(B_OBJS) -o $(B_NAME) $(LIBS)

bonus_Darwin_leak: $(LIBFT) $(DSTRCTR) $(OBJDIRS) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) $(DSTRCTR) -o $(B_NAME) $(LIBS)

bonus_Linux_leak: bonus_sani

bonus_leak: bonus_$(shell uname)_leak

##############
# Test rules #
##############

CXX			:= clang++
CXXFLAG		:= -std=c++11 -DDEBUG -g -fsanitize=integer -fsanitize=address -Wno-writable-strings
gTestDir	:= ./.google_test
gVersion	:= release-1.11.0
gTestVer	:= googletest-$(gVersion)
gTest		:= $(gTestDir)/gtest $(gTestDir)/$(gTestVer)

TESTDIR		:= ./tests/
TESTSRCS_C	:= $(filter-out main.c,$(SRCS))
TESTSRCS_CPP:= $(wildcard $(TESTDIR)*.cpp)
TESTOBJS	:= $(addprefix $(SRCDIR), $(TESTSRCS_C:%.c=%.o)) \
				$(TESTSRCS_CPP:%.cpp=%.o)

%.o: %.cpp
	$(CXX) $(CXXFLAG) -I$(gTestDir) $(INCLUDE) -c $< -o $@

$(gTest):
	mkdir -p $(gTestDir)
	curl -OL https://github.com/google/googletest/archive/refs/tags/$(gVersion).tar.gz
	tar -xvzf $(gVersion).tar.gz $(gTestVer)
	$(RM) $(gVersion).tar.gz
	python $(gTestVer)/googletest/scripts/fuse_gtest_files.py $(gTestDir)
	mv $(gTestVer) $(gTestDir)

test: $(gTest) $(TESTOBJS)
	@$(CXX) $(CXXFLAG) \
		$(TESTOBJS) \
		$(gTestDir)/$(gTestVer)/googletest/src/gtest_main.cc \
		$(gTestDir)/gtest/gtest-all.cc \
		-I$(gTestDir) $(INCLUDE) $(LIBS) -lpthread -o test && ./test

test_clean: FORCE
	$(RM) $(TESTOBJS)

test_fclean: test_clean
	$(RM) -r tester tester.dSYM

test_re: test_fclean test

##########
# Colors #
##########

END		= \e[0m
BOLD	= \e[1m
THIN	= \e[2m
ITALIC	= \e[3m
U_LINE	= \e[4m
BLACK	= \e[30m
RED		= \e[31m
GREEN	= \e[32m
YELLOW	= \e[33m
BLUE	= \e[34m
PURPLE	= \e[35m
CYAN	= \e[36m
WHITE	= \e[37m
