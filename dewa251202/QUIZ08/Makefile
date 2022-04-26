obj-m += hello01.o
obj-m += hello02.o
obj-m += hello03.o
obj-m += hello04.o
obj-m += hello05.o
hello02-objs := hello02a.o hello02b.o

PWD := $(CURDIR)

all: 
ifeq ($(shell id -u), 0)
	@echo "No ROOT, please!"
	@exit 1
endif
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

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
	rmmod  hello01.ko

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
	rmmod  hello02.ko

H03ins:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod  hello03.ko
	modinfo hello03.ko
	lsmod   | grep hello03

H03del:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod  hello03.ko

H04ins:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod  hello04.ko
	modinfo hello04.ko
	lsmod   | grep hello04
	ls -al /proc/helloworld
	cat    /proc/helloworld

H04del:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod  hello04.ko

H05ins:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	insmod  hello05.ko
	modinfo hello05.ko
	lsmod   | grep hello05

H05del:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif
	rmmod  hello05.ko
