# REV04X Tue 19 Apr 2022 01:59:03 PM WIB
# REV04 Mon 18 Apr 2022 23:00:00 WIB
# REV03 Sun 17 Apr 2022 17:30:00 WIB
# REV02 Tue 05 Apr 2022 12:30:00 WIB
# REV01 Mon 04 Apr 2022 17:00:00 WIB
# START Sun 03 Apr 2022 11:30:00 WIB
#

obj-m += hello01.o
obj-m += hello02.o
hello02-objs += hello02a.o hello02b.o
obj-m += hello03.o
obj-m += hello04.o

EUID=$(shell id -u)
PWD := $(CURDIR)

ccflags-y := -std=gnu18

all:
ifeq ($(EUID),0)
	@echo "No ROOT, please!"
	@exit 1
endif
	+make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) modules

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
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod hello01.ko
	modinfo hello01.ko
	lsmod   | grep hello01

H01del:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod hello01

H02ins:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod hello02.ko
	modinfo hello02.ko
	lsmod   | grep hello02

H02del:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod hello02

H03ins:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod hello03.ko myshort=69 myint=888 mylong=1234567890  mystring="newString" myintArray=1,2,3,4,5
	modinfo hello03.ko
	lsmod   | grep hello03

H03del:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod hello03

H04ins:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod hello04.ko
	modinfo hello04.ko
	lsmod   | grep hello04

H04del:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod hello04
