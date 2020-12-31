#include "ast/ast.hpp"

#include <sstream>

namespace ast {
using namespace std;

string to_string(Type type) {
  switch (type) {
    case Type::INT:
      return "int";
    case Type::BOOL:
      return "bool";
    case Type::VOID:
      return "void";
    case Type::ERROR:
      return "<error>";
  }
  return "invalid type";
}

string to_string(BinOp op) {
  switch (op) {
    case BinOp::ADD:
      return "+";
    case BinOp::SUB:
      return "-";
    case BinOp::MULT:
      return "*";
    case BinOp::DIV:
      return "/";
    case BinOp::MOD:
      return "%";
    case BinOp::LESS:
      return "<";
    case BinOp::LESS_EQ:
      return "<=";
    case BinOp::MORE:
      return ">";
    case BinOp::MORE_EQ:
      return ">=";
    case BinOp::EQ:
      return "==";
    case BinOp::NOT_EQ:
      return "!=";
    case BinOp::AND:
      return "&&";
    case BinOp::OR:
      return "||";
  }
  return "invalid op";
}

string ASTBinOpExpr::to_string() const {
  stringstream ss;
  ss << "(" << left->to_string() << " " << ast::to_string(op) << " "
     << right->to_string() << ")";
  return ss.str();
}

}  // namespace ast