#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS

#include <llvm/Pass.h>
#include <llvm/ADT/SmallVector.h>
//#include <llvm/Analysis/Verifier.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/InlineAsm.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/MathExtras.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <algorithm>
using namespace llvm;

Module* makeLLVMModule();

int main(int argc, char**argv) {
  Module* Mod = makeLLVMModule();
//  verifyModule(*Mod, PrintMessageAction);
//  PassManager PM;
//  PM.add(createPrintModulePass(&outs()));
//  PM.run(*Mod);
  return 0;
}


Module* makeLLVMModule() {
 // Module Construction
 char output_filename[512];
 snprintf(output_filename, 500, "test0b.bc");

 Module* mod = new Module(output_filename, getGlobalContext());
 mod->setDataLayout("");
 mod->setTargetTriple("x86_64-pc-linux-gnu");
 // Type Definitions
 std::vector<Type*>FuncTy_0_args;
 PointerType* PointerTy_1 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);
 
 FuncTy_0_args.push_back(PointerTy_1);
 FunctionType* FuncTy_0 = FunctionType::get(
  /*Result=*/IntegerType::get(mod->getContext(), 32),
  /*Params=*/FuncTy_0_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_2 = PointerType::get(PointerTy_1, 0);
 
 
 // Function Declarations
 
 Function* func_test0 = mod->getFunction("test0");
 if (!func_test0) {
 func_test0 = Function::Create(
  /*Type=*/FuncTy_0,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"test0", mod); 
 func_test0->setCallingConv(CallingConv::C);
 }
 AttributeSet func_test0_PAL;
 {
  SmallVector<AttributeSet, 4> Attrs;
  AttributeSet PAS;
   {
    AttrBuilder B;
    B.addAttribute(Attribute::NoUnwind);
    B.addAttribute(Attribute::UWTable);
    PAS = AttributeSet::get(mod->getContext(), ~0U, B);
   }
  
  Attrs.push_back(PAS);
  func_test0_PAL = AttributeSet::get(mod->getContext(), Attrs);
  
 }
 func_test0->setAttributes(func_test0_PAL);
 
 // Global Variable Declarations

 
 // Constant Definitions
 ConstantInt* const_int32_3 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
 
 // Global Variable Definitions
 
 // Function Definitions
 
 // Function: test0 (func_test0)
 {
  Function::arg_iterator args = func_test0->arg_begin();
  Value* ptr_fred = &*args;
  args++;
  ptr_fred->setName("fred");
  
  BasicBlock* label_4 = BasicBlock::Create(mod->getContext(), "",func_test0,0);
  
  // Block  (label_4)
  AllocaInst* ptr_5 = new AllocaInst(PointerTy_1, "", label_4);
  ptr_5->setAlignment(8);
  AllocaInst* ptr_fred1 = new AllocaInst(IntegerType::get(mod->getContext(), 32), "fred1", label_4);
  ptr_fred1->setAlignment(4);
  AllocaInst* ptr_fred2 = new AllocaInst(PointerTy_1, "fred2", label_4);
  ptr_fred2->setAlignment(8);
  LoadInst* int32_15 = new LoadInst(ptr_fred1, "", false, label_4);
  int32_15->setAlignment(4);
  ReturnInst::Create(mod->getContext(), int32_15, label_4);
  std::string ErrorInfo;
  std::error_code error_code;
  //raw_fd_ostream OS(output_filename, error_code, 0);
  raw_fd_ostream OS(output_filename, error_code, sys::fs::OpenFlags::F_None);

  if (error_code) {
  // *ErrorMessage = strdup(error_code.message().c_str());
    return 0;
  }
  WriteBitcodeToFile(mod, OS);
 
 }
 
 return mod;
}
