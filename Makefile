CC:=gcc # The compiler
CFLAGS:=-Wall -Wextra -Werror -pedantic  -std=gnu89 # Compiltion flags

TARGET:=sort.out # Output name
SRCS:=print_array.c print_list.c # Source files


# make (0~1000)
%: ./mains/%-main.c 
	$(CC)$(CFLAGS) -o $(TARGET) $(SRCS) $<  $(wildcard $@-*.c)

# make o(0~1000)
o%: ./output/%-output.txt
	@./$(TARGET)
	@cat $<

# Clean Target
clean:
	rm $(TARGET)
