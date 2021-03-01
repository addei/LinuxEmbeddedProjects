src = $(wildcard source/*.c)
obj = $(src:.c=.o)
dep = $(obj:.o=.d)  # dependency files

LDFLAGS = -lz -lm -lwiringPi -lwiringPiDev  # linker flags
CFLAGS = -MMD                  # compiler flags

ipv4_16x2: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)
	
-include $(dep)   # include all dep files in the makefile

%.d: %.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(obj) ipv4_16x2

.PHONY: cleandep
cleandep:
	rm -f $(dep)
