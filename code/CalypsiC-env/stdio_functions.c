#include <errno.h>
#include <stddef.h>
#include <stubs.h>
#include "MemAccess.h"
#include "SBC.h"



size_t _Stub_write(int fd, const void *buf, size_t count){
	const char *p = buf;
	size_t n = 0;
	
	switch (fd){
		case 1:
			while (count){
				while ((mread8(_CTRL) & _BIT_TXE)){};
				mwrite8(_SERIAL, *p);
				p++;
				n++;
				count--;
			}
		break;
		default:
			__set_errno(EBADF);
			return (size_t) -1;
		break;
	}
	return n;
}

size_t _Stub_read(int fd, void *buf, size_t count){
	char *p = buf;
	size_t n = 0;
	
	switch (fd){
		case 1:
			while (count){
				while ((mread8(_CTRL) & _BIT_RXF)){};
				*p = mread8(_SERIAL);
				p++;
				n++;
				count--;
			}
		break;
		default:
			__set_errno(EBADF);
			return (size_t) -1;
		break;
	}
	return n;
}

long _Stub_lseek(int fd, long offset, int whence) {
  return -1;
}

int _Stub_open(const char *path, int oflag, ...) {
  return 0;
}

int _Stub_close(int fd) {
  return 0;
}
