//
//  ops.h
//  plassemble
//
//  Created by Noah Wooten on 2/6/22.
//

#ifndef ops_h
#define ops_h

enum {
	__SET = 0x00, // Set Register (SET [R:(4,4),DEST] [R:(4,4),SRC]):16
	__LDWM = 0x01, // Load Register Word from Memory (LDWM [R:(4,4),DEST] [R:(4,4),SRC_PTR]):16
	__STWM = 0x02, // Store Register Word in Memory (STWM [R:(4,4),DEST] [R:(4,4),SRC_PTR]):16
	__LDBM = 0x03, // Load Register Byte from Memory (LDBM [R:(4,4),DEST] [R:(4,4),SRC_PTR]):16
	__STBM = 0x04, // Store Register Byte in Memory (STBM [R:(4,4),DEST] [R:(4,4),SRC_PTR]):16
	__OR = 0x05, // Logical OR (OR [R:(4,4),DEST] [R:(4,4),SRC]):16
	__AND = 0x06, // Logical AND (AND [R:(4,4),DEST] [R:(4,4),SRC]):16
	__XOR = 0x07, // Logical XOR (XOR [R:(4,4),DEST] [R:(4,4),SRC]):16
	__NOT = 0x08, // Logical NOT (NOT [R:(4,4),DEST] [R:(4,4),SRC]):16
	__ADD = 0x09, // Summate Registers (ADD [R:(4,4),DEST] [R:(4,4),SRC]):16
	__SUB = 0x0A, // Subtract Registers (SUB [R:(4,4),DEST] [R:(4,4),SRC]):16
	__MUL = 0x0B, // Multiply Registers (MUL [R:(4,4),DEST] [R:(4,4),SRC]):16
	__DIV = 0x0C, // Divide Registers (DIV [R:(4,4),DEST] [R:(4,4),SRC]):16
	__SETI = 0x0D, // Set Register Immediate (SETI [R:(4,8),DEST] [I:(64,64),SRC]):80
	__LDWMI = 0x0E, // Load Register Word from Memory Immediate (LDWMI [R:(4,8),DEST] [I:(64,64),SRC_PTR]):80
	__STWMI = 0x0F, // Store Register Word in Memory Immediate (STWMI [R:(4,8),DEST] [I:(64,64),SRC_PTR]):80
	__LDBMI = 0x10, // Load Register Byte from Memory Immediate (LDBMI [R:(4,8),DEST] [I:(64,64),SRC_PTR]):80
	__STBMI = 0x11, // Store Register Byte in Memory Immediate (STBMI [R:(4,8),DEST] [I:(64,64),SRC_PTR]):80
	__ORI = 0x12, // Logical OR Immediate (ORI [R:(4,8),DEST] [I:(64,64),SRC]):80
	__ANDI = 0x13, // Logical AND Immediate (ANDI [R:(4,8),DEST] [I:(64,64),SRC]):80
	__XORI = 0x14, // Logical XOR Immediate (XORI [R:(4,8),DEST] [I:(64,64),SRC]):80
	__ADDI = 0x15, // Sum Register and Immediate (ADDI [R:(4,8),DEST] [I:(64,64),SRC]):80
	__SUBI = 0x16, // Subtract Immediate from Register (SUBI [R:(4,8),DEST] [I:(64,64),SRC]):80
	__MULI = 0x17, // Multiply Register by Immediate (MULI [R:(4,8),DEST] [I:(64,64),SRC]):80
	__DIVI = 0x18, // Divide Register By Immediate (DIVI [R:(4,8),DEST] [I:(64,64),SRC]):80
	__SL = 0x19, // Shift Left (SL [R:(4,4),DEST] [R:(4,4),AMT]):16
	__SR = 0x1A, // Shift Right (SR [R:(4,4),DEST] [R:(4,4),AMT]):16
	__SLI = 0x1B, // Shift Left Immediate (SLI [R:(4,8),SRC] [I:(6,8),AMT]):24
	__SRI = 0x1C, // Shift Right Immediate (SRI [R:(4,8),SRC] [I:(6,8,AMT]):24
	__SA = 0x1D, // Stack Add (Push) (SA [R:(4,8),SRC]):16
	__SP = 0x1E, // Stack Pull (SP [R:(4,8),DEST]):16
	__SAI = 0x1F, // Stack Add (Push) Immediate (SAI [I:(64, 64)]):72
	__GO = 0x20, // Go (Jump) (GO [R:(4,8),LOCATION]):16
	__ENT = 0x21, // Enter (Call) (GO [R:(4,8),LOCATION]):16
	__RT = 0x22, // Return (RT):8
	__RTF = 0x23, // Return if Flag (RTF [R:(4,8),FLAG]):16
	__RTFI = 0x24, // Return if Flag Immediate (RTFI [I:(64,64),FLAG]):72
	__GOI = 0x25, // Go (Jump) Immediate (GOI [I:(64,64),LOCATION]):72
	__ENTI = 0x26, // Enter (Call) Immediate (ENTI [I:(64,64),LOCATION]):72
	__CMP = 0x27, // Compare Registers (CMP [R:(4,4),COMPARE0] [R:(4,4),COMPARE1]):16
	__CMPI = 0x28, // Compare Register with Immediate (CMPI [R:(4,8),COMPARE0] [I:(64,64),COMPARE1]):80
	__GOF = 0x29, // Go if Flag (GOF [R:(4,4),LOCATION] [R:(4,4),FLAG]):16
	__ENTF = 0x2A, // Enter if Flag (ENTF [R:(4,4),LOCATION] [R:(4,4),FLAG]):16
	__GOFI = 0x2B, // Go if Flag Immediate (GOFI [R:(4,8),LOCATION] [I:(64,64),FLAG]):80
	__ENTFI = 0x2C, // Enter if Flag Immediate (ENTFI [R:(4,8),LOCATION] [I:(64,64),FLAG]):80
	__GOFII = 0x2D, // Go if Flag Immediate Immediate  (GOFII [I:(64,64),LOCATION] [I:(64,64),FLAG]):136
	__ENTFII = 0x2E, // Enter if Flag Immediate Immediate (ENTFII [I:(64,64),LOCATION] [I:(64,64),FLAG]):136
	__NEG = 0x2F, // Signed Negate Register (NEG [R:(4,8)]):16
	__NOP = 0x30, // No Operation (NOP):8
	__EIH = 0x31, // Enable Interrupt Handling (EIH):8
	__DIH = 0x32, // Disable Interrupt Handling (DIH):8
	__HLT = 0x33, // Enter Halt State (HLT):8
	__INT = 0x34, // Call Interrupt (INT [R:(4,8),INTERRUPT]):8
	__INTI = 0x35, // Call Interrupt Immediate (INTI [I:(8,8),INTERRUPT]):16
	__HND = 0x36, // Handle Interrupt (HND [R:(4,4),INTERRUPT] [R:(4,4),LOCATION]):16
	__HNDI = 0x37, // Handle Interrupt Immediate (HNDI [I:(8,8),INTERRUPT] [R:(4,8),LOCATION]):24
	__HNDII = 0x38, // Handle Interrupt Immediate Immediate (HNDII [I:(8,8),INTERRUPT] [I:(64,64),LOCATION]):80
	__SPA = 0x39, // Stack Pull All (SPA):8
	__SPG = 0x3A, // Stack Pull General (SPG):8
	__SAA = 0x3B, // Stack Add (Push) All (SAA):8
	__SAG = 0x3C, // Stack Add (Push) General (SAG):8
	__LDSD = 0x3D, // Load System Descriptor (LDSD [R:(4,4),PART0] [R:(4,4),PART1]):16
	__LDSDI = 0x3E, // Load System Descriptor Immediate (LDSDI [I:(64,64),PART0] [I:(64,64),PART1]):136
	__STSD = 0x3F, // Store System Descriptor to Registers (STSD [R:(4,4),PART0] [R:(4,4),PART1]):16
	__LDVM = 0x40, // Load Virtual Descriptor from Registers (LDVM [R:(4,4),PART0] [R:(4,4),PART1]):16
	__LDVMI = 0x41, // Load Virtual Descriptor from Immediates (LDVMI [I:(64,64),PART0] [I:(64,64),PART1]):136
	__STVM = 0x42, // Store Virtual Descriptor to Registers (STVM [R:(4,4),PART0] [R:(4,4),PART1]):16
	__SPN = 0x43, // Stack Pull No Operand (SPN):8
	__MSP = 0x44, // Multiply Stack Pointer (DATA is multiplied by IMM) (MSP [R:(4,4),DATA] [I:(20,20),IMM]):32
	__SSP = 0x45, // Subtract Stack Pointer (DATA is multiplied by IMM) (SSP [R:(4,4),DATA] [I:(20,20),IMM]):32
	__ASP = 0x47, // Add Stack Pointer (DATA is multiplied by IMM) (ASP [R:(4,4),DATA] [I:(20,20),IMM]):32
	__SPB = 0x48, // Stack Pull Byte (SPB [R:(4,8),DEST]):16
	__SAB = 0x49, // Stack Add Byte (SAB [R:(4,8),SRC]):16
	__SAII = 0x4A, // Stack Add Byte Immediate (SAII [I:(8,8),SRC]):16
	__INC = 0x4B, // Increment (INC [R:(4,8),SRC]):16
	__DEC = 0x4C, // Decrement (DEC [R:(4,8),SRC]):16
	__SBN = 0x4D, // Stack Pull Byte No Operand (SBN):8
	__IOB = 0x4E, // I/O Output Byte (IOB [R:(4,4),PORT] [R:(4,4),DATA]):16
	__IIB = 0x4F, // I/O Input Byte (IIB [R:(4,4),PORT] [R:(4,4),DATA]):16
	__IOW = 0x50, // I/O Output Word (IOW [R:(4,4),PORT] [R:(4,4),DATA]):16
	__IIW = 0x51, // I/O Input Word (IIW [R:(4,4),PORT] [R:(4,4),DATA]):16
	__IOS = 0x52, // I/O Output String (IOB [R:(4,4),PORT] [R:(4,4),DATA] [R:(4,8),LEN]):24
	__IIS = 0x53, // I/O Input String (IOB [R:(4,4),PORT] [R:(4,4),STR] [R:(4,8),LEN]):24
	__LDHM = 0x54, // Load Register Half-Word from Memory (LDHM [R:(4,4),DEST] [R:(4,4),SRC_PTR]):16
	__STHM = 0x55, // Store Register Half-Word in Memory (STHM [R:(4,4),DEST] [R:(4,4),SRC_PTR]):16
	__LDHMI = 0x56, // Load Immediate Half-Word from Memory (LDHM [R:(4,8),DEST] [I:(32,32),SRC]):48
	__STHMI = 0x57, // Store Immediate Half-Word in Memory (STHM [R:(4,8),DEST] [I:(32,32),SRC):48
	__LDQM = 0x58, // Load Register Quarter-Word from Memory (LDQM [R:(4,4),DEST] [R:(4,4),SRC_PTR]):16
	__STQM = 0x59, // Store Register Quarter-Word from Memory (STQM [R:(4,4),DEST] [R:(4,4),SRC_PTR]):16
	__LDQMI = 0x5A, // Load Immediate Quarter-Word from Memory (LDQM [R:(4,8),DEST] [I:(16,16),SRC]):32
	__STQMI = 0x5B, // Store Immediate Quarter-Word from Memory (STQM [R:(4,8),DEST] [I:(16,16),SRC]):32
};

#endif /* ops_h */
