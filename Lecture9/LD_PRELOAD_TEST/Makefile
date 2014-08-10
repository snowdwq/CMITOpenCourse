## http://askubuntu.com/questions/470796/fatal-error-sys-cdefs-h-no-such-file-or-directory
## http://superuser.com/questions/224533/how-to-tell-if-linux-process-is-64bit
## https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html#index-Wl-1143
## need to install libc6-dev-i386
## -m32 for 32 bit architectures
## -Wl passes options to linker

libsystem.so: libsystem.c
	gcc -shared -Wl,-soname,libsystem.so.1 -Wl,-m,elf_i386 -m32 -fPIC -o libsystem.so.1.0  libsystem.c
	ln -s libsystem.so.1.0 libsystem.so.1
	ln -s libsystem.so.1 libsystem.so

shell: libsystem.so
	export LD_PRELOAD=libsystem.so; export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH
