#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(const char* message);
void print_elf_header(const Elf64_Ehdr* header);
int main(int argc, char* argv[]);

void print_error(const char* message)
{
fprintf(stderr, "Error: %s\n", message);
exit(98);
}

void print_elf_header(const Elf64_Ehdr* header)
{
printf("Magic: ");
for (int i = 0; i < EI_NIDENT; i++) {
printf("%02x ", header->e_ident[i]);
}
printf("\n");

printf("Class: %s\n", (header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
printf("Data: %s\n", (header->e_ident[EI_DATA] == ELFDATA2MSB) ? "big-endian" : "little-endian");
printf("Version: %d\n", header->e_ident[EI_VERSION]);
printf("OS/ABI: %s\n", (header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Other");
printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

printf("Type: ");
switch (header->e_type) {
case ET_NONE:
printf("NONE (No file type)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("Unknown\n");
break;
}

printf("Entry point address: 0x%lx\n", header->e_entry);
}

int main(int argc, char* argv[])
{
if (argc != 2) {
print_error("Usage: elf_header elf_filename");
}

const char* filename = argv[1];
int fd = open(filename, O_RDONLY);
if (fd == -1) {
print_error("Failed to open the file");
}

Elf64_Ehdr header;
if (read(fd, &header, sizeof(header)) != sizeof(header)) {
print_error("Failed to read ELF header");
}

if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3) {
print_error("Not an ELF file");
}

void print_error(const char* message);
void print_elf_header(const Elf64_Ehdr* header);
int main(int argc, char* argv[]);
print_elf_header(&header);

close(fd);
return 0;

}
