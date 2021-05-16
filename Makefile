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
#    Created/Updated: 2021/05/09 19:15:49  /  2021/05/10 20:30:20 @cclarice    #
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
TSTN = test_xtox

# SRCS
SRCF = src
SRC  = ft_atoi.c    ft_itoa.c \
       ft_atol.c    ft_ltoa.c \
       ft_atod.c  \
       ft_atoui.c \
       ft_atoul.c

SRCS = $(addprefix $(SRCF)/, $(SRC))

# OBJS
OBJF = obj
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

# COMPILE
FLAG = -Wall -Wextra -Werror -O3
MKDR = mkdir -p
S    = echo -e
RM   = rm -rf
CC   = clang
AR   = ar rc

# Compile Rule
all: start $(OBJF) $(NAME) done

start:
	@$S "Start [all]\n" 

obj/%.o: src/%.c $(HEAD)
	@$(CC) $(FLAG) -c $< -o $@
	$(BUILD)
	@$S "Compiling $@ > $<"

$(OBJF):
	$(MKDR) $(OBJF)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

done:
	@$S "\033[0mDone [all]"

# Test Rule
test: all $(NAME)
	@$S "Start [test]"
	@$(CC) $(FLAG) $(TEST) $(NAME) -o $(TSTN)
	@$S "\033[32mCompiling $(TSTN)"
	@$S "\033[0mDone [test]"

# Clean Rules
clean:
	@$S "Start [clean]"
	@$(RM) $(OBJF)
	@$S "\033[31mRemoving $(OBJF)\033[0m"
	@$S "Done [clean]"

fclean:
	@$S "Start [fclean]"
	@$(RM) $(OBJF)
	@$S "\033[31mRemoving $(OBJF)\033[0m"
	@$(RM) $(NAME)
	@$S "\033[31mRemoving $(NAME)\033[0m"
	@$(RM) $(TSTN)
	@$S "\033[31mRemoving $(TSTN)\033[0m"
	@$S "Done [fclean]"

# My temp rule
temp: clearscreen test
	@./test_xtox
	@norminette src

clearscreen:
	@clear