# Define default run function
define DEFAULT_RUN
	clang main.c -o main
	./main $(1) $(2)
endef

# Invoke default run
run:
	$(call DEFAULT_RUN, $(input), $(output))

# Invoke modified run
open:
	$(call DEFAULT_RUN, $(input), $(output))
	nvim shell.sh

	