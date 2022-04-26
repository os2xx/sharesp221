obj-m += hello01.o
obj-m += hello02.o
hello02-objs += hello02a.o hello02b.o
obj-m += hello03.o
obj-m += hello04.o

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

H02ins:
ifneq ($(shell id -u),0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod hello02.ko
	modinfo hello02.ko
	lsmod   | grep hello02

H02del:
ifneq ($(shell id -u),0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod hello02

H03ins:
ifneq ($(shell id -u),0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod hello03.ko myshort=69 myint=888 mylong=1234567890  mystring="newString" myintArray=1,2,3,4,5
	modinfo hello03.ko
	lsmod   | grep hello03

H03del:
ifneq ($(shell id -u),0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod hello03

H04ins:
ifneq ($(shell id -u),0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod hello04.ko
	modinfo hello04.ko
	lsmod   | grep hello04
	@echo "=================================="
	ls -al /proc/helloworld
	cat /proc/helloworld
	@echo "=================================="

H04del:
ifneq ($(shell id -u),0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod hello04
