
#include "control.h"

/**
 * \c control module callback function.
 */
void control::entry()
{
  switch(opcode.read()) {
    case 0: // R-format
    	Jump.write(0);
		JumpOnRegister.write(0);
		BranchNotEqual.write(1);
       	RegDst.write(1);  
        ALUSrc.write(0);
	    MemtoReg.write(0);
	    RegWrite.write(1);
	    MemRead.write(0);
	    MemWrite.write(0);
	    Branch.write(0);

	    switch(funct.read()) {
	    	case  8: // jr
					Jump.write(1);
					JumpOnRegister.write(1);
					RegWrite.write(0);
					ALUOp.write(6);
					break;
		    case  9: // jalr
					Jump.write(1);
					JumpOnRegister.write(1);
				    ALUOp.write(6);
					break;
	       	case 32: ALUOp.write(2);
	                break;
	       	case 34: ALUOp.write(6);
	                break;
	       	case 36: ALUOp.write(0);
	                break;
	       	case 37: ALUOp.write(1);
	                break;
	       	case 42: ALUOp.write(7);
	                break;
		}
	    break;
	case  2: // j
		Jump.write(1);
		JumpOnRegister.write(0);
		RegWrite.write(0);

		RegDst.write(0);
		MemtoReg.write(0);
		BranchNotEqual.write(0);
		ALUSrc.write(0);
	    MemRead.write(0);
	    MemWrite.write(0);
	    Branch.write(0);
	    ALUOp.write(6);
		break;
	case  3: // jal
		Jump.write(1);
		JumpOnRegister.write(0);
		RegWrite.write(1);
		MemtoReg.write(0);

		RegDst.write(0);
		BranchNotEqual.write(0);
		ALUSrc.write(0);
	    MemRead.write(0);
	    MemWrite.write(0);
	    Branch.write(0);
	    ALUOp.write(6);
	    break;
	case  4: // beq
    	Jump.write(0);
		JumpOnRegister.write(0);

		RegDst.write(0);
		MemtoReg.write(0);
		BranchNotEqual.write(0);
        ALUSrc.write(0);
	    RegWrite.write(0);
	    MemRead.write(0);
	    MemWrite.write(0);
	    Branch.write(1);
	    ALUOp.write(6);
	    break;
    case  5: // bne
		Jump.write(0);
		JumpOnRegister.write(0);

		RegDst.write(0);
		MemtoReg.write(0);
		BranchNotEqual.write(1);
        ALUSrc.write(0);
	    RegWrite.write(0);
	    MemRead.write(0);
	    MemWrite.write(0);
	    Branch.write(1);
	    ALUOp.write(6);
	    break;
    case 35: // lw
    	Jump.write(0);
		JumpOnRegister.write(0);

		BranchNotEqual.write(1);

        RegDst.write(0); 
        ALUSrc.write(1);
	    MemtoReg.write(1);
	    RegWrite.write(1);
	    MemRead.write(1);
	    MemWrite.write(0);
	    Branch.write(0);
	    ALUOp.write(2);
	    break;
    case 43: // sw
        Jump.write(0);
		JumpOnRegister.write(0);

		BranchNotEqual.write(1);
		RegDst.write(0);
		MemtoReg.write(0);
        ALUSrc.write(1);
	    RegWrite.write(0);
	    MemRead.write(0);
	    MemWrite.write(1);
	    Branch.write(0);
	    ALUOp.write(2);
	    break;
   default: // Unknown opcode
        fprintf(stderr,"ERROR: Illegal opcode\n");
	    //assert(0);
	    break;
    }
}
