# REV05: Tue 26 Apr 2022 01:19:31 PM WIB
# REV04: Tue 19 Apr 2022 01:59:03 WIB
# REV03: Sun 17 Apr 2022 17:30:00 WIB
# REV02: Tue 05 Apr 2022 12:30:00 WIB
# REV01: Mon 04 Apr 2022 17:00:00 WIB
# START: Sun 03 Apr 2022 11:30:00 WIB
# 

obj-m          += hello01.o
obj-m          += hello02.o
hello02-objs   := hello02a.o hello02b.o
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

# ZCZC 15
H02ins:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod  hello02.ko
	modinfo hello02.ko
	lsmod   | grep hello02
H02del:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod   hello02

