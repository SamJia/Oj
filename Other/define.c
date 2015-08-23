#include <stdio.h>
#define super(type,a,args...) type a[] = {args}
#define debug(format, ...) printf (format, ## __VA_ARGS__)

int main(){
	super(int, a);
	printf("%d, %d, %d\n", a[0], a[1], a[2]);
	debug("message\n");
}