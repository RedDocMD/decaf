#include <memory>
#include <string>

#include "ast/ast.hpp"
#include "gtest/gtest.h"

using namespace ast;
using std::make_unique;

TEST(ExprToTest, SimpleBinExpr) {
  auto expr =
      ASTBinOpExpr(make_unique<ASTIntLitExpr>(ASTIntLitExpr(10)),
                   make_unique<ASTIntLitExpr>(ASTIntLitExpr(20)), BinOp::ADD);
  auto expected_string = std::string("(10 + 20)");
  auto obtained_string = expr.to_string();
  ASSERT_EQ(expected_string, obtained_string);
}