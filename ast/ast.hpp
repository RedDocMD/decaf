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

// A logical not expression
class ASTNotExpr : public ASTExpr {
 public:
  ASTNotExpr(std::unique_ptr<ASTExpr> expr) : expr{std::move(expr)} {}
  ~ASTNotExpr() {}
  std::string to_string() const override {
    return "!(" + expr->to_string() + ")";
  }

 private:
  std::unique_ptr<ASTExpr> expr;
};

// Negated expression
class ASTNegExpr : public ASTExpr {
 public:
  ASTNegExpr(std::unique_ptr<ASTExpr> expr) : expr{std::move(expr)} {}
  ~ASTNegExpr() {}
  std::string to_string() const override {
    return "-(" + expr->to_string() + ")";
  }

 private:
  std::unique_ptr<ASTExpr> expr;
};

// A target location (variable name or array location)
class ASTLocation : public ASTNode {
 public:
  ASTLocation(std::string name) : name{name} {}
  virtual ~ASTLocation() {}
  std::string to_string() const override = 0;
  std::string get_name() const { return name; }

 private:
  std::string name;
};

// Location indicating a non-array variable
class ASTLocVar : public ASTLocation {
 public:
  ASTLocVar(std::string name) : ASTLocation{name} {}
  ~ASTLocVar() {}
  std::string to_string() const override { return ASTLocation::get_name(); }
};

// Location indicating an array variable
class ASTLocArr : public ASTLocation {
 public:
  ASTLocArr(std::string name, std::unique_ptr<ASTExpr> loc_expr)
      : ASTLocation(name), loc_expr{std::move(loc_expr)} {}
  ~ASTLocArr() {}
  std::string to_string() const override {
    return ASTLocation::get_name() + "[" + loc_expr->to_string() + "]";
  }

 private:
  std::unique_ptr<ASTExpr> loc_expr;
};

// An expression containing a location
class ASTLocExpr : public ASTExpr {
 public:
  ASTLocExpr(std::unique_ptr<ASTLocation> loc) : loc{std::move(loc)} {}
  ~ASTLocExpr();
  std::string to_string() const override { return loc->to_string(); }

 private:
  std::unique_ptr<ASTLocation> loc;
};

}  // namespace ast