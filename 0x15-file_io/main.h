#ifndef MAIN_H
#define MAIN_H
#include "elf_helpers.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int check_elf(char *pointer)
void print_magic(char *pointer)
void print_sys(char *pointer)
int main(int argc, char *argv[])
#endif

