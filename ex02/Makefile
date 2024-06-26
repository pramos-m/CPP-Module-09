# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 16:51:54 by pramos-m          #+#    #+#              #
#    Updated: 2024/05/28 16:51:55 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<--------------------------------->COLORS<----------------------------------->#
DEF_COLOR	:=	\033[1;97m
WHITE_BOLD	:=	\033[1m
BLACK		:=	\033[1;90m
RED			:=	\033[1;91m
GREEN		:=	\033[1;92m
YELLOW		:=	\033[1;93m
BLUE		:=	\033[1;94m
PINK		:=	\033[1;95m
CIAN		:=	\033[1;96m

#<--------------------------------->NAME<------------------------------------>#
PRENAME		:=	"PmergeMe"
NAME		:=	$(shell echo $(PRENAME) | tr ' ' '_')

#<--------------------------------->VARS<------------------------------------>#
NULL		:=
SPACE		:=	$(NULL) #

#<--------------------------------->ROOTS<----------------------------------->#
LIB_ROOT	:=	lib/

LIBFT_ROOT	:=	$(LIB_ROOT)libft/

SRC_ROOT	:=	src/
OBJ_ROOT	:=	.objs/
DEP_ROOT	:=	.deps/
INC_ROOT	:=	inc/

#<-------------------------------->LIBRARYS<--------------------------------->#
LIB_A		:=

LIB_ADD_DIR	:=

LIB_SEARCH	:=

#<-------------------------------->HEADERS<---------------------------------->#
HEADERS		:=	$(INC_ROOT)

#<---------------------------------->DIRS<----------------------------------->#
SRC_DIRS	:=	./
SRC_DIRS	:=	$(subst :,$(SPACE),$(SRC_DIRS))
SRC_DIRS	:=	$(addprefix $(SRC_ROOT),$(SRC_DIRS))
SRC_DIRS	:=	$(subst $(SPACE),:,$(SRC_DIRS))

#<--------------------------------->FILES<---------------------------------->#
FILES		:=	main PmergeMe

#<---------------------------------->LANG<---------------------------------->#
LANG		:=	CPP
CFLAGS		:=	-Wall -Wextra -Werror -g -fsanitize=address

ifeq ($(LANG),C)
	CC := cc
	SUFFIX := c
else
	CC := c++
	SUFFIX := cpp
	CFLAGS += -std=c++98
endif

#<--------------------------------->SRCS<----------------------------------->#
SRCS		:=	$(addsuffix .$(SUFFIX),$(FILES))

#<----------------------------->OBJS && DEPS<------------------------------->#
OBJS		:=	$(addprefix $(OBJ_ROOT),$(subst .$(SUFFIX),.o,$(SRCS)))
DEPS		:=	$(addprefix $(DEP_ROOT),$(subst .$(SUFFIX),.d,$(SRCS)))

#<-------------------------------->COMANDS<---------------------------------->#
INCLUDE		:=	$(addprefix -I,$(HEADERS))
RM			:=	rm -rf
MKD			:=	mkdir -p
MK			:=	Makefile
MKFLAGS		:=	--no-print-directory
MUTE		:=	&> /dev/null


#<--------------------------------->VPATHS<---------------------------------->#

vpath %.$(SUFFIX) $(SRC_DIRS)
vpath %.d $(DEP_ROOT)

#<-------------------------------->FUNCTIONS<-------------------------------->#

define msg_creating
	printf "\r$(3)$(1): $(YELLOW)$(2).$(DEF_COLOR)                                                                 \r"
	sleep 0.01
	printf "\r$(3)$(1): $(YELLOW)$(2)..$(DEF_COLOR)                                                                \r"
	sleep 0.01
	printf "\r$(3)$(1): $(YELLOW)$(2)...$(DEF_COLOR)                                                               \r"
	sleep 0.01
endef

create_dir = $(shell $(MKD) $(1))

#<--------------------------------->RULES<----------------------------------->#

all : $(NAME)

.SECONDEXPANSION:

$(DEP_ROOT)%.d : %.$(SUFFIX) $(MK) | $$(call create_dir,$$(DEP_ROOT))
	$(call msg_creating,Dependence,$*,$(BLUE))
	$(CC) $(CFLAGS) -MMD -MF $@ $(INCLUDE) -c $< && rm -rf $(addsuffix .o,$*)
	sed -i.tmp '1 s|:| $@ :|' $@ && rm -rf $(addsuffix .tmp,$@)
	sed -i.tmp '1 s|^$*|$(OBJ_ROOT)$*|' $@ && rm -rf $(addsuffix .tmp,$@)

$(OBJ_ROOT)%.o : %.$(SUFFIX) $(MK) %.d $(LIB_A) | $$(call create_dir,$$(OBJ_ROOT))
	$(call msg_creating,Object,$*,$(PINK))
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "\n$(GREEN)"$(NAME)" has been compiled\n$(DEF_COLOR)"

clean :
	$(RM) $(OBJ_ROOT) $(DEP_ROOT)
	echo ""
	echo "$(RED)All OBJS && DEPS has been removed$(DEF_COLOR)"
	echo ""

fclean :
	$(MAKE) $(MKFLAGS) clean
	$(RM) $(NAME)
	echo ""
	echo "$(RED)Program has been removed$(DEF_COLOR)"

re :
	$(MAKE) $(MKFLAGS) fclean
	$(MAKE) $(MKFLAGS) all
	echo ""
	echo "$(CIAN)$(NAME) has been recompiled$(DEF_COLOR)"

.PHONY : all clean fclean re

.SILENT :

ifeq (,$(filter-out all $(NAME),$(MAKECMDGOALS)))
 -include $(DEPS)
endif
