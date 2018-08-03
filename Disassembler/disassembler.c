#include <stdio.h>
#include <stdlib.h>

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
    Accumulator : register A
    addr        : 16-bits address
    d8          : 8-bits data
    d16         : 16-bits data
    byte 2      : the second byte of the instruction
    byte 3      : the third byte of the instruction
    port        : 8-bits address of an I/O device
    PC          : 16-bits program counter register (PCH and PCL for the high-order and low-order 8 bits)
    SP          : 16-bits stack pointer register (SPH and SPL for the high-order and low-order 8 bits)

    #           : the actual value
    ()          : the value at the address

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


    ===== Register Pair =====

    rp = One of the register pair :
        - B represents the B, C pair, with B as the high-order register and C as the low-order register
        - D represents the D, E pair, with D as the high-order register and E as the low-order register
        - H represents the H, L pair, with H as the high-order register and L as the low-order register
        - SP represents the 16 bits stack pointer register

    rh = The first / high-order register of a designated register pair
    rl = The second / low-order register of a designated register pair

    +-----------+----------+
    |     RP    | Registers|
    +----------------------+
    |     00    |    B-C   |
    |     01    |    D-E   |
    |     10    |    H-L   |
    |     11    |    SP    |
    +-----------+----------+


    ===== Flags =====

    +---------------+
    |7|6|5|4|3|2|1|0|
    +---------------+
    |S|Z|-|A|-|P|-|C|
    +---------------+

    S - Sign Flag : set if the most significant bit of the result of the operation has the value 1
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
        case 0x40:
            printf("%04x\tMOV B, B\t(B) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x41:
            printf("%04x\tMOV B, C\t(B) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x42:
            printf("%04x\tMOV B, D\t(B) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x43:
            printf("%04x\tMOV B, E\t(B) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x44:
            printf("%04x\tMOV B, H\t(B) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x45:
            printf("%04x\tMOV B, L\t(B) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x47:
            printf("%04x\tMOV B, A\t(B) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x48:
            printf("%04x\tMOV C, B\t(C) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x49:
            printf("%04x\tMOV C, C\t(C) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x4A:
            printf("%04x\tMOV C, D\t(C) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x4B:
            printf("%04x\tMOV B, E\t(C) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x4C:
            printf("%04x\tMOV B, H\t(C) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x4D:
            printf("%04x\tMOV B, L\t(C) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x4F:
            printf("%04x\tMOV B, A\t(C) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x50:
            printf("%04x\tMOV D, B\t(D) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x51:
            printf("%04x\tMOV D, C\t(D) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x52:
            printf("%04x\tMOV D, D\t(D) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x53:
            printf("%04x\tMOV D, E\t(D) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x54:
            printf("%04x\tMOV D, H\t(D) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x55:
            printf("%04x\tMOV D, L\t(D) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x57:
            printf("%04x\tMOV D, A\t(D) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x58:
            printf("%04x\tMOV E, B\t(E) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x59:
            printf("%04x\tMOV E, C\t(E) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x5A:
            printf("%04x\tMOV E, D\t(E) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x5B:
            printf("%04x\tMOV E, E\t(E) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x5C:
            printf("%04x\tMOV E, H\t(E) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x5D:
            printf("%04x\tMOV E, L\t(E) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x5F:
            printf("%04x\tMOV E, A\t(E) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x60:
            printf("%04x\tMOV H, B\t(H) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x61:
            printf("%04x\tMOV H, C\t(H) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x62:
            printf("%04x\tMOV H, D\t(H) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x63:
            printf("%04x\tMOV H, E\t(H) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x64:
            printf("%04x\tMOV H, H\t(H) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x65:
            printf("%04x\tMOV H, L\t(H) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x67:
            printf("%04x\tMOV H, A\t(H) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x68:
            printf("%04x\tMOV L, B\t(L) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x69:
            printf("%04x\tMOV L, C\t(L) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x6A:
            printf("%04x\tMOV L, D\t(L) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x6B:
            printf("%04x\tMOV L, E\t(L) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x6C:
            printf("%04x\tMOV L, H\t(L) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x6D:
            printf("%04x\tMOV L, L\t(L) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x6F:
            printf("%04x\tMOV L, A\t(L) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x78:
            printf("%04x\tMOV A, B\t(A) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x79:
            printf("%04x\tMOV A, C\t(A) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x7A:
            printf("%04x\tMOV A, D\t(A) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x7B:
            printf("%04x\tMOV A, E\t(A) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x7C:
            printf("%04x\tMOV A, H\t(A) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x7D:
            printf("%04x\tMOV A, L\t(A) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x7F:
            printf("%04x\tMOV A, A\t(A) <= (A)", *opcode);
            op_bytes = 1;
            break;
        
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
        case 0x46:
            printf("%04x\tMOV B, M\t(B) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x4E:
            printf("%04x\tMOV C, M\t(C) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x56:
            printf("%04x\tMOV D, M\t(D) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x5E:
            printf("%04x\tMOV E, M\t(E) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x66:
            printf("%04x\tMOV H, M\t(H) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x6E:
            printf("%04x\tMOV L, M\t(L) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x7E:
            printf("%04x\tMOV A, M\t(A) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;

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
        case 0x70:
            printf("%04x\tMOV M, B\t((H)(L)) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x71:
            printf("%04x\tMOV M, C\t((H)(L)) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x72:
            printf("%04x\tMOV M, D\t((H)(L)) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x73:
            printf("%04x\tMOV M, E\t((H)(L)) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x74:
            printf("%04x\tMOV M, H\t((H)(L)) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x75:
            printf("%04x\tMOV M, L\t((H)(L)) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x77:
            printf("%04x\tMOV M, A\t((H)(L)) <= (A)", *opcode);
            op_bytes = 1;
            break;

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
        case 0x06:
            printf("%04x\tMVI B, d8\t(B) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x0E:
            printf("%04x\tMVI C, d8\t(C) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x16:
            printf("%04x\tMVI D, d8\t(D) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x1E:
            printf("%04x\tMVI E, d8\t(E) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x26:
            printf("%04x\tMVI H, d8\t(H) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x2E:
            printf("%04x\tMVI L, d8\t(L) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x3E:
            printf("%04x\tMVI A, d8\t(A) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;

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
        case 0x36:
            printf("%04x\tMVI M, d8\t((H)(L)) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;

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
        case 0x01:
            printf("%04x\tLXI B, d16\t(B) <= #$%02x, (C) <= #$%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0x11:
            printf("%04x\tLXI D, d16\t(D) <= #$%02x, (E) <= #$%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0x21:
            printf("%04x\tLXI H, d16\t(H) <= #$%02x, (L) <= #$%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0x31:
            printf("%04x\tLXI SP, d16\t(SPH) <= #$%02x, (SPL) <= #$%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;

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
        case 0x3A:
            printf("%04x\tLDA a16\t(A) <= ($%02x%02x)", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;

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
        case 0x32:
            printf("%04x\tSTA a16\t($%02x%02x) <= (A)", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;

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
        case 0x2A:
            printf("%04x\tLHLD a16\t(L) <= ($%02x%02x), (H) <= ($%02x%02x + 1)", *opcode, opcode[2], opcode[1], opcode[2], opcode[1]);
            op_bytes = 3;
            break;

        /*
            Name : Store H and L direct
            Explanation : The content of the register L is moved to the memory
                location whose address is specified in byte 2 and byte 3. The content
                of the regsiter H is moved to the succeeding memory location
            Encoding :  +---------------+
                        |0|0|1|0|0|0|1|0|
                        +---------------+
                        | low-order ADDR|
                        +---------------+
                        |high-order ADDR|
                        +---------------+
            Cycles / States : 5 / 16
            Flags : None
        */
        case 0x22:
            printf("%04x\tSHLD a16\t($%02x%02x) <= (L), ($%02x%02x + 1) <= (H)", *opcode, opcode[2], opcode[1], opcode[2], opcode[1]);
            op_bytes = 3;
            break;

        /*
            Name : Load accumulator direct
            Explanation : The content of the memory location, whose address is in
                the register pair rp, is moved to the register A. Note: only register
                pairs rp = B or rp = D may be specified
            Encoding :  +---------------+
                        |0|0|R|P|1|0|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : None
        */
        case 0x0A:
            printf("%04x\tLDAX B\t(A) <= ((B)(C))", *opcode);
            op_bytes = 3;
            break;
        case 0x1A:
            printf("%04x\tLDAX D\t(A) <= ((D)(E))", *opcode);
            op_bytes = 3;
            break;

        /*
            Name : Store accumulator direct
            Explanation : The content of the register A is moved to the memory location
                whose address is in the register pair rp. Note: only register pairs rp = B
                or rp = D may be specified
            Encoding :  +---------------+
                        |0|0|R|P|0|0|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : None
        */
       case 0x02:
            printf("%04x\tSTAX B\t((B)(C)) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x12:
            printf("%04x\tSTAX D\t((D)(E)) <= (A)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Exchange H and L with D and E
            Explanation : The contents of registers H and L are exchanged with the contents
                of registers D and E
            Encoding :  +---------------+
                        |1|1|1|0|1|0|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : None
        */
       case 0xEB:
            printf("%04x\tXCHG\t(H) <=> (D), (L) <=> (E)", *opcode);
            op_bytes = 1;
            break;

        default:
            printf("Instruction non prise en charge : %04x", *opcode);
            break;
    }
    return op_bytes;
}
