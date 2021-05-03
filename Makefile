# **************************************************************************** #
#                                                                              #
#        ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::   #
#      :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+:  #
#     +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+   #
#    +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:    #
#   +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+            #
#  #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#      #
#   ######    ######  ############## ###    ### ###   ######    #######        #
#                                                                              #
# **************************************************************************** #
#                                                                              #
#    Makefile                                 cclarice@student.21-school.ru    #
#                                                                              #
#    Created/Updated: 2021/05/01 17:41:13  /  2021/05/03 03:33:56 @cclarice    #
#                                                                              #
# **************************************************************************** #

# PROGRESS BAR
ifndef BUILD
sixteen := x x x x x x x x x x x x x x x x
MAX     := $(foreach x,$(sixteen),$(sixteen))
T       := $(shell $(MAKE) -nrRf $(firstword $(MAKEFILE_LIST)) $(MAKECMDGOALS) BUILD="COUNTTHIS" | grep -c "COUNTTHIS")
N       := $(wordlist 1,$T,$(MAX))
counter  = $(words $N) $(eval N := $(wordlist 2,$(words $N),$N))
need     = $(words $N)
done     = $(shell expr $T - $(counter) + 1)
bar     := "=================================================="
BUILD    = @printf "\033[2A\033[32m[%-*.*s] [%1d/%-1d]     \n" $(T) $(done) $(bar) $(need) $T
endif

# HEAD & NAME
NAME = xtox.a
HEAD = xtox.h

# TEST
TEST = test_xtox.c
TSMN = test_xtox

# SRCS
SRCF = src
SRC  = atoi.c atol.c strtoui.c strtoul.c
SRCS = $(addprefix $(SRCF)/, $(SRC))

# OBJS
OBJF = obj
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

# COMPILE
FLAG = -Wall -Wextra -Werror -O4
MKDR = mkdir -p
S    = echo -e
RM   = rm -rf
CC   = clang
AR   = ar rc

# Compile Rule
all: start $(OBJF) $(NAME) done

start:
	@echo "Start [all]\n" 

obj/%.o: src/%.c $(HEAD)
	@$(CC) $(FLAG) -c $< -o $@
	$(BUILD)
	@echo "Compiling $@ > $<"

$(OBJF):
	$(MKDR) $(OBJF)

$(NAME): $(OBJS)
	ar rc $?sd

done:
	@echo "\033[0mDone [all]"

# Test Rule
test: all
	@$(CC) $(FLAG)

# Clean Rule

clean:
	@echo "Start [clean]"
	@$(RM) $(OBJF)
	@echo "\033[31mRemoving $(OBJF)\033[0m"
	@echo "Done [clean]"

fclean:
	@echo "Start [fclean]"
	@$(RM) $(OBJF)
	@echo "\033[31mRemoving $(OBJF)\033[0m"
	@$(RM) $(NAME)
	@echo "\033[31mRemoving $(NAME)\033[0m"
	@echo "Done [fclean]"

re: fclean all
