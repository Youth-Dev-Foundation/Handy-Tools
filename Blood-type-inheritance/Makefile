# Define main function, call clang and execute file
define DEFAULT_RUN
	clang blood-type.c -o blood-type
	./blood-type $(1)
endef

# Create 'Makefile' called inheritance
inheritance:
	$(call DEFAULT_RUN, $(gen))
