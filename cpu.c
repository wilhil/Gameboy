#define SET_AF(x) do {registers.A = ((x & 0xFF00) >> 8); registers.F = (x&0x00FF);} while(0) // multi-line macro
#define SET_BC(x) do {registers.B = ((x & 0xFF00) >> 8); registers.C = (x&0x00FF);} while(0)
#define SET_DE(x) do {registers.D = ((x & 0xFF00) >> 8); registers.E = (x&0x00FF);} while(0)
#define SET_HL(x) do {registers.H = ((x & 0xFF00) >> 8); registers.L = (x&0x00FF);} while(0)

#define GET_AF() ((registers.A << 8) | registers.F)
#define GET_BC() ((registers.B << 8) | registers.C)
#define GET_DE() ((registers.D << 8) | registers.E)
#define GET_HL() ((registers.H << 8) | registers.L)

#define SET_Z(x) ((registers.F & 0x7F) | (x << 7))
#define SET_N(x) ((registers.F & 0xBF) | (x << 6))
#define SET_H(x) ((registers.F & 0xDF) | (x << 5))
#define SET_C(x) ((registers.F & 0xEF) | (x << 4))

#define FLAG_Z ((registers.F >> 7) & 0x1)
#define FLAG_N ((registers.F >> 6) & 0x1)
#define FLAG_H ((registers.F >> 5) & 0x1)
#define FLAG_C ((registers.F >> 4) & 0x1)

struct registers {
    unsigned char A;
    unsigned char F; // flags: Z N H C

    unsigned char B;
    unsigned char C;

    unsigned char D;
    unsigned char E;

    unsigned char H;
    unsigned char L;

    unsigned short SP;
    unsigned short PC;

    unsigned int cycles;
} registers;

struct registers registers;

void reset(void) {

    registers.PC = 0x100;
    registers.cycles = 0;
}

void cpuCycle(void) {
    unsigned char instruction = readByte(registers.PC);

    switch (instruction) {
        case 0x06:    // LD B,n
            registers.B = readByte(registers.PC+1);
            registers.PC += 2;
            registers.cycles += 2;
            break;
        case 0x0E:    // LD C,n
            registers.C = readByte(registers.PC+1);
            registers.PC += 2;
            registers.cycles += 2;
            break;
        case 0x16:    // LD D,n
            registers.D = readByte(registers.PC+1);
            registers.PC += 2;
            registers.cycles += 2;
            break;
        case 0x1E:    // LD E,n
            registers.E = readByte(registers.PC+1);
            registers.PC += 2;
            registers.cycles += 2;
            break;
        case 0x26:    // LD H,n
            registers.H = readByte(registers.PC+1);
            registers.PC += 2;
            registers.cycles += 2;
            break;
        case 0x2E:    // LD L,n
            registers.L = readByte(registers.PC+1);
            registers.PC += 2;
            registers.cycles += 2;
            break;
        case 0x40:    // LD B,B
            registers.B = registers.B;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x41:    // LD B,C
            registers.B = registers.C;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x42:    // LD B,D
            registers.B = registers.D;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x43:    // LD B,E
            registers.B = registers.E;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x44:    // LD B,H
            registers.B = registers.H;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x45:    // LD B,L
            registers.B = registers.L;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x46:    // LD B,(HL)
            registers.B = readByte(GET_HL());
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x48:    // LD C,B
            registers.C = registers.B;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x49:    // LD C,C
            registers.C = registers.C;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x4A:    // LD C,D
            registers.C = registers.D;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x4B:    // LD C,E
            registers.C = registers.E;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x4C:    // LD C,H
            registers.C = registers.H;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x4D:    // LD C,L
            registers.C = registers.L;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x4E:    // LD C,(HL)
            registers.C = readByte(GET_HL());
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x50:    // LD D,B
            registers.D = registers.B;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x51:    // LD D,C
            registers.D = registers.C;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x52:    // LD D,D
            registers.D = registers.D;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x53:    // LD D,E
            registers.D = registers.E;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x54:    // LD D,H
            registers.D = registers.H;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x55:    // LD D,L
            registers.D = registers.L;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x56:    // LD D,(HL)
            registers.D = readByte(GET_HL());
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x58:    // LD E,B
            registers.E = registers.B;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x59:    // LD E,C
            registers.E = registers.C;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x5A:    // LD E,D
            registers.E = registers.D;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x5B:    // LD E,E
            registers.E = registers.E;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x5C:    // LD E,H
            registers.E = registers.H;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x5D:    // LD E,L
            registers.E = registers.L;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x5E:    // LD E,(HL)
            registers.E = readByte(GET_HL());
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x60:    // LD H,B
            registers.H = registers.B;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x61:    // LD H,C
            registers.H = registers.C;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x62:    // LD H,D
            registers.H = registers.D;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x63:    // LD H,E
            registers.H = registers.E;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x64:    // LD H,H
            registers.H = registers.H;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x65:    // LD H,L
            registers.H = registers.L;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x66:    // LD H,(HL)
            registers.H = readByte(GET_HL());
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x68:    // LD L,B
            registers.L = registers.B;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x69:    // LD L,C
            registers.L = registers.C;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x6A:    // LD L,D
            registers.L = registers.D;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x6B:    // LD L,E
            registers.L = registers.E;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x6C:    // LD L,H
            registers.L = registers.H;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x6D:    // LD L,L
            registers.L = registers.L;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x6E:    // LD L,(HL)
            registers.L = readByte(GET_HL());
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x70:    // LD (HL),B
            writeByte(GET_HL(), registers.B);
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x71:    // LD (HL),C
            writeByte(GET_HL(), registers.C);
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x72:    // LD (HL),D
            writeByte(GET_HL(), registers.D);
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x73:    // LD (HL),E
            writeByte(GET_HL(), registers.E);
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x74:    // LD (HL),H
            writeByte(GET_HL(), registers.H);
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x75:    // LD (HL),L
            writeByte(GET_HL(), registers.L);
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x76:    // LD (HL),n
            writeByte(GET_HL(), readByte(registers.PC+1));
            registers.PC += 2;
            registers.cycles += 4;
            break;
        case 0x78:    // LD A,B
            registers.A = registers.B;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x79:    // LD A,C
            registers.A = registers.C;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x7A:    // LD A,D
            registers.A = registers.D;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x7B:    // LD A,E
            registers.A = registers.E;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x7C:    // LD A,H
            registers.A = registers.H;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x7D:    // LD A,L
            registers.A = registers.L;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        case 0x7E:    // LD A,(HL)
            registers.A = readByte(GET_HL());
            registers.PC += 1;
            registers.cycles += 2;
            break;
        case 0x7F:    // LD A,A
            registers.A = registers.A;
            registers.PC += 1;
            registers.cycles += 1;
            break;
        default:
            printf("Undefined instruction.");
            break;
    }
}
