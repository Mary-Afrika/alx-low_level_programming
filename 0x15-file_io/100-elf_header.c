#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
* check_elf - Checks if a file is an ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: The check_elf() function is designed to
* determine whether a given file is an ELF (Executable and
* Linkable Format) file. It takes as input a pointer e_ident
* to an array containing the ELF magic numbers.
* The ELF magic numbers are specific byte values that identify the file format.
* If the file is not an ELF file - exit code 98.
*/
void check_elf(unsigned char *e_ident)
{
int index;

for (index = 0; index < 4; index++)
{
/* Check if the current element is not equal to 127 OR 'E' OR 'L' OR 'F'*/
if (!(e_ident[index] == 127 ||
e_ident[index] == 'E' ||
e_ident[index] == 'L' ||
e_ident[index] == 'F'))
{
/* Print an error message indicating that the file is not an ELF file */
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");

/* Exit the program with exit code 98*/
exit(98);

}
}
}

/**
* print_magic - Prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: The magic numbers are separated by spaces.
*/
void print_magic(unsigned char *e_ident)
{
int index;

/* Print the label for the magic numbers*/
printf("  Magic:   ");

/* Iterate over each magic number in the array*/
for (index = 0; index < EI_NIDENT; index++)
{
/* Print the current magic number */
printf("%02x", e_ident[index]);

/* Check if the current magic number is not the last one */
if (index != EI_NIDENT - 1)
printf(" ");
/* Print a space to separate the magic numbers */
else
printf("\n"); /* Print a newline character to start a new line */
}
}

/**
* print_class - Prints the class of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*
* Description: This function prints the class of an ELF header,
* which represents the architecture-specific data size of the object file.
* The class value is obtained from the e_ident array at index EI_CLASS.
* Possible values and their corresponding output are:
* - ELFCLASSNONE: "none"
* - ELFCLASS32: "ELF32"
* - ELFCLASS64: "ELF64"
* If the class value is none of the above, it prints "<unknown: %x>",
* where %x represents the hexadecimal value of the class.
*/
void print_class(unsigned char *e_ident)
{
printf("  Class:                             ");

if (e_ident[EI_CLASS] == ELFCLASSNONE)
printf("none\n");
else if (e_ident[EI_CLASS] == ELFCLASS32)
printf("ELF32\n");
else if (e_ident[EI_CLASS] == ELFCLASS64)
printf("ELF64\n");
else
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

/**
* print_data - Prints the data of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*
* Description: This function prints the data format of an ELF header,
* which specifies the byte order and the encoding of data in the object file.
* The data value is obtained from the e_ident array at index EI_DATA.
* Possible values and their corresponding output are:
* - ELFDATANONE: "none"
* - ELFDATA2LSB: "2's complement, little endian"
* - ELFDATA2MSB: "2's complement, big endian"
* If the data value is none of the above, it prints "<unknown: %x>",
* where %x represents the hexadecimal value of the data.
*/
void print_data(unsigned char *e_ident)
{
printf("  Data:                              ");

if (e_ident[EI_DATA] == ELFDATANONE)
printf("none\n");
else if (e_ident[EI_DATA] == ELFDATA2LSB)
printf("2's complement, little endian\n");
else if (e_ident[EI_DATA] == ELFDATA2MSB)
printf("2's complement, big endian\n");
else
printf("<unknown: %x>\n", e_ident[EI_DATA]);
}

/**
* print_version - Prints the version of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*
* Description: This function prints the version of an ELF header,
* which represents the version number of the ELF specification used.
* The version value is obtained from the e_ident array at index EI_VERSION.
* It is printed as-is, followed by "(current)" if it matches the constant EV_CURRENT.
* Otherwise, only the version number is printed.
*/
void print_version(unsigned char *e_ident)
{
printf("  Version:                           %d", e_ident[EI_VERSION]);

/* Check if the version matches the current version */
if (e_ident[EI_VERSION] == EV_CURRENT)
printf(" (current)\n");
else
printf("\n");
}

/**
* print_osabi - Prints the OS/ABI of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*
* Description: This function prints the OS/ABI (Operating System/Application Binary Interface)
* of an ELF header. The value is obtained from the e_ident array at index EI_OSABI.
* The function uses a series of conditional statements to match the OS/ABI value
* against known constants and prints the corresponding OS/ABI description.
* If the value does not match any known OS/ABI, an unknown OS/ABI message is printed.
*/
void print_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");

/* Check the OS/ABI value and print the corresponding description */
if (e_ident[EI_OSABI] == ELFOSABI_NONE)
printf("UNIX - System V\n");
else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
printf("UNIX - HP-UX\n");
else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
printf("UNIX - NetBSD\n");
else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
printf("UNIX - Linux\n");
else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
printf("UNIX - Solaris\n");
else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
printf("UNIX - IRIX\n");
else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
printf("UNIX - FreeBSD\n");
else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
printf("UNIX - TRU64\n");
else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
printf("ARM\n");
else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
printf("Standalone App\n");
else
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}

/**
* print_abi - Prints the ABI version of an ELF header.
* @e_ident: A pointer to an array containing the ELF ABI version.
*
* Description: This function prints the ABI (Application Binary Interface)
* version of an ELF header. The ABI version is obtained from the e_ident array
* at index EI_ABIVERSION. The function directly accesses the value and prints it
* using printf. No additional conditional statements or logic are needed since
* the ABI version is a single value.
*/
void print_abi(unsigned char *e_ident)
{
printf("  ABI Version:                       %d\n",
e_ident[EI_ABIVERSION]);
}

/**
* print_type - Prints the type of an ELF header.
* @e_type: The ELF type.
* @e_ident: A pointer to an array containing the ELF class.
*
* Description: This function prints the type of an ELF header. The type is
* obtained from the e_type parameter. If the endianness in e_ident is big
* endian, the e_type value is shifted right by 8 bits. The function then
* checks the shifted e_type value against known constants and prints the
* corresponding type description. If the value does not match any known type,
* an unknown type message is printed.
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
printf("  Type:                              ");

/* Check if the endianness is big endian and adjust the e_type value */
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

/* Check the ELF type value and print the corresponding description */
if (e_type == ET_NONE)
printf("NONE (None)\n");
else if (e_type == ET_REL)
printf("REL (Relocatable file)\n");
else if (e_type == ET_EXEC)
printf("EXEC (Executable file)\n");
else if (e_type == ET_DYN)
printf("DYN (Shared object file)\n");
else if (e_type == ET_CORE)
printf("CORE (Core file)\n");
else
printf("<unknown: %x>\n", e_type);
}

/**
* print_entry - Prints the entry point of an ELF header.
* @e_entry: The address of the ELF entry point.
* @e_ident: A pointer to an array containing the ELF class.
*
* Description: This function prints the entry point address of an ELF header.
* If the endianness in e_ident is big endian, the e_entry value is byte-swapped.
* The function checks the ELF class in e_ident to determine whether to print
* the entry point as a 32-bit value or a 64-bit value.
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
{
printf("  Entry point address:               ");

/* Check if the endianness is big endian and byte-swap the entry point value */
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}

/* Use a conditional statement to print the entry point based on the ELF class */
printf("%#lX\n", (e_ident[EI_CLASS] == ELFCLASS32) ? (unsigned int)e_entry : e_entry);
}

/**
* close_elf - Closes an ELF file.
* @elf: The file descriptor of the ELF file.
*
* Description: This function closes the ELF file associated with the given file descriptor.
* If the file cannot be closed, it prints an error message and exits with code 98.
*/
void close_elf(int elf)
{
/* Use a conditional statement to check if the file can be closed */
if (close(elf) != 0)
{
/* Print an error message indicating the failure to close the file */
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", elf);

/* Exit the program with code 98 to indicate the failure */
exit(98);
}
}

/**
* main - Displays the information contained in the
*        ELF header at the start of an ELF file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: This function opens an ELF file, reads its ELF header,
* and displays the information contained in the header. If the file
* is not an ELF file or if the function fails, it exits with code 98.
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int o, r;

o = open(argv[1], O_RDONLY);
if (o == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf(o);
dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
exit(98);
}

r = read(o, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
close_elf(o);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

/* Check if the file is not an ELF file by comparing the magic number */
if (header->e_ident[EI_MAG0] != ELFMAG0 || header->e_ident[EI_MAG1] != ELFMAG1 ||
header->e_ident[EI_MAG2] != ELFMAG2 || header->e_ident[EI_MAG3] != ELFMAG3)
{
free(header);
close_elf(o);
dprintf(STDERR_FILENO, "Error: `%s` is not an ELF file\n", argv[1]);
exit(98);
}

/* Display the information contained in the ELF header */
check_elf(header->e_ident);
printf("ELF Header:\n");
print_class(header->e_ident);
print_magic(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);

/* Clean up resources and exit successfully */
free(header);
close_elf(o);
return 0;

}
