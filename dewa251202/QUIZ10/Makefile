# REV??+3: 19/05/2022 12:39:00
# REV??+2: 19/05/2022 12:34:00
# REV??+1: 17/05/2022 14:57:00
# REV??+0: 17/05/2022 13:33:00

obj-m += hello01.o
obj-m += hello02.o
obj-m += hello03.o
obj-m += hello04.o
obj-m += hello05.o
obj-m += hello06.o
obj-m += hello07.o
obj-m += hello08.o
obj-m += simplefs.o
hello02-objs := hello02a.o hello02b.o
simplefs-objs := hello09.o super.o inode.o file.o dir.o extent.o

PWD := $(CURDIR)

MKFS = mkfs.simplefs

all: usermode
	+make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean: 
	+make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

$(MKFS): mkfs.c
	$(CC) -std=gnu99 -Wall -o $@ $<

H01ins: rootmode
	insmod  hello01.ko
	modinfo hello01.ko
	lsmod   | grep hello01

H01del: rootmode
	rmmod  hello01.ko

H02ins: rootmode
	insmod  hello02.ko
	modinfo hello02.ko
	lsmod   | grep hello02

H02del: rootmode
	rmmod  hello02.ko

H03ins: rootmode
	insmod  hello03.ko
	lsmod   | grep hello03
	rmmod   hello03.ko
	insmod  hello03.ko myshort=69 myint=888 mylong=1234567890  mystring="newString" myintArray=1,2,3,4,5
	lsmod   | grep hello03
	rmmod   hello03.ko
	insmod  hello03.ko myshort=99 myint=999 mylong=1122334455  mystring="lastString" myintArray=11,22,33,44,55
	modinfo hello03.ko
	lsmod   | grep hello03

H03del: rootmode
	rmmod  hello03.ko

H04ins: rootmode
	insmod  hello04.ko
	modinfo hello04.ko
	lsmod   | grep hello04
	@echo "===== ===== ===== =====  ===== ===== ===== ===== ====="
	ls -al /proc/helloworld
	cat    /proc/helloworld
	@echo "===== ===== ===== =====  ===== ===== ===== ===== ====="

H04del: rootmode
	rmmod  hello04.ko

H05ins: rootmode
	insmod  hello05.ko
	modinfo hello05.ko
	lsmod   | grep hello05

H05del: rootmode
	rmmod  hello05.ko

H06ins: rootmode
	insmod  hello06.ko
	modinfo hello06.ko
	lsmod   | grep hello06
	@echo "===== ===== ===== ===== ====="
	cat /proc/buffer1k
	@echo "===== ===== ===== ===== ====="
	echo -n    "Hello!" > /proc/buffer1k
	echo -n "Good Bye!" > /proc/buffer1k
	@echo "===== ===== ===== ===== ====="

H06del: rootmode
	rmmod  hello06.ko

H07ins: rootmode
	insmod  hello07.ko
	modinfo hello07.ko
	lsmod   | grep hello07
	@echo "===== ===== ===== ===== ====="
	cat /proc/ITER
	cat /proc/ITER
	cat /proc/ITER
	@echo "===== ===== ===== ===== ====="
	rmmod   hello07
	insmod  hello07.ko counter=10
	lsmod   | grep hello07
	@echo "===== ===== ===== ===== ====="
	cat /proc/ITER
	cat /proc/ITER
	cat /proc/ITER
	@echo "===== ===== ===== ===== ====="

H07del: rootmode
	rmmod  hello07.ko

H08ins: rootmode
	insmod  hello08.ko
	modinfo hello08.ko
	lsmod   | grep hello08
	@echo "===== ===== ===== ===== ====="
	cat         /sys/kernel/H08module/hello08var
	echo "99" > /sys/kernel/H08module/hello08var
	cat         /sys/kernel/H08module/hello08var
	@echo "===== ===== ===== ===== ====="

H08del: rootmode
	rmmod  hello08.ko

H09ins: rootmode
	insmod  simplefs.ko
	modinfo simplefs.ko
	lsmod   | grep simplefs
	bash ./h09-test.sh

H09del: rootmode
	rmmod  simplefs.ko

# === MODE CHECKER === #
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
