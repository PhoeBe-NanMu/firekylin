#/*  This file is part of The Firekylin Operating System.
# *
# *  Copyright 2016 Liuxiaofeng
# *
# *  Licensed under the Apache License, Version 2.0 (the "License");
# *  you may not use this file except in compliance with the License.
# *  You may obtain a copy of the License at
# *
# *      http://www.apache.org/licenses/LICENSE-2.0
# *
# *  Unless required by applicable law or agreed to in writing, software
# *  distributed under the License is distributed on an "AS IS" BASIS,
# *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# *  See the License for the specific language governing permissions and
# *  limitations under the License.
# */

AS=nasm
CC=gcc

SFLAGS=-f elf32
CFLAGS=-c -x c -Wall -m32 -std=c99 -nostdinc -nostdlib -fno-builtin \
       -fno-stack-protector -I ../../include

include ctype/sub.mk
include stdio/sub.mk
include stdlib/sub.mk
include string/sub.mk
include time/sub.mk
include unistd/sub.mk
include misc/sub.mk

.s.o:
	@echo         AS	$<
	@$(AS) $(SFLAGS) -o $@  $<
.c.o:
	@echo         CC	$<
	@$(CC) $(CFLAGS) -o $@  $<

libc.a: $(LIBC_OBJ)
	@echo         AR       libc
	@ar rcs   libc.a       $(LIBC_OBJ) 

install:libc.a
	@echo installing libc ...
	@-cp  libc.a  $(PREFIX)/libc.a

clean: 
	@echo cleaning libc ...
	@-rm -f libc.a $(LIBC_OBJ)
