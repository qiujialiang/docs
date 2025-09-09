ifneq ($(KERNELRELEASE),)
	obj-m:=readpfcount.o
else
	KDIR:= /usr/src/linux-5.6.15/
	PWD:= $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
endif
