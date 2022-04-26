obj-m += hello01.o
obj-m += hello02.o
hello02-objs += hello02a.o hello02b.o
obj-m += hello03.o
obj-m += hello04.o
obj-m += hello05.o
obj-m += hello06.o

EUID=$(shell id -u)
PWD := $(CURDIR)

ccflags-y := -std=gnu18

all:
ifeq ($(EUID),0)
	@echo "No ROOT, please!"
	@exit 1
endif
	+make -C /lib/modules/$(shell uname -r)/build CC=$(CC) M=$(PWD) modules

clean:
	+make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

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

H05ins:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod hello05.ko
	modinfo hello05.ko
	lsmod   | grep hello05

H05del:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod hello05

H06ins:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod hello06.ko
	modinfo hello06.ko
	lsmod   | grep hello06
	@echo "===== ===== ===== ===== ====="
	cat    /proc/buffer1k
	@echo "===== ===== ===== ===== ====="
	echo "XXX" > /proc/buffer1k
	@echo "===== ===== ===== ===== ====="

H06del:
ifneq ($(EUID),0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod hello06