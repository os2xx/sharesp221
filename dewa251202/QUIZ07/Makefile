obj-m += hello01.o
obj-m += hello02.o
obj-m += hello03.o
obj-m += hello04.o
hello02-objs := hello02a.o hello02b.o

PWD := $(CURDIR)

all: 
	@if [ "$(shell id -u)" = 0 ]; then\
		echo "No ROOT, please!";\
		exit 1;\
	else\
		make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules;\
	fi

clean: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

H01ins:
	@if ! [ "$(shell id -u)" = 0 ]; then\
		echo "ROOT only!";\
		exit 1;\
	else\
		insmod hello01.ko;\
		modinfo hello01.ko;\
		lsmod | grep hello01;\
	fi

H01del:
	@if ! [ "$(shell id -u)" = 0 ]; then\
		echo "ROOT only!";\
		exit 1;\
	else\
		rmmod hello01.ko;\
	fi

H02ins:
	@if ! [ "$(shell id -u)" = 0 ]; then\
		echo "ROOT only!";\
		exit 1;\
	else\
		insmod hello02.ko;\
		modinfo hello02.ko;\
		lsmod | grep hello02;\
	fi

H02del:
	@if ! [ "$(shell id -u)" = 0 ]; then\
		echo "ROOT only!";\
		exit 1;\
	else\
		rmmod hello02.ko;\
	fi

H03ins:
	@if ! [ "$(shell id -u)" = 0 ]; then\
		echo "ROOT only!";\
		exit 1;\
	else\
		insmod hello03.ko;\
		modinfo hello03.ko;\
		lsmod | grep hello03;\
	fi

H03del:
	@if ! [ "$(shell id -u)" = 0 ]; then\
		echo "ROOT only!";\
		exit 1;\
	else\
		rmmod hello03.ko;\
	fi

H04ins:
	@if ! [ "$(shell id -u)" = 0 ]; then\
		echo "ROOT only!";\
		exit 1;\
	else\
		insmod hello04.ko;\
		modinfo hello04.ko;\
		lsmod | grep hello04;\
	fi

H04del:
	@if ! [ "$(shell id -u)" = 0 ]; then\
		echo "ROOT only!";\
		exit 1;\
	else\
		rmmod hello04.ko;\
	fi
