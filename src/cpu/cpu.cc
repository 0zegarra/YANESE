#define ORA 0b00000000 | 0b0000000
#define AND 0b00100000 | 0b0000000
#define EOR 0b01000000 | 0b0000000
#define ADC 0b01100000 | 0b0000000
#define STA 0b10000000 | 0b0000000
#define LDA 0b10100000 | 0b0000000
#define CMP 0b11000000 | 0b0000000
#define SBC 0b11100000 | 0b0000000              

#define ASL 0b00000000 | 0b0000010 
#define ROL 0b00100000 | 0b0000010 
#define LSR 0b01000000 | 0b0000010 
#define ROR 0b01100000 | 0b0000010 
#define STX 0b10000000 | 0b0000010 
#define LDX 0b10100000 | 0b0000010 
#define DEC 0b11000000 | 0b0000010 
#define INC 0b11100000 | 0b0000010 

#define BIT  0b00100000 | 0b0000000 
#define JMP  0b01000000 | 0b0000000 
#define JMPA 0b01100000 | 0b0000000  
#define STY  0b10000000 | 0b0000000 
#define LDY  0b10100000 | 0b0000000 
#define CPY  0b11000000 | 0b0000000 
#define CPX  0b11100000 | 0b0000000 

#define DEX 0xCA

// Masks for flag values
#define CARRY  0b0000001
#define ZERO   0b0000010
#define INTERRUPT   0b0000100
#define DECIMAL 0b0001000
#define BREAK 0b00010000
#define OVERFLOW    0b0100000
#define NEGATIVE 0b1000000

// Addressing modes
#define IMM 0b00000000 
#define ZP 0b00000100 
#define A 0b00001000 
#define ABS 0b00001100 
#define ZPX 0b00010100 
#define AX 0b00011100 

namespace CPU {


// Flag 
byte flag = 0b00000000

// Registers
byte A = 0;
byte X = 0;
byte Y = 0;

byte P = 0;
byte SP = 0;
unint16_t PC = 0;

void ControlOperations(byte opcode) {

}



void ALUOperations(byte opcode, byte operand) {
  // Determine the addressing mode of the operation

  byte val = 0;
  // TODO(oscar): These values need to be fleshed out.
  switch (opcode && 0b000111000) {
    case IMM:
      val = operand;
    case ZP:
      val = M[operand];
    case ZPX:
      val = M[operand + X_]; 
    case A:
      val = M[operand] // This should be 16 bits...
  }


  switch(opcode) {
    case ORA:
      A = A | val;
      flag = flag | (ZERO & (A == val));
    case AND:
      A = A | val;
    case EOR:
      A = A ^ val;
    case ADC:
      A = A + val + (flag & CARRY);
    case STA:
      M[val] = A
    case LDA:
      M[val] = A;
      flag = flag | (ZERO & (A == 0));
    case CMP:
      flag = flag | (CARRY & (A >= val));
      flag = flag | (ZERO & (A == val));
    case SBC:
      A = A - val - (1 - (FLAG & CARRY));
      flag = flag | (CARRY & (A >= val));
    }
}

void RMWOperations(byte opcode) {
  byte val = 0;
  switch (opcode && 0b000111000) {
    case IMM:
      val = operand;
    case ZP:
      val = M[operand];
    case ZPX:
      val = M[operand + X_]; 
    case A:
      val = M[operand] // This should be 16 bits...
  }

  switch (opcode) {
    case ASL:
    case ROL:
    case LSR:
    case ROR:
    case STX:
    case LDX:
    case DECIN:
  }
}

// IllegalOperations contains all unofficial opearatiosn not officially supported by the 6502 instruction set.
void IllegalOperations(byte opcode) {

}

} // namespace CPU