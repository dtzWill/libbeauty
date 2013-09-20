
#include <stdio.h>
#include <llvm-c/Disassembler.h>

#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCDisassembler.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/MemoryObject.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/Debug.h"

#include "X86BaseInfo.h"
#include "decode_inst_disasm.h"
#include "decode_inst.h"
#include "opcodes.h"


namespace llvm {

class DecodeAsmX86_64 {
public:

DecodeAsmX86_64() {}

~DecodeAsmX86_64();

int DecodeAsmInstruction(uint8_t *Bytes,
	uint64_t BytesSize, uint64_t PC,
	struct instruction_low_level_s *ll_inst);

int setup();

private:
LLVMDisasmContext *DC;
const llvm::Target *TheTarget;
void *DisInfo;
// memory object;
MCInst Inst;
const char *TripleName;

protected:


};

} // namespace llvm