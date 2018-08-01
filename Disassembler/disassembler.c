#include <stdio.h>
#include <stdlib.h>

void print_instruction(int opcode, char *mnemonic, char *operation);

/*
    1. Read the code into a buffer
    2. Get a pointer to the beginning of the buffer
    3. Use the byte at the pointer to determine the opcode
    4. Print informations about the opcode
    5. Advance the pointer the number of bytes used by the instruction
    6. Go to step 3
*/


/*
    Symbols

    ===== DDD / SSS =====

    The bit pattern (DDD = Destination / SSS = Source) designating one of the registers :

    +-----------+----------+
    | DDD / SSS | Register |
    +----------------------+
    |    111    |     A    |
    |    000    |     B    |
    |    001    |     C    |
    |    010    |     D    |
    |    011    |     E    |
    |    100    |     H    |
    |    101    |     L    |
    +-----------+----------+


    ===== Flags =====

    +---------------+
    |7|6|5|4|3|2|1|0|
    +---------------+
    |S|Z|-|A|-|P|-|C|
    +---------------+

    S - Sign Flag : set if the result of an instruction is negative
    Z - Zero Flag : set if the result of an instruction has the value 0
    Not used - Always zero
    AC/H - Auxiliary carry : carry flag for binary coded decimal arithmetic
    Not used - Always zero
    P - Parity Flag : set if the result is even
    Not used - Always one
    C - Carry : set if the last addition resulted in a carry or if the last subtraction resulted in a borrow

    TODO: modify flags
        Single byte instruction / Two byte instructions
        Symbols
*/


int disassemble8080(unsigned char *code_buffer, int pc)
{
    unsigned char *opcode = &code_buffer[pc];
    // the number of bytes to advance the pc
    int op_bytes = 0;

    /*
        Description of the instruction :
            - Name
            - Explanation of the instruction
            - Encoding
            - Cycles - States
            - Flags affected

        Print :
            Opcode - Instruction mnemonic (operation resume)
    */
    switch (*opcode)
    {
        /*
            Name : Move Register
            Explanation : The content of register r2 is moved to register r1
            Encoding :  +---------------+
                        |0|1|D|D|D|S|S|S|
                        +---------------+
            Cycles / States : 1 / 5
            Flags : None
        */
        #pragma region
        case 0x40:
            printf("%x04\tMOV B, B\t(B) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x41:
            printf("%x04\tMOV B, C\t(B) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x42:
            printf("%x04\tMOV B, D\t(B) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x43:
            printf("%x04\tMOV B, E\t(B) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x44:
            printf("%x04\tMOV B, H\t(B) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x45:
            printf("%x04\tMOV B, L\t(B) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x47:
            printf("%x04\tMOV B, A\t(B) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x48:
            printf("%x04\tMOV C, B\t(C) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x49:
            printf("%x04\tMOV C, C\t(C) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x4A:
            printf("%x04\tMOV C, D\t(C) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x4B:
            printf("%x04\tMOV B, E\t(C) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x4C:
            printf("%x04\tMOV B, H\t(C) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x4D:
            printf("%x04\tMOV B, L\t(C) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x4F:
            printf("%x04\tMOV B, A\t(C) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x50:
            printf("%x04\tMOV D, B\t(D) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x51:
            printf("%x04\tMOV D, C\t(D) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x52:
            printf("%x04\tMOV D, D\t(D) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x53:
            printf("%x04\tMOV D, E\t(D) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x54:
            printf("%x04\tMOV D, H\t(D) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x55:
            printf("%x04\tMOV D, L\t(D) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x57:
            printf("%x04\tMOV D, A\t(D) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x58:
            printf("%x04\tMOV E, B\t(E) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x59:
            printf("%x04\tMOV E, C\t(E) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x5A:
            printf("%x04\tMOV E, D\t(E) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x5B:
            printf("%x04\tMOV E, E\t(E) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x5C:
            printf("%x04\tMOV E, H\t(E) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x5D:
            printf("%x04\tMOV E, L\t(E) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x5F:
            printf("%x04\tMOV E, A\t(E) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x60:
            printf("%x04\tMOV H, B\t(H) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x61:
            printf("%x04\tMOV H, C\t(H) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x62:
            printf("%x04\tMOV H, D\t(H) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x63:
            printf("%x04\tMOV H, E\t(H) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x64:
            printf("%x04\tMOV H, H\t(H) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x65:
            printf("%x04\tMOV H, L\t(H) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x67:
            printf("%x04\tMOV H, A\t(H) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x68:
            printf("%x04\tMOV L, B\t(L) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x69:
            printf("%x04\tMOV L, C\t(L) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x6A:
            printf("%x04\tMOV L, D\t(L) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x6B:
            printf("%x04\tMOV L, E\t(L) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x6C:
            printf("%x04\tMOV L, H\t(L) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x6D:
            printf("%x04\tMOV L, L\t(L) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x6F:
            printf("%x04\tMOV L, A\t(L) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x78:
            printf("%x04\tMOV A, B\t(A) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x79:
            printf("%x04\tMOV A, C\t(A) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x7A:
            printf("%x04\tMOV A, D\t(A) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x7B:
            printf("%x04\tMOV A, E\t(A) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x7C:
            printf("%x04\tMOV A, H\t(A) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x7D:
            printf("%x04\tMOV A, L\t(A) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x7F:
            printf("%x04\tMOV A, A\t(A) <= (A)", *opcode);
            op_bytes = 1;
            break;
        #pragma endregion
        
        /*
            Name : Move from memory
            Explanation : The content of the memory location,
                whose address is in register H and L, is moved to register r
            Encoding :  +---------------+
                        |0|1|D|D|D|1|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : None
        */
        #pragma region
        case 0x46:
            printf("%x04\tMOV B, M\t(B) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x4E:
            printf("%x04\tMOV C, M\t(C) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x56:
            printf("%x04\tMOV D, M\t(D) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x5E:
            printf("%x04\tMOV E, M\t(E) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x66:
            printf("%x04\tMOV H, M\t(H) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x6E:
            printf("%x04\tMOV L, M\t(L) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x7E:
            printf("%x04\tMOV A, M\t(A) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        #pragma endregion

        case 0TO_CHANGE:
            /*
                Name : Move to memory
                Explanation : The content of the register r is moved to the
                    memory location whose address is in registers H and L
                Encoding :  +---------------+
                            |0|1|1|1|0|S|S|S|
                            +---------------+
                Cycles / States : 2 / 7
                Flags : None
            */
            print_instruction(*opcode, "MOV M, r", "((H) (L)) <= r");
            break;

        case 0TO_CHANGE:
             /*
                Name : Move immediate
                Explanation : The content of byte 2 of the instruction is moved
                    to register r
                Encoding :  +---------------+
                            |0|0|D|D|D|1|1|0|
                            +---------------+
                            |      DATA     |
                            +---------------+

                Cycles / States : 2 / 7
                Flags : None
            */
            print_instruction(*opcode, "MVI r, data", "(r) <= (byte 2)");
            break;


        case 0TO_CHANGE:
            /*
                Name : Move to memory immediate
                Explanation : The content of byte 2 of the instruction is moved
                    to the memory location whose address is in register H and L
                Encoding :  +---------------+
                            |0|0|1|1|0|1|1|0|
                            +---------------+
                            |      DATA     |
                            +---------------+
                Cycles / States : 3 / 7
                Flags : None
            */
            print_instruction(*opcode, "MVI M, data", "((H) (L)) <= (byte 2)");
            break;

        case 0TO_CHANGE:
            /*
                Name : Load register pair immediate
                Explanation : Byte  3 of the instruction is moved into the high-order
                    register (rh) of the register pair rp. Byte 2 of the instruction is
                    moved into the low-order register (rl) of the register pair rp
                Encoding :  +---------------+
                            |0|0|R|P|0|0|0|1|
                            +---------------+
                            | low-order DATA|
                            +---------------+
                            |high-order DATA|
                            +---------------+

                Cycles / States : 3 / 10
                Flags : None
            */
            print_instruction(*opcode, "LXi rp, data 16", "(rh) <= (byte 3), (rl) <= (byte 2)");
            break;

        case 0TO_CHANGE:
            /*
                Name : Load Accumulator direct
                Explanation : the content of the memory location ,whose address is
                    specified in byte 2 and byte 3 of the instruction, is moved to register A
                Encoding :  +---------------+
                            |0|0|1|1|1|0|1|0|
                            +---------------+
                            | low-order ADDR|
                            +---------------+
                            |high-order ADDR|
                            +---------------+
                Cycles / States : 4 / 13
                Flags : None
            */
            print_instruction(*opcode, "LDA addr", "(A) <= ((byte 3) (byte 2))");
            break;

        case 0TO_CHANGE:
            /*
                Name : Store Accumulator direct
                Explanation : The content of the accumulator is moved to the memory
                    location whose address is specified in byte 2 and byte 3 of the instruction
                Encoding :  +---------------+
                            |0|0|1|1|0|0|1|0|
                            +---------------+
                            | low-order ADDR|
                            +---------------+
                            |high-order ADDR|
                            +---------------+
                Cycles / States : 4 / 13
                Flags : None
            */
            print_instruction(*opcode, "STA addr", "((byte 3 (byte 2)) <= A");
            break;

        case 0TO_CHANGE:
            /*
                Name : Load H and L direct
                Explanation : The content of the memory location, whose address is
                    specified in byte 2 and byte 3 of the instruction, is moved to
                    register L. The content of the memory location at the succeeding
                    address is moved to register H
                Encoding :  +---------------+
                            |0|0|1|0|1|0|1|0|
                            +---------------+
                            | low-order ADDR|
                            +---------------+
                            |high-order ADDR|
                            +---------------+
                Cycles / States : 5 / 16
                Flags : None
            */
            print_instruction(*opcode, "LHLD addr", "(L) <= ((byte 3) (byte 2)), (H) <= ((byte 3) (byte 2) + 1)");
            break;

        case 0TO_CHANGE:
            /*
                Name : Store H and L direct
                Explanation :
                Encoding :  +---------------+
                            |||||||||
                            +---------------+
                Cycles / States :  /
                Flags :
            */
            print_instruction(*opcode, "", "");
            break;

        case 0TO_CHANGE:
            /*
                Name :
                Explanation :
                Encoding :  +---------------+
                            |||||||||
                            +---------------+
                Cycles / States :  /
                Flags :
            */
            print_instruction(*opcode, "", "");
            break;

        default:
            printf("Instruction non prise en charge : %04x", *opcode);
            break;
    }
    return op_bytes;
}
