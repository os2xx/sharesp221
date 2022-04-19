obj-m += hello01.o
obj-m += hello02.o

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
