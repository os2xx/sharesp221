# REV04X Tue 19 Apr 2022 01:59:03 PM WIB
# REV04 Mon 18 Apr 2022 23:00:00 WIB
# REV03 Sun 17 Apr 2022 17:30:00 WIB
# REV02 Tue 05 Apr 2022 12:30:00 WIB
# REV01 Mon 04 Apr 2022 17:00:00 WIB
# START Sun 03 Apr 2022 11:30:00 WIB
# 

obj-m          += hello01.o
ccflags-y      := -std=gnu18

all:
ifeq ($(shell id -u), 0)
	@echo "No ROOT, please!"
	@exit 1
endif
	+make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	+make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

help:
	@echo "all"
	@echo "clean"
	@echo "HXins"
	@echo "HXdel"
	@echo "help"

# ZCZC 15
H01ins:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod  hello01.ko
	modinfo hello01.ko
	lsmod   | grep hello01
H01del:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod   hello01

