#include "main.h"
#include "elf_helpers.h"

/**
 * check_elf - Check if the given buffer is an ELF file
 * @ptr: A pointer to the buffer containing the ELF file header
 *
 * Return: If the buffer contains an ELF file, return 1, otherwise return 0.
 */
int check_elf(char *ptr)
{
	return (ptr[0] == 0x7F && ptr[1] == 'E' && ptr[2] == 'L' && ptr[3] == 'F');
}

/**
 * print_magic - Prints the magic number of an ELF file header
 * @ptr: Pointer to the ELF file header
 *
 * This function prints the magic number of an ELF file header
 * in the same format as the readelf command.
 */
void print_magic(char *ptr)
{
	int bytes;

	printf("  Magic:  ");
	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", ptr[bytes]);
	printf("\n");
}

/**
 * print_data - Prints the data format of the ELF file
 * @data: Data format value from the ELF header
 */
void print_data(char data)
{
	if (data == 1)
		printf(", little endian\n");
	else if (data == 2)
		printf(", big endian\n");
}

/**
 * print_version - Prints the ELF version
 * @version: Version value from the ELF header
 */
void print_version(int version)
{
	printf("  Version: %d", version);
	if (version == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

/**
 * print_osabi - Prints the OS/ABI of the ELF file
 * @osabi: OS/ABI value from the ELF header
 */
void print_osabi(char osabi)
{
	printf("  OS/ABI: ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);
}

/**
 * print_type - Prints the type of the ELF file
 * @type: Type value from the ELF header
 */
void print_type(char type)
{
	switch (type)
	{
	case 0:
		printf("NONE (No file type)\n");
		break;
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	case 4:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
		break;
	}
}

/**
 * print_entry_point - Prints the entry point address of the ELF file
 * @sys: System class value from the ELF header
 * @ptr: Pointer to the ELF header
 */
void print_entry_point(char sys, char *ptr)
{
	int i;

	printf("  Entry point address: 0x");
	if (sys == '1')
	{
		printf("80");
		for (i = 26; i >= 22; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", 256 + ptr[i]);
			if (ptr[7] == 6)
				printf("00");
		}
	}
	else if (sys == '2')
	{
		for (i = 26; i > 23; i--)
		{
			if (ptr[i] >= 0)
				printf("%02x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%02x", 256 + ptr[i]);
		}
	}
	printf("\n");
}

/**
 * print_sys - Prints the ELF system of the file
 * @ptr: Pointer to the ELF array
 */
void print_sys(char *ptr)
{
	char sys = ptr[4] + '0';
	char data = ptr[5];
	int version = ptr[6];
	char osabi = ptr[7];
	char type;

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(ptr);

	if (sys == '1')
		printf("Class: ELF32\n");

	if (sys == '2')
		printf("Class: ELF64\n");

	printf("Data: 2's complement");
	print_data(data);

	print_version(version);

	print_osabi(osabi);

	printf("ABI Version: %d\n", ptr[8]);

	type = (data == 1) ? ptr[16] : ptr[17];

	printf("  Type: ");
	print_type(type);

	print_entry_point(sys, ptr);
}

/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments passed
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd, ret_read;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: file cannot be opened\n");
		exit(98);
	}

	lseek(fd, 0, SEEK_SET);
	ret_read = read(fd, ptr, 27);
	if (ret_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file cannot be read\n");
		exit(98);
	}

	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF file\n");
		exit(98);
	}

	print_sys(ptr);
	close(fd);

	return (0);
}

