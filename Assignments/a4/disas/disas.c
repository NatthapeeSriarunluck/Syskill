#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *registers[] = {"%rax", "%rcx", "%rdx", "%rbx", "%rsp", "%rbp", "%rsi", "%rdi"};
int scaleFactors[] = {1, 2, 4, 8};

void print_hex_bytes(const unsigned char *raw_instr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%02x ", raw_instr[i]);
    }
    printf("\t");
}
/*
Starts with a switch case to separate the types of registers out
*/
void disassemble(const unsigned char *raw_instr)
{
    unsigned char opCode = raw_instr[0];
    switch (opCode)
    {
    case 0x68:                                       // Immediate Constant
        uint32_t *ptr = (uint32_t *)(raw_instr + 1); // address in 32 bits
        print_hex_bytes(raw_instr, 5);
        printf("pushq $%#x\n", *ptr);
        break;
    case 0x53: // Register
        print_hex_bytes(raw_instr, 1);  
        int registryIndex = raw_instr[0] & 0x7;
        printf("pushq %s\n", registers[registryIndex]);
        break;

    case 0xff:                             // Indirect
        if ((raw_instr[1] & 0x70) == 0x30) // Indirect without displacement
        {
            print_hex_bytes(raw_instr, 2);
            int registryIndex = raw_instr[1] & 0x7;
            printf("pushq (%s)\n", registers[registryIndex]);
            break;
        }
        else if (raw_instr[1] == 0x74) // Indirect with displacement and scaled index
        {
            print_hex_bytes(raw_instr, 4);
            int registryIndex = (raw_instr[2] & 0x38) >> 3; // left group, neecds shifting to get the actual index
            int baseAdressIndex = raw_instr[2] & 0x7;       // right group, neecds shifting to get the actual index
            int scaleIndex = (raw_instr[2] & 0xC0) >> 6;
            printf("pushq %#x(%s,%s,%d)\n", raw_instr[3], registers[baseAdressIndex], registers[registryIndex], scaleFactors[scaleIndex]);
            break;
        }
        else if ((raw_instr[1] & 0x70) == 0x70) // Indirect with displacement
        {
            print_hex_bytes(raw_instr, 3);
            int registryIndex = raw_instr[1] & 0x7;
            printf("pushq %#x(%s)\n", raw_instr[2], registers[registryIndex]);
            break;
        }
        else
        {
            printf("Invalid Raw Instructions in switch case\n");
            break;
        }
    default:
        printf("Invalid Raw Instructions \n");
    }
}

int main()
{
    // pushq $0x3f10
    //unsigned char inst1[5] = {0x68, 0x10, 0x3f, 0x00, 0x00};
    // pushq %rbx
    //unsigned char inst2[1] = {0x53};
    // pushq(%rdx)
    //unsigned char inst3[2] = {0xff, 0x32};
    // pushq 0x8(%rax)
    //unsigned char inst4[3] = {0xff, 0x70, 0x08};
    // pushq 0xff(%rbp,%rcx,4)
    unsigned char inst5[4] = {0xff, 0x74, 0x8d, 0xff};
    //disassemble(inst1);
    //disassemble(inst2);
    //disassemble(inst3);
    //disassemble(inst4);
    disassemble(inst5);
    return 0;
}
