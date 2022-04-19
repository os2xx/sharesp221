obj-m += hello01.o

EUID=$(shell id -u)
PWD := $(CURDIR)

ifeq ($(CONFIG_STATUS_CHECK_GCC),y)
CC=$(STATUS_CHECK_GCC)
ccflags-y += -fanalyzer
endif

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
