# REV07: Thu 05 May 2022 07:30:00 WIB
# REV06: Tue 26 Apr 2022 00:30:00 WIB
# REV05: Mon 25 Apr 2022 23:00:00 WIB
# REV03: Sun 17 Apr 2022 17:30:00 WIB
# REV01: Mon 04 Apr 2022 17:00:00 WIB
# START: Sun 03 Apr 2022 11:30:00 WIB
# 

obj-m          += hello01.o
obj-m          += hello02.o
hello02-objs   := hello02a.o hello02b.o
obj-m          += hello03.o
obj-m          += hello04.o
obj-m          += hello05.o
obj-m          += hello06.o
ccflags-y      := -std=gnu18

all: usermode
	+make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

H01ins: rootmode
	insmod  hello01.ko
	modinfo hello01.ko
	lsmod   | grep hello01
H01del: rootmode
	rmmod   hello01

H02ins: rootmode
	insmod  hello02.ko
	modinfo hello02.ko
	lsmod   | grep hello02
H02del: rootmode
	rmmod   hello02

# ZCZC 15
H03ins: rootmode
	insmod  hello03.ko
	lsmod   | grep hello03
	rmmod   hello03
	insmod  hello03.ko myshort=69 myint=888 mylong=1234567890  mystring="newString" myintArray=1,2,3,4,5
	lsmod   | grep hello03
	rmmod   hello03
	insmod  hello03.ko myshort=99 myint=999 mylong=1122334455  mystring="lastString" myintArray=11,22,33,44,55
	modinfo hello03.ko
	lsmod   | grep hello03
H03del: rootmode
	rmmod   hello03

# ZCZC
H04ins:rootmode
	insmod  hello04.ko
	modinfo hello04.ko
	lsmod   | grep hello04
	@echo "===== ===== ===== =====  ===== ===== ===== ===== ====="
	ls -al /proc/helloworld
	cat    /proc/helloworld
	@echo "===== ===== ===== =====  ===== ===== ===== ===== ====="
H04del:rootmode
	rmmod   hello04

H05ins:rootmode
	insmod  hello05.ko
	modinfo hello05.ko
	lsmod   | grep hello05
H05del:rootmode
	rmmod   hello05

H06ins:rootmode
	insmod  hello06.ko
	modinfo hello06.ko
	lsmod   | grep hello06
	@echo "===== ===== ===== ===== ====="
	cat /proc/buffer1k
	@echo "===== ===== ===== ===== ====="
	echo -n    "Hello!" > /proc/buffer1k
	echo -n "Good Bye!" > /proc/buffer1k
	@echo "===== ===== ===== ===== ====="
H06del:rootmode
	rmmod   hello06

.PHONY: clean help rootmode usermode

clean: usermode
	+make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

help: usermode
	@echo "all"
	@echo "clean"
	@echo "HXins"
	@echo "HXdel"
	@echo "help"


rootmode:
ifneq ($(shell id -u), 0)
	@echo "ROOT only!"
	@exit 1
endif

usermode:
ifeq ($(shell id -u), 0)
	@echo "No ROOT, please!"
	@exit 1
endif

