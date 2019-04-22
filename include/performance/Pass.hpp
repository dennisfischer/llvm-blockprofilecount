#ifndef FUNCTIONFILTER_FILTER_HPP
#define FUNCTIONFILTER_FILTER_HPP

#include <llvm/IR/Module.h>
#include <llvm/Pass.h>

class PerformanceTestPass : public llvm::ModulePass {
public:
  static char ID;

public:
  PerformanceTestPass() : llvm::ModulePass(ID) {}

public:
  bool runOnModule(llvm::Module& M) override;
  virtual void getAnalysisUsage(llvm::AnalysisUsage& AU) const override;
};

#endif // FUNCTIONFILTER_FILTER_HPP