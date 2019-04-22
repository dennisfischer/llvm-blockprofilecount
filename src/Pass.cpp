#include <llvm/Analysis/BlockFrequencyInfo.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/Debug.h>
#include <llvm/Support/raw_ostream.h>
#include <performance/Pass.hpp>

char PerformanceTestPass::ID = 0;

static llvm::RegisterPass<PerformanceTestPass> X("perf-test", "Performance Test");

void PerformanceTestPass::getAnalysisUsage(llvm::AnalysisUsage& AU) const {

  AU.setPreservesAll();
  AU.addRequired<llvm::BlockFrequencyInfoWrapperPass>();
}

bool PerformanceTestPass::runOnModule(llvm::Module& M) {
  llvm::dbgs() << "Running Perf Test\n";
  for (auto& F : M) {
    if (F.isDeclaration()) {
      continue;
    }
    auto& bfiPass = getAnalysis<llvm::BlockFrequencyInfoWrapperPass>(F);
    llvm::BlockFrequencyInfo* BFI = &bfiPass.getBFI();

    BFI->print(llvm::dbgs());

    for (const llvm::BasicBlock& B : F) {
      llvm::dbgs() << BFI->getBlockProfileCount(&B).getValueOr(123456789) << "\n";
    }
  }

  return false;
}
