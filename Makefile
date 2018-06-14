# makefile of all

all: 
	@echo "<xianmin> all makefile begin"
	$(MAKE) -C src
	@echo "<xianmin> all makefile end"

.PHONY : clean
clean:
	@echo "<xianmin> all makefile Clean begin"
	$(MAKE) clean -C src
	@echo "<xianmin> all makefile Clean end"	