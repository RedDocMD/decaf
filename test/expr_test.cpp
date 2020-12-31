#include <memory>
#include <string>

#include "ast/ast.hpp"
#include "gtest/gtest.h"

using namespace ast;
using namespace std;

TEST(ExprToString, SimpleBinExpr) {
  ASTBinOpExpr expr(make_unique<ASTIntLitExpr>(10),
                    make_unique<ASTIntLitExpr>(20), BinOp::ADD);
  string expected_string("(10 + 20)");
  auto obtained_string = expr.to_string();
  ASSERT_EQ(expected_string, obtained_string);
}

TEST(ExprToString, SlightlyComplexExpr) {
  ASTBinOpExpr expr(
      make_unique<ASTBinOpExpr>(make_unique<ASTIntLitExpr>(10),
                                make_unique<ASTIntLitExpr>(20), BinOp::DIV),
      make_unique<ASTBinOpExpr>(make_unique<ASTIntLitExpr>(134),
                                make_unique<ASTIntLitExpr>(69), BinOp::SUB),
      BinOp::MULT);
  string expected_string("((10 / 20) * (134 - 69))");
  auto obtained_string = expr.to_string();
  ASSERT_EQ(expected_string, obtained_string);
}