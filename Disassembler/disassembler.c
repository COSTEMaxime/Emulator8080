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
    F           : 8-bits flags register

    #           : the actual value
    ()          : the value at the address

    <=          : is transfered to
    <=>         : is exchanged with
    &&          : logical AND
    ||          : inclusive OR
    ^           : exclusive OR

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
    AC - Auxiliary carry : carry flag for binary coded decimal arithmetic
    Not used - Always zero
    P - Parity Flag : set if the result is even
    Not used - Always one
    CY - Carry : set if the last addition resulted in a carry or if the last subtraction resulted in a borrow

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
            Data Transfer Group
        */
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
            printf("%02x\tMOV B, B\t(B) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x41:
            printf("%02x\tMOV B, C\t(B) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x42:
            printf("%02x\tMOV B, D\t(B) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x43:
            printf("%02x\tMOV B, E\t(B) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x44:
            printf("%02x\tMOV B, H\t(B) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x45:
            printf("%02x\tMOV B, L\t(B) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x47:
            printf("%02x\tMOV B, A\t(B) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x48:
            printf("%02x\tMOV C, B\t(C) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x49:
            printf("%02x\tMOV C, C\t(C) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x4A:
            printf("%02x\tMOV C, D\t(C) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x4B:
            printf("%02x\tMOV B, E\t(C) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x4C:
            printf("%02x\tMOV B, H\t(C) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x4D:
            printf("%02x\tMOV B, L\t(C) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x4F:
            printf("%02x\tMOV B, A\t(C) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x50:
            printf("%02x\tMOV D, B\t(D) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x51:
            printf("%02x\tMOV D, C\t(D) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x52:
            printf("%02x\tMOV D, D\t(D) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x53:
            printf("%02x\tMOV D, E\t(D) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x54:
            printf("%02x\tMOV D, H\t(D) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x55:
            printf("%02x\tMOV D, L\t(D) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x57:
            printf("%02x\tMOV D, A\t(D) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x58:
            printf("%02x\tMOV E, B\t(E) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x59:
            printf("%02x\tMOV E, C\t(E) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x5A:
            printf("%02x\tMOV E, D\t(E) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x5B:
            printf("%02x\tMOV E, E\t(E) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x5C:
            printf("%02x\tMOV E, H\t(E) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x5D:
            printf("%02x\tMOV E, L\t(E) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x5F:
            printf("%02x\tMOV E, A\t(E) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x60:
            printf("%02x\tMOV H, B\t(H) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x61:
            printf("%02x\tMOV H, C\t(H) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x62:
            printf("%02x\tMOV H, D\t(H) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x63:
            printf("%02x\tMOV H, E\t(H) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x64:
            printf("%02x\tMOV H, H\t(H) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x65:
            printf("%02x\tMOV H, L\t(H) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x67:
            printf("%02x\tMOV H, A\t(H) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x68:
            printf("%02x\tMOV L, B\t(L) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x69:
            printf("%02x\tMOV L, C\t(L) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x6A:
            printf("%02x\tMOV L, D\t(L) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x6B:
            printf("%02x\tMOV L, E\t(L) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x6C:
            printf("%02x\tMOV L, H\t(L) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x6D:
            printf("%02x\tMOV L, L\t(L) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x6F:
            printf("%02x\tMOV L, A\t(L) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x78:
            printf("%02x\tMOV A, B\t(A) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x79:
            printf("%02x\tMOV A, C\t(A) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x7A:
            printf("%02x\tMOV A, D\t(A) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x7B:
            printf("%02x\tMOV A, E\t(A) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x7C:
            printf("%02x\tMOV A, H\t(A) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x7D:
            printf("%02x\tMOV A, L\t(A) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x7F:
            printf("%02x\tMOV A, A\t(A) <= (A)", *opcode);
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
            printf("%02x\tMOV B, M\t(B) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x4E:
            printf("%02x\tMOV C, M\t(C) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x56:
            printf("%02x\tMOV D, M\t(D) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x5E:
            printf("%02x\tMOV E, M\t(E) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x66:
            printf("%02x\tMOV H, M\t(H) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x6E:
            printf("%02x\tMOV L, M\t(L) <= ((H)(L))", *opcode);
            op_bytes = 1;
            break;
        case 0x7E:
            printf("%02x\tMOV A, M\t(A) <= ((H)(L))", *opcode);
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
            printf("%02x\tMOV M, B\t((H)(L)) <= (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x71:
            printf("%02x\tMOV M, C\t((H)(L)) <= (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x72:
            printf("%02x\tMOV M, D\t((H)(L)) <= (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x73:
            printf("%02x\tMOV M, E\t((H)(L)) <= (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x74:
            printf("%02x\tMOV M, H\t((H)(L)) <= (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x75:
            printf("%02x\tMOV M, L\t((H)(L)) <= (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x77:
            printf("%02x\tMOV M, A\t((H)(L)) <= (A)", *opcode);
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
            printf("%02x\tMVI B, d8\t(B) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x0E:
            printf("%02x\tMVI C, d8\t(C) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x16:
            printf("%02x\tMVI D, d8\t(D) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x1E:
            printf("%02x\tMVI E, d8\t(E) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x26:
            printf("%02x\tMVI H, d8\t(H) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x2E:
            printf("%02x\tMVI L, d8\t(L) <= #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;
        case 0x3E:
            printf("%02x\tMVI A, d8\t(A) <= #$%02x", *opcode, opcode[1]);
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
            printf("%02x\tMVI M, d8\t((H)(L)) <= #$%02x", *opcode, opcode[1]);
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
            printf("%02x\tLXI B, d16\t(B) <= #$%02x, (C) <= #$%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0x11:
            printf("%02x\tLXI D, d16\t(D) <= #$%02x, (E) <= #$%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0x21:
            printf("%02x\tLXI H, d16\t(H) <= #$%02x, (L) <= #$%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0x31:
            printf("%02x\tLXI SP, d16\t(SPH) <= #$%02x, (SPL) <= #$%02x", *opcode, opcode[2], opcode[1]);
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
            printf("%02x\tLDA a16\t(A) <= ($%02x%02x)", *opcode, opcode[2], opcode[1]);
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
            printf("%02x\tSTA a16\t($%02x%02x) <= (A)", *opcode, opcode[2], opcode[1]);
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
            printf("%02x\tLHLD a16\t(L) <= ($%02x%02x), (H) <= ($%02x%02x + 1)", *opcode, opcode[2], opcode[1], opcode[2], opcode[1]);
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
            printf("%02x\tSHLD a16\t($%02x%02x) <= (L), ($%02x%02x + 1) <= (H)", *opcode, opcode[2], opcode[1], opcode[2], opcode[1]);
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
            printf("%02x\tLDAX B\t(A) <= ((B)(C))", *opcode);
            op_bytes = 3;
            break;
        case 0x1A:
            printf("%02x\tLDAX D\t(A) <= ((D)(E))", *opcode);
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
            printf("%02x\tSTAX B\t((B)(C)) <= (A)", *opcode);
            op_bytes = 1;
            break;
        case 0x12:
            printf("%02x\tSTAX D\t((D)(E)) <= (A)", *opcode);
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
            printf("%02x\tXCHG\t(H) <=> (D), (L) <=> (E)", *opcode);
            op_bytes = 1;
            break;


        /*
            Arithmetic Group
        */
        /*
            Name : Add Register
            Explanation : The contents of register r is added to the content of the accumulator.
                The result is placed in the accumulator
            Encoding :  +---------------+
                        |1|0|0|0|0|S|S|S|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : Z, S, P, CY, AC
        */
        case 0x80:
            printf("%02x\tADD B\t(A) <= (A) + (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x81:
            printf("%02x\tADD C\t(A) <= (A) + (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x82:
            printf("%02x\tADD D\t(A) <= (A) + (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x83:
            printf("%02x\tADD E\t(A) <= (A) + (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x84:
            printf("%02x\tADD H\t(A) <= (A) + (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x85:
            printf("%02x\tADD L\t(A) <= (A) + (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x87:
            printf("%02x\tADD A\t(A) <= (A) + (A)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Add Memory
            Explanation : The contents the memory location, whose address is contained in the H
                and L registers is added to the content of the accumulator. The result is placed
                in the accumulator
            Encoding :  +---------------+
                        |1|0|0|0|0|1|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0x86:
            printf("%02x\tADD M\t(A) <= (A) + ((H)(L))", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Add Immediate
            Explanation : The contents of the second byte of the instruction is added to the
                content of the accumulator. The result is placed in the accumulator.
            Encoding :  +---------------+
                        |1|1|0|0|0|1|1|0|
                        +---------------+
                        |      DATA     |
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xC6:
            printf("%02x\tADI d8\t(A) <= (A) + #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;

        /*
            Name : Add Register with Carry
            Explanation : The contents of register r and the content of the carry bit are added
                to the content of the accumulator. The result is placed in the accumulator
            Encoding :  +---------------+
                        |1|0|0|0|1|S|S|S|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : Z, S, P, CY, AC
        */
        case 0x88:
            printf("%02x\tADC B\t(A) <= (A) + (B) + (CY)", *opcode);
            op_bytes = 1;
            break;
        case 0x89:
            printf("%02x\tADC C\t(A) <= (A) + (C) + (CY)", *opcode);
            op_bytes = 1;
            break;
        case 0x8A:
            printf("%02x\tADC D\t(A) <= (A) + (D) + (CY)", *opcode);
            op_bytes = 1;
            break;
        case 0x8B:
            printf("%02x\tADC E\t(A) <= (A) + (E) + (CY)", *opcode);
            op_bytes = 1;
            break;
        case 0x8C:
            printf("%02x\tADC H\t(A) <= (A) + (H) + (CY)", *opcode);
            op_bytes = 1;
            break;
        case 0x8D:
            printf("%02x\tADC L\t(A) <= (A) + (L) + (CY)", *opcode);
            op_bytes = 1;
            break;
        case 0x8F:
            printf("%02x\tADC A\t(A) <= (A) + (A) + (CY)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Add Memory with Carry
            Explanation : The contents of the memory location whose address is contained in the H
                and L registers and the content of the CY flag are added to the accumulator.
                The result is placed in the accumulator
            Encoding :  +---------------+
                        |1|0|0|0|1|1|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0x8E:
            printf("%02x\tADC M\t(A) <= (A) + ((H)(L)) + (CY)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Add Immediate with Carry
            Explanation : The contents of the second byte of the instruction and the content of
                the CY flag are added to the contents of the accumulator. The result is placed in the accumulator.
            Encoding :  +---------------+
                        |1|1|0|0|1|1|1|0|
                        +---------------+
                        |      DATA     |
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xCE:
            printf("%02x\tACI d8\t(A) <= (A) + #$%02x + (CY)", *opcode, opcode[1]);
            op_bytes = 2;
            break;

        /*
            Name : Substract Register
            Explanation : The contents of register r is substracted from the content of the accumulator.
                The result is placed in the accumulator
            Encoding :  +---------------+
                        |1|0|0|1|0|S|S|S|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : Z, S, P, CY, AC
        */
        case 0x90:
            printf("%02x\tSUB B\t(A) <= (A) - (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x91:
            printf("%02x\tSUB C\t(A) <= (A) - (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x92:
            printf("%02x\tSUB D\t(A) <= (A) - (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x93:
            printf("%02x\tSUB E\t(A) <= (A) - (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x94:
            printf("%02x\tSUB H\t(A) <= (A) - (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x95:
            printf("%02x\tSUB L\t(A) <= (A) - (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x97:
            printf("%02x\tSUB A\t(A) <= (A) - (A)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Substract Memory
            Explanation : The contents of the memory location whose address is contained in the H
                and L registers is substracted from the content of the accumulator. The result is
                placed in the accumulator
            Encoding :  +---------------+
                        |1|0|0|1|0|1|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0x96:
            printf("%02x\tSUB M\t(A) <= (A) - ((H)(L))", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Substract Immediate
            Explanation : The contents of the second byte of the instruction is substracted from the
                content of the accumulator. The result is placed in the accumulator.
            Encoding :  +---------------+
                        |1|1|0|1|0|1|1|0|
                        +---------------+
                        |      DATA     |
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xD6:
            printf("%02x\tSUI d8\t(A) <= (A) - #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;

        /*
            Name : Substract Register with Borrow
            Explanation : The contents of register r and the content of the CY flag are both substracted
                from the content of the accumulator. The result is placed in the accumulator
            Encoding :  +---------------+
                        |1|0|0|1|1|S|S|S|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : Z, S, P, CY, AC
        */
        case 0x98:
            printf("%02x\tSBB B\t(A) <= (A) - (CY) - (B)", *opcode);
            op_bytes = 1;
            break;
        case 0x99:
            printf("%02x\tSBB C\t(A) <= (A) - (CY) - (C)", *opcode);
            op_bytes = 1;
            break;
        case 0x9A:
            printf("%02x\tSBB D\t(A) <= (A) - (CY) - (D)", *opcode);
            op_bytes = 1;
            break;
        case 0x9B:
            printf("%02x\tSBB E\t(A) <= (A) - (CY) - (E)", *opcode);
            op_bytes = 1;
            break;
        case 0x9C:
            printf("%02x\tSBB H\t(A) <= (A) - (CY) - (H)", *opcode);
            op_bytes = 1;
            break;
        case 0x9D:
            printf("%02x\tSBB L\t(A) <= (A) - (CY) - (L)", *opcode);
            op_bytes = 1;
            break;
        case 0x9F:
            printf("%02x\tSBB A\t(A) <= (A) - (CY) - (A)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Substract Memory with Borrow
            Explanation : The contents of the memory location whose address is contained in the H
                and L registers and the content of the CY flag are both substracted from the accumulator.
                The result is placed in the accumulator
            Encoding :  +---------------+
                        |1|0|0|1|1|1|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0x9E:
            printf("%02x\tSBB M\t(A) <= (A) - ((H)(L)) - (CY)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Substract Immediate with Borrow
            Explanation : The contents of the second byte of the instruction and the content of the CY flag are
                both substracted from the contents of the accumulator. The result is placed in the accumulator.
            Encoding :  +---------------+
                        |1|1|0|1|1|1|1|0|
                        +---------------+
                        |      DATA     |
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xDE:
            printf("%02x\tSBI d8\t(A) <= (A) - #$%02x - (CY)", *opcode, opcode[1]);
            op_bytes = 2;
            break;

        /*
            Name : Increment Register
            Explanation : The content of register r is incremented by one.
                Note: all condition flags except CY are affected
            Encoding :  +---------------+
                        |0|0|D|D|D|1|0|0|
                        +---------------+
            Cycles / States : 1 / 5
            Flags : Z, S, P, AC
        */
        case 0x04:
            printf("%02x\tINR B\t(B) <= (B) + 1", *opcode);
            op_bytes = 1;
            break;
        case 0x0C:
            printf("%02x\tINR C\t(C) <= (C) + 1", *opcode);
            op_bytes = 1;
            break;
        case 0x14:
            printf("%02x\tINR D\t(D) <= (D) + 1", *opcode);
            op_bytes = 1;
            break;
        case 0x1C:
            printf("%02x\tINR E\t(E) <= (E) + 1", *opcode);
            op_bytes = 1;
            break;
        case 0x24:
            printf("%02x\tINR H\t(H) <= (H) + 1", *opcode);
            op_bytes = 1;
            break;
        case 0x2C:
            printf("%02x\tINR L\t(L) <= (L) + 1", *opcode);
            op_bytes = 1;
            break;
        case 0x3C:
            printf("%02x\tINR A\t(A) <= (A) + 1", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Increment Memory
            Explanation : The content of the memory location whose address is contained in the H and L
                registers is incremented by one. Note: all condition flags except CY are affected
            Encoding :  +---------------+
                        |0|0|1|1|0|1|0|0|
                        +---------------+
            Cycles / States : 3 / 10
            Flags : Z, S, P, AC
        */
        case 0x34:
            printf("%02x\tINR M\t((H)(L)) <= ((H)(L)) + 1", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Decrement Register
            Explanation : The content of register r is decremented by one.
                Note: all condition flags except CY are affected
            Encoding :  +---------------+
                        |0|0|D|D|D|1|0|1|
                        +---------------+
            Cycles / States : 1 / 5
            Flags : Z, S, P, AC
        */
        case 0x05:
            printf("%02x\tDCR B\t(B) <= (B) - 1", *opcode);
            op_bytes = 1;
            break;
        case 0x0D:
            printf("%02x\tDCR C\t(C) <= (C) - 1", *opcode);
            op_bytes = 1;
            break;
        case 0x15:
            printf("%02x\tDCR D\t(D) <= (D) - 1", *opcode);
            op_bytes = 1;
            break;
        case 0x1D:
            printf("%02x\tDCR E\t(E) <= (E) - 1", *opcode);
            op_bytes = 1;
            break;
        case 0x25:
            printf("%02x\tDCR H\t(H) <= (H) - 1", *opcode);
            op_bytes = 1;
            break;
        case 0x2D:
            printf("%02x\tDCR L\t(L) <= (L) - 1", *opcode);
            op_bytes = 1;
            break;
        case 0x3D:
            printf("%02x\tDCR A\t(A) <= (A) + 1", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Decrement Memory
            Explanation : The content of the memory location whose address is contained in the H and L
                registers is decremented by one. Note: all condition flags except CY are affected
            Encoding :  +---------------+
                        |0|0|1|1|0|1|0|1|
                        +---------------+
            Cycles / States : 3 / 10
            Flags : Z, S, P, AC
        */
        case 0x35:
            printf("%02x\tDCR M\t((H)(L)) <= ((H)(L)) - 1", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Increment Register Pair
            Explanation : The content of the register pair rp is incremented by one. Note: no condition are affected
            Encoding :  +---------------+
                        |0|0|R|P|0|0|1|1|
                        +---------------+
            Cycles / States : 1 / 5
            Flags : None
        */
        case 0x03:
            printf("%02x\tINX B\t(B)(C) <= (B)(C) + 1", *opcode);
            op_bytes = 1;
            break;
        case 0x13:
            printf("%02x\tINX D\t(D)(E) <= (D)(E) + 1", *opcode);
            op_bytes = 1;
            break;
        case 0x23:
            printf("%02x\tINX H\t(H)(L) <= (H)(L) + 1", *opcode);
            op_bytes = 1;
            break;
        case 0x33:
            printf("%02x\tINX SP\t(SP) <= (SP) + 1", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Decrement Register Pair
            Explanation : The content of the register pair rp is decremented by one. Note: no condition are affected
            Encoding :  +---------------+
                        |0|0|R|P|1|0|1|1|
                        +---------------+
            Cycles / States : 1 / 5
            Flags : None
        */
        case 0x0B:
            printf("%02x\tDCX B\t(B)(C) <= (B)(C) - 1", *opcode);
            op_bytes = 1;
            break;
        case 0x1B:
            printf("%02x\tDCX D\t(D)(E) <= (D)(E) - 1", *opcode);
            op_bytes = 1;
            break;
        case 0x2B:
            printf("%02x\tDCX H\t(H)(L) <= (H)(L) - 1", *opcode);
            op_bytes = 1;
            break;
        case 0x3B:
            printf("%02x\tDCX SP\t(SP) <= (SP) - 1", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Add Register Pair to H and L
            Explanation : The content of the register pair rp is added to the content of the register pair H and L.
                The result is placed in the register pair H and L. Note: only the CY condition flag is affected.
                It is set if there is a carry out of the double precision add, otherwise it is reset.
            Encoding :  +---------------+
                        |0|0|R|P|1|0|0|1|
                        +---------------+
            Cycles / States : 3 / 10
            Flags : CY
        */
        case 0x09:
            printf("%02x\tDAD B\t(H)(L) <= (H)(L) + (B)(C)", *opcode);
            op_bytes = 1;
            break;
        case 0x19:
            printf("%02x\tDAD D\t(H)(L) <= (H)(L) + (D)(E)", *opcode);
            op_bytes = 1;
            break;
        case 0x29:
            printf("%02x\tDAD H\t(H)(L) <= (H)(L) + (H)(L)", *opcode);
            op_bytes = 1;
            break;
        case 0x39:
            printf("%02x\tDAD SP\t(H)(L) <= (H)(L) + (SP)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Decimal Ajust Accumulator
            Explanation : The eight-bit number in the accumulator is adjusted to form two four-bit Binary-Coded-Decimal
                digits by the following process :
                    1. If the value of the least significant 4 bits of the accumulator is greater than 9 or is the
                        AC flag is set, 6 is added to the accumulator;
                    2. If the value of the most significant 4 bits of the accumulator is now greater than 9, or if
                        the CY flag is set, 6 is added to the most significant 4 bits of the accumulator.
            Encoding :  +---------------+
                        |0|0|1|0|0|1|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : Z, S, P, CY, AC
        */
        case 0x27:
            printf("%02x\tDAA\tDecimal Adjust Accumulator", *opcode);
            op_bytes = 1;
            break;


        /*
            Logical Group
        */
        /*
            Name : AND Register
            Explanation : The content of register r is logically anded with the content of the accumulator. The result is
                placed in the accumulator. The CY flag is cleared.
            Encoding :  +---------------+
                        |1|0|1|0|0|S|S|S|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : Z, S, P, CY, AC
        */
        case 0xA0:
            printf("%02x\tANA B\t(A) <= (A) && (B)", *opcode);
            op_bytes = 1;
            break;
        case 0xA1:
            printf("%02x\tANA C\t(A) <= (A) && (C)", *opcode);
            op_bytes = 1;
            break;
        case 0xA2:
            printf("%02x\tANA D\t(A) <= (A) && (D)", *opcode);
            op_bytes = 1;
            break;
        case 0xA3:
            printf("%02x\tANA E\t(A) <= (A) && (E)", *opcode);
            op_bytes = 1;
            break;
        case 0xA4:
            printf("%02x\tANA H\t(A) <= (A) && (H)", *opcode);
            op_bytes = 1;
            break;
        case 0xA5:
            printf("%02x\tANA L\t(A) <= (A) && (L)", *opcode);
            op_bytes = 1;
            break;
        case 0xA7:
            printf("%02x\tANA A\t(A) <= (A) && (A)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : AND Memory
            Explanation : The content of the memory location whose address is contained in the H and L registers is logically anded
                with the content of the accumulator. The result is placed in the accumulator. The CY flag is cleared.
            Encoding :  +---------------+
                        |1|0|1|0|0|1|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xA6:
            printf("%02x\tANA M\t(A) <= (A) && ((H)(L))", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : AND Immediate
            Explanation : The content of the second byte of the instruction is logically anded with the content of the accumulator.
                The result is placed in the accumulator. The CY and AC flags are cleared.
            Encoding :  +---------------+
                        |1|1|1|0|0|1|1|0|
                        +---------------+
                        |      DATA     |
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xE6:
            printf("%02x\tANI d8\t(A) <= (A) && #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;

        /*
            Name : Exclusive OR Register
            Explanation : The content of register r is exclusive-or'd with the content of the accumulator. The result is
                placed in the accumulator. The CY and AC flags are cleared.
            Encoding :  +---------------+
                        |1|0|1|0|1|S|S|S|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : Z, S, P, CY, AC
        */
        case 0xA8:
            printf("%02x\tXRA B\t(A) <= (A) ^ (B)", *opcode);
            op_bytes = 1;
            break;
        case 0xA9:
            printf("%02x\tXRA C\t(A) <= (A) ^ (C)", *opcode);
            op_bytes = 1;
            break;
        case 0xAA:
            printf("%02x\tXRA D\t(A) <= (A) ^ (D)", *opcode);
            op_bytes = 1;
            break;
        case 0xAB:
            printf("%02x\tXRA E\t(A) <= (A) ^ (E)", *opcode);
            op_bytes = 1;
            break;
        case 0xAC:
            printf("%02x\tXRA H\t(A) <= (A) ^ (H)", *opcode);
            op_bytes = 1;
            break;
        case 0xAD:
            printf("%02x\tXRA L\t(A) <= (A) ^ (L)", *opcode);
            op_bytes = 1;
            break;
        case 0xAF:
            printf("%02x\tXRA A\t(A) <= (A) ^ (A)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Exclusive OR Memory
            Explanation : The content of the memory location whose address is contained in the H and L registers is exclusive-OR'd
                with the content of the accumulator. The result is placed in the accumulator. The CY and AC flags are cleared.
            Encoding :  +---------------+
                        |1|0|1|0|1|1|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xAE:
            printf("%02x\tXRA M\t(A) <= (A) ^ ((H)(L))", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Exclusive OR Immediate
            Explanation : The content of the second byte of the instruction is exclusive-OR'd with the content of the accumulator.
                The result is placed in the accumulator. The CY and AC flag are cleared.
            Encoding :  +---------------+
                        |1|1|1|0|1|1|1|0|
                        +---------------+
                        |      DATA     |
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xEE:
            printf("%02x\tXRI d8\t(A) <= (A) ^ #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;

        /*
            Name : OR Register
            Explanation : The content of register r is inclusive-or'd with the content of the accumulator. The result is
                placed in the accumulator. The CY and AC flags are cleared.
            Encoding :  +---------------+
                        |1|0|1|1|0|S|S|S|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : Z, S, P, CY, AC
        */
        case 0xB0:
            printf("%02x\tORA B\t(A) <= (A) || (B)", *opcode);
            op_bytes = 1;
            break;
        case 0xB1:
            printf("%02x\tORA C\t(A) <= (A) || (C)", *opcode);
            op_bytes = 1;
            break;
        case 0xB2:
            printf("%02x\tORA D\t(A) <= (A) || (D)", *opcode);
            op_bytes = 1;
            break;
        case 0xB3:
            printf("%02x\tORA E\t(A) <= (A) || (E)", *opcode);
            op_bytes = 1;
            break;
        case 0xB4:
            printf("%02x\tORA H\t(A) <= (A) || (H)", *opcode);
            op_bytes = 1;
            break;
        case 0xB5:
            printf("%02x\tORA L\t(A) <= (A) || (L)", *opcode);
            op_bytes = 1;
            break;
        case 0xB7:
            printf("%02x\tORA A\t(A) <= (A) || (A)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : OR Memory
            Explanation : The content of the memory location whose address is contained in the H and L registers is inclusive-OR'd
                with the content of the accumulator. The result is placed in the accumulator. The CY and AC flags are cleared.
            Encoding :  +---------------+
                        |1|0|1|1|0|1|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xB6:
            printf("%02x\tORA M\t(A) <= (A) || ((H)(L))", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : OR Immediate
            Explanation : The content of the second byte of the instruction is inclusive-OR'd with the content of the accumulator.
                The result is placed in the accumulator. The CY and AC flag are cleared.
            Encoding :  +---------------+
                        |1|1|1|1|0|1|1|0|
                        +---------------+
                        |      DATA     |
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xF6:
            printf("%02x\tORI d8\t(A) <= (A) || #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;

        /*
            Name : Compare Register
            Explanation : The content of register r is substracted from the accumulator. The accumulator remains unchanged. The condition
                flags are set as a result of the substraction. The Z flag is set to 1 if (A) = (r). The CY flag is set to 1 if (A) < (r).
            Encoding :  +---------------+
                        |1|0|1|1|1|S|S|S|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : Z, S, P, CY, AC
        */
        case 0xB8:
            printf("%02x\tCMP B\t(A) - (B)", *opcode);
            op_bytes = 1;
            break;
        case 0xB9:
            printf("%02x\tCMP C\t(A) - (C)", *opcode);
            op_bytes = 1;
            break;
        case 0xBA:
            printf("%02x\tCMP D\t(A) - (D)", *opcode);
            op_bytes = 1;
            break;
        case 0xBB:
            printf("%02x\tCMP E\t(A) - (E)", *opcode);
            op_bytes = 1;
            break;
        case 0xBC:
            printf("%02x\tCMP H\t(A) - (H)", *opcode);
            op_bytes = 1;
            break;
        case 0xBD:
            printf("%02x\tCMP L\t(A) - (L)", *opcode);
            op_bytes = 1;
            break;
        case 0xBF:
            printf("%02x\tCMP A\t(A) - (A)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Compare Memory
            Explanation : The content of the memory location whose address is contained in the H and L registers is substracted from the accumulator.
                The accumulator remains unchanged. The condition flags are set as a result of the substraction.
                The Z flag is set to 1 if (A) = ((H)(L)). The CY flag is set to 1 if (A) < ((H)(L)).
            Encoding :  +---------------+
                        |1|0|1|1|1|1|1|0|
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xBE:
            printf("%02x\tCMP M\t(A) - ((H)(L))", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Compare Immediate
            Explanation : The content of the second byte of the instruction is substracted from the accumulator. The accumulator remains unchanged.
                The condition flags are set as a result of the substraction. The Z flag is set to 1 if (A) = (byte2). The CY flag is set to 1 if (A) < (byte2).
            Encoding :  +---------------+
                        |1|1|1|1|1|1|1|0|
                        +---------------+
                        |      DATA     |
                        +---------------+
            Cycles / States : 2 / 7
            Flags : Z, S, P, CY, AC
        */
        case 0xFE:
            printf("%02x\tCPI d8\t(A) - #$%02x", *opcode, opcode[1]);
            op_bytes = 2;
            break;

         /*
            Name : Rotate Left
            Explanation : The content of the accumulator is rotated left one position. The low order bit and the CY flag are both set to the value
                shifted out of the high order bit position. Only the CY flag is affected
            Encoding :  +---------------+
                        |0|0|0|0|0|1|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : CY
        */
        case 0x07:
            printf("%02x\tRLC\t(An+1) <= (An), (A0) <= (A7), (CY) <= (A7)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Rotate Right
            Explanation : The content of the accumulator is rotated right one position. The high order bit and the CY flag are both set to the value
                shifted out of the low order bit position. Only the CY flag is affected
            Encoding :  +---------------+
                        |0|0|0|0|1|1|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : CY
        */
        case 0x0F:
            printf("%02x\tRRC\t(An) <= (An+1), (A7) <= (A0), (CY) <= (A0)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Rotate Left through Carry
            Explanation : The content of the accumulator is rotated left one position though the CY flag. The low order bit is set equal to the CY flag
                and the CY flag is set to the value shifted out of the high order bit. Only the CY flag is affected
            Encoding :  +---------------+
                        |0|0|0|1|0|1|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : CY
        */
        case 0x17:
            printf("%02x\tRAL\t(An+1) <= (An), (CY) <= (A7), (A0) <= (CY)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Rotate Right through Carry
            Explanation : The content of the accumulator is rotated right one position though the CY flag. The high order bit is set equal to the CY flag
                and the CY flag is set to the value shifted out of the low order bit. Only the CY flag is affected
            Encoding :  +---------------+
                        |0|0|0|1|1|1|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : CY
        */
        case 0x1F:
            printf("%02x\tRAR\t(An) <= (An+1), (CY) <= (A0), (A7) <= (CY)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Complement Accumulator
            Explanation : The contents of the accumulator are complemented (zero bits decome 1, one bits become 0). No flags are affected
            Encoding :  +---------------+
                        |0|0|1|0|1|1|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : None
        */
        case 0x2F:
            printf("%02x\tCMA\t(An) <= !(An)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Complement Carry
            Explanation : The CY flag is complemented. No other flags are affected
            Encoding :  +---------------+
                        |0|0|1|1|1|1|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : CY
        */
        case 0x3F:
            printf("%02x\tCMC\t(CY) <= !(CY)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Set Carry
            Explanation : The CY flag is set to 1. No other flags are affected
            Encoding :  +---------------+
                        |0|0|1|1|0|1|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : CY
        */
        case 0x37:
            printf("%02x\tSTC\t(CY) <= 1", *opcode);
            op_bytes = 1;
            break;


        /*
            Branch Group

            Specifications:
                - Condition flags are not affected by any instructions in the group
                - Two types of branch instructions :
                    - Conditionnal : Depend on the content of one of the flags
                    - Unconditionnal : Simply perform an operation on the Program Counter (PC)

            Conditions :
                +------+-----------+------+-----+
                | NAME |  VERBOSE  | FLAG | CCC |
                +------+-----------+------+-----+
                |  NZ  | Not Zero  |Z  = 0| 000 |
                |   Z  |     Zero  |Z  = 1| 001 |
                |  NC  | No Carry  |CY = 0| 010 |
                |   C  |    Carry  |CY = 1| 011 |
                |  PO  |Parity odd |P  = 0| 100 |
                |  PE  |Parity even|P  = 1| 101 |
                |   P  | Plus sign |S  = 0| 110 |
                |   M  |Minus sign |S  = 1| 111 |
                +------+-----------+------+-----+

        */
       /*
            Name : Jump
            Explanation : Control is transfered to the instruction whose addresss is specified in byte 3 and byte 2 of the current instruction.
            Encoding :  +---------------+
                        |1|1|0|0|0|0|1|1|
                        +---------------+
                        | low-order ADDR|
                        +---------------+
                        |high-order ADDR|
                        +---------------+
            Cycles / States : 3 / 10
            Flags : None
        */
        case 0xC3:
        case 0xCB:
            printf("%02x\tJMP addr\t(PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;

        /*
            Name : Conditionnal Jump
            Explanation : If the specified condition is true, control is transfered to the instruction whose addresss is specified in byte 3 and byte 2
                of the current instruction; otherwise, control continues sequentially.
            Encoding :  +---------------+
                        |1|1|C|C|C|0|1|0|
                        +---------------+
                        | low-order ADDR|
                        +---------------+
                        |high-order ADDR|
                        +---------------+
            Cycles / States : 3 / 10
            Flags : None
        */
        case 0xC2:
            printf("%02x\tJNZ addr\tif(Z = 0): (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xCA:
            printf("%02x\tJZ addr\tif(Z = 1): (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xD2:
            printf("%02x\tJNC addr\tif(CY = 0): (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xDA:
            printf("%02x\tJC addr\tif(CY = 1): (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xE2:
            printf("%02x\tJPO addr\tif(P = 0): (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xEA:
            printf("%02x\tJPE addr\tif(P = 1): (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xF2:
            printf("%02x\tJP addr\tif(S = 0): (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xFA:
            printf("%02x\tJM addr\tif(S = 1): (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;

        /*
            Name : Call
            Explanation :
                -The high-order eight bits of the next instruction address are moved to the memory location whose address is one less than the content of register SP.
                -The low-order eight bits of the next instruction address are moved to the memory location whose address is two less than the content of register SP.
                -The content of regoster SP is decremented by 2. => push the address of the next instruction on the stack
                -Control is transfered to the instruction whose address is specified in byte 2 and byte 3 of the current instruction.
            Encoding :  +---------------+
                        |1|1|0|0|1|1|0|1|
                        +---------------+
                        | low-order ADDR|
                        +---------------+
                        |high-order ADDR|
                        +---------------+
            Cycles / States : 5 / 17
            Flags : None
        */
        case 0xCD:
        case 0xDD:
        case 0xED:
        case 0xFD:
            printf("%02x\tCALL addr\t((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP - 2), (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;

        /*
            Name : Conditionnal Call
            Explanation : If the specified condition is true, the actions specified in the CALL instruction are performed;
                otherwise, control continues sequentially.
            Encoding :  +---------------+
                        |1|1|C|C|C|1|0|0|
                        +---------------+
                        | low-order ADDR|
                        +---------------+
                        |high-order ADDR|
                        +---------------+
            Cycles / States : 11 / 17
            Flags : None
        */
        case 0xC4:
            printf("%02x\tCNZ addr\tif(Z = 0): ((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP - 2), (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xCC:
            printf("%02x\tCZ addr\tif(Z = 1): ((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP - 2), (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xD4:
            printf("%02x\tCNC addr\tif(CY = 0): ((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP - 2), (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xDC:
            printf("%02x\tCC addr\tif(CY = 1): ((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP - 2), (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xE4:
            printf("%02x\tCPO addr\tif(P = 0): ((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP - 2), (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xEC:
            printf("%02x\tCPE addr\tif(P = 1): ((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP - 2), (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xF4:
            printf("%02x\tCP addr\tif(S = 0): ((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP - 2), (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;
        case 0xFC:
            printf("%02x\tCM addr\tif(S = 1): ((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP - 2), (PC) <= #$%02x%02x", *opcode, opcode[2], opcode[1]);
            op_bytes = 3;
            break;

        /*
            Name : Return
            Explanation :
                -The content of the memory location whose address is specified in register SP is moved to the low-order eight bits of register PC.
                -The content of the memory location whose address is one more than the content of register SP is mover to the high-order eight bits of register PC.
                -The content of register SP is incremented by two. => POP the address on top of the stack into the register PC.
            Encoding :  +---------------+
                        |1|1|0|0|1|0|1|1|
                        +---------------+
            Cycles / States : 3 / 10
            Flags : None
        */
        case 0xC9:
        case 0xD9:
            printf("%02x\tRET\t(PCL) <= ((SP)), (PCH) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Conditionnal Return
            Explanation : If the specified condition is true, the actions specified in the RET instruction are performed;
                otherwise, control continues sequentially.
            Encoding :  +---------------+
                        |1|1|C|C|C|0|0|0|
                        +---------------+
            Cycles / States : 5 / 11
            Flags : None
        */
        case 0xC0:
            printf("%02x\tRNZ\tif(Z = 0): (PCL) <= ((SP)), (PCH) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;
        case 0xC8:
            printf("%02x\tRZ\tif(Z = 1): ((PCL) <= ((SP)), (PCH) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;
        case 0xD0:
            printf("%02x\tRNC\tif(CY = 0): (PCL) <= ((SP)), (PCH) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;
        case 0xD8:
            printf("%02x\tRC\tif(CY = 1): (PCL) <= ((SP)), (PCH) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;
        case 0xE0:
            printf("%02x\tRPO\tif(P = 0): (PCL) <= ((SP)), (PCH) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;
        case 0xE8:
            printf("%02x\tRPE\tif(P = 1): (PCL) <= ((SP)), (PCH) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;
        case 0xF0:
            printf("%02x\tRP\tif(S = 0): (PCL) <= ((SP)), (PCH) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;
        case 0xF8:
            printf("%02x\tRM\tif(S = 1): (PCL) <= ((SP)), (PCH) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Restart
            Explanation :
                -The high-order eight bits of the next instruction address are moved to the memory location whose address is one less than the content of the SP.
                -The low-order eight bits of the next instruction address are moved to the memory location whose address is two less than the content of the SP.
                -The content of register SP is decremented by two. => PUSH the PC on the stack
                -Control is transfered to the instruction whose address is eight times the content of NNN.

                This is used to jump to a specific vector location. These vector addresses contain (mainly) executable code (AKA a jump instruction to an interrupt subroutine).
            Encoding :  +---------------+
                        |1|1|N|N|N|1|1|1|
                        +---------------+
            Cycles / States : 3 / 11
            Flags : None
        */
        case 0xC7:
            printf("%02x\tRST 0\t((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP) - 2, (PC) <= 8 * 0b000", *opcode);
            op_bytes = 1;
            break;
        case 0xCF:
            printf("%02x\tRST 1\t((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP) - 2, (PC) <= 8 * 0b001", *opcode);
            op_bytes = 1;
            break;
        case 0xD7:
            printf("%02x\tRST 2\t((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP) - 2, (PC) <= 8 * 0b010", *opcode);
            op_bytes = 1;
            break;
        case 0xDF:
            printf("%02x\tRST 3\t((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP) - 2, (PC) <= 8 * 0b011", *opcode);
            op_bytes = 1;
            break;
        case 0xE7:
            printf("%02x\tRST 4\t((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP) - 2, (PC) <= 8 * 0b100", *opcode);
            op_bytes = 1;
            break;
        case 0xEF:
            printf("%02x\tRST 5\t((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP) - 2, (PC) <= 8 * 0b101", *opcode);
            op_bytes = 1;
            break;
        case 0xF7:
            printf("%02x\tRST 6\t((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP) - 2, (PC) <= 8 * 0b110", *opcode);
            op_bytes = 1;
            break;
        case 0xFF:
            printf("%02x\tRST 7\t((SP) - 1) <= (PCH), ((SP) - 2) <= (PCL), (SP) <= (SP) - 2, (PC) <= 8 * 0b111", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Jump H and L direct / Move H and L to PC
            Explanation :
                -The content register H is moved to the high-order eight bits of register PC.
                -The content register L is moved to the low-order eight bits of register PC.
            Encoding :  +---------------+
                        |1|1|1|0|1|0|0|1|
                        +---------------+
            Cycles / States : 1 / 5
            Flags : None
        */
        case 0xE9:
            printf("%02x\tPCHL\t(PCH) <= (H), (PCL) <= (L)", *opcode);
            op_bytes = 1;
            break;


        /*
            Stack, I/O, and Machine Control Group
        */
        /*
            Name : Push
            Explanation :
                -The content of the high-order register of register pair is moved to the memory location whose address is one less than the content of register SP.
                -The content of the low-order register of register pair is moved to the memory location whose address is two less than the content of register SP.
                -The content of register SP is decremented by 2.
                Note: register pair rp = SP may not be specified.
            Encoding :  +---------------+
                        |1|1|R|P|0|1|0|1|
                        +---------------+
            Cycles / States : 3 / 11
            Flags : None
        */
        case 0xC5:
            printf("%02x\tPUSH B\t((SP) - 1) <= (C), ((SP) - 2) <= (B), (SP) <= (SP) - 2", *opcode);
            op_bytes = 1;
            break;
        case 0xD5:
            printf("%02x\tPUSH E\t((SP) - 1) <= (D), ((SP) - 2) <= (E), (SP) <= (SP) - 2", *opcode);
            op_bytes = 1;
            break;
        case 0xE5:
            printf("%02x\tPUSH H\t((SP) - 1) <= (H), ((SP) - 2) <= (L), (SP) <= (SP) - 2", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Push Processor Status Word
            Explanation :
                -The content register A is moved to the memory location whose address is one less than the content of register SP.
                -The content register F (flags) is moved to the memory location whose address is two less than the content of register SP.
                -The content of register SP is decremented by 2.
            Encoding :  +---------------+
                        |1|1|1|1|0|1|0|1|
                        +---------------+
            Cycles / States : 3 / 11
            Flags : None
        */
        case 0xF5:
            printf("%02x\tPUSH PSW\t((SP) - 1) <= (A), ((SP) - 2) <= (F), (SP) <= (SP) - 2", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Pop
            Explanation :
                -The content of the memory location, whose address is specified by the content of register SP,
                    is moved to the low-order register of register pair rp.
                -The content of the memory location, whose address is one more than the content of register SP,
                    is moved to the high-order register of register pair rp.
                -The content of register SP is incremented by 2.
                Note: register pair rp = SP may not be specified.
            Encoding :  +---------------+
                        |1|1|R|P|0|0|0|1|
                        +---------------+
            Cycles / States : 3 / 10
            Flags : None
        */
        case 0xC1:
            printf("%02x\tPOP B\t(C) <= ((SP)), (B) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;
        case 0xD1:
            printf("%02x\tPOP D\t(D) <= ((SP)), (E) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;
        case 0xE1:
            printf("%02x\tPOP H\t(H) <= ((SP)), (L) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Pop Processor Status Word
            Explanation :
                -The content of the memory location whose address is specified by the content of register SP is used to restore the condition flags.
                -The content of the memory location whose address is one more than the content of register SP is moved to register A.
                -The content of register SP is incremented by 2.
            Encoding :  +---------------+
                        |1|1|1|1|0|0|0|1|
                        +---------------+
            Cycles / States : 3 / 10
            Flags : Z, S, P, CY, AC
        */
        case 0xF1:
            printf("%02x\tPOP PSW\t(F) <= ((SP)), (A) <= ((SP) + 1), (SP) <= (SP) + 2", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Exchange Stack Top with H and L
            Explanation :
                -The content of the L register is exchanged with the content of the memory location whose address is specified by the content of register SP.
                -The content of the H register is exchanged with the content of the memory location whose address is one more than the content of regoster SP.
            Encoding :  +---------------+
                        |1|1|1|0|0|0|1|1|
                        +---------------+
            Cycles / States : 5 / 18
            Flags : None
        */
        case 0xE3:
            printf("%02x\tXTHL\t(L) <= ((SP)), (H) <= ((SP) + 1)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Move HL to SP
            Explanation : The contents of registers H and L (16 bits) are moved to register SP.
            Encoding :  +---------------+
                        |1|1|1|1|1|0|0|1|
                        +---------------+
            Cycles / States : 1 / 5
            Flags : None
        */
        case 0xF9:
            printf("%02x\tSPHL\t(SP) <= (H)(L)", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Input
            Explanation : The data placed on the eight bit bi-directional data bus by the specified port is moved to register A.
            Encoding :  +---------------+
                        |1|1|0|1|1|0|1|1|
                        +---------------+
                        |      Port     |
                        +---------------+
            Cycles / States : 3 / 10
            Flags : None
        */
        case 0xDB:
            printf("%02x\tIN port\t(A) <= (data)", *opcode);
            op_bytes = 2;
            break;

        /*
            Name : Output
            Explanation : The content of register A is placed on the eight bit bi-directional data bus for transmission to the specified port.
            Encoding :  +---------------+
                        |1|1|0|1|0|0|1|1|
                        +---------------+
                        |      Port     |
                        +---------------+
            Cycles / States : 3 / 10
            Flags : None
        */
        case 0xD3:
            printf("%02x\tOUT port\t(data) <= (A)", *opcode);
            op_bytes = 2;
            break;

        /*
            Name : Enable Interrupts
            Explanation : The interrupt system is enabled following the execution of the next instruction.
            Encoding :  +---------------+
                        |1|1|1|1|1|0|1|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : None
        */
        case 0xFB:
            printf("%02x\tEI\tEnable interrupts", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Disable Interrupts
            Explanation : The interrupt system is disabled following the execution of the DI instruction.
            Encoding :  +---------------+
                        |1|1|1|1|1|0|0|1|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : None
        */
        case 0xF3:
            printf("%02x\tDI\tDisable interrupts", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : Halt
            Explanation : The processor is stopped. The registers and flags are unaffected.
            Encoding :  +---------------+
                        |0|1|1|1|0|1|1|0|
                        +---------------+
            Cycles / States : 1 / 7
            Flags : None
        */
        case 0x76:
            printf("%02x\tHLT\tStop processor", *opcode);
            op_bytes = 1;
            break;

        /*
            Name : No op
            Explanation : No operation is performed. The registers and flags are unaffected.
            Encoding :  +---------------+
                        |0|0|0|0|0|0|0|0|
                        +---------------+
            Cycles / States : 1 / 4
            Flags : None
        */
        case 0x00:
        case 0x08:
        case 0x10:
        case 0x18:
        case 0x20:
        case 0x28:
        case 0x30:
        case 0x38:
            printf("%02x\tNOP\t", *opcode);
            op_bytes = 1;
            break;

        default:
            printf("Instruction non prise en charge : %02x", *opcode);
            break;
    }
    printf("\n");
    return op_bytes;
}
