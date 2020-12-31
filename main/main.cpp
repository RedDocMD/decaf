#include "DecafBaseVisitor.h"
#include "DecafLexer.h"
#include "DecafParser.h"
#include "antlr4-runtime.h"

#include <iostream>

using namespace std;
using namespace grammar;

class MyVisitor : public DecafBaseVisitor {
  antlrcpp::Any
  visitMethod_decl(DecafParser::Method_declContext *ctx) override {
    auto name = ctx->ID()->getText();
    cout << name << "\n";
    return antlrcpp::Any();
  }
};

int main(int, char **) {
  ifstream stream{};
  auto filename = "/home/deep/work/compiler/p3files/codegen/16-qsort.dcf";
  stream.open(filename);
  antlr4::ANTLRInputStream input{stream};
  DecafLexer lexer{&input};
  antlr4::CommonTokenStream tokens{&lexer};
  DecafParser parser{&tokens};

  auto tree = parser.program();
  MyVisitor visitor{};
  visitor.visit(tree);
}
