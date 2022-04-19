obj-m += hello01.o
ccflags-y := -std=gnu18

all:
ifeq ($(shell id -u), 0)
	@echo "No ROOT, please"!
	@exit 1
endif
	+make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

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

clean:
	+make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
