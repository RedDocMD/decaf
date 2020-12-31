#pragma once

#include <memory>
#include <string>

namespace ast {
// Virtual base class for all AST Nodes
class ASTNode {
 public:
  virtual ~ASTNode() {}
  virtual std::string to_string() const = 0;
};

// Represents the types in Decaf
enum class Type {
  INT,
  BOOL,
  VOID,
  ERROR  // If there is an error in type deduction
};
std::string to_string(Type type);

// Virtual base class for expressions
class ASTExpr : public ASTNode {
 public:
  virtual ~ASTExpr() {}
  virtual std::string to_string() const = 0;
};

// An integer constant
class ASTIntLitExpr : public ASTExpr {
 public:
  ASTIntLitExpr(int lit) : lit{lit} {}
  ~ASTIntLitExpr() {}
  std::string to_string() const override { return std::to_string(lit); }

 private:
  int lit;
};

// A boolean constant
class ASTBoolLitExpr : public ASTExpr {
 public:
  ASTBoolLitExpr(bool lit) : lit{lit} {}
  ~ASTBoolLitExpr() {}
  std::string to_string() const override { return std::to_string(lit); }

 private:
  bool lit;
};

// Types of binary operations
enum class BinOp {
  ADD,
  SUB,
  MULT,
  DIV,
  MOD,
  LESS,
  MORE,
  LESS_EQ,
  MORE_EQ,
  EQ,
  NOT_EQ,
  AND,
  OR
};
std::string to_string(BinOp op);

// A binary-operation expression
class ASTBinOpExpr : public ASTExpr {
 public:
  ASTBinOpExpr(std::unique_ptr<ASTExpr> left, std::unique_ptr<ASTExpr> right,
               BinOp op)
      : left{std::move(left)}, right{std::move(right)}, op{op} {}
  ~ASTBinOpExpr() {}
  std::string to_string() const override;

 private:
  std::unique_ptr<ASTExpr> left;
  std::unique_ptr<ASTExpr> right;
  BinOp op;
};

}  // namespace ast