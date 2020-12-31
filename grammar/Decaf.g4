grammar Decaf;
import DecafTokens;

program :  TK_CLASS ID LCURLY field_decl* method_decl* RCURLY;

field_decl : type field_name (COMMA field_name)* SEMICOLON;
field_name : ID | ID LSQUARE NUMBER RSQUARE;
type : TK_BOOLEAN | TK_INT;

method_decl : (type | TK_VOID) ID LPAREN arglist? RPAREN block;
arglist : arg (COMMA arg)*;
arg : type ID;

block : LCURLY var_decl* statement* RCURLY;
var_decl : type ID (COMMA ID)* SEMICOLON;

statement : location assign_op expr SEMICOLON  #AssignStmt
            | method_call SEMICOLON  #MethodCallStmt
            | TK_IF LPAREN expr RPAREN block (TK_ELSE block)?  #IfStmt
            | TK_FOR ID '=' expr COMMA expr block  #ForStmt
            | TK_RETURN expr? SEMICOLON  #ReturnStmt
            | TK_BREAK  SEMICOLON  #BreakStmt
            | TK_CONTINUE SEMICOLON  #ContinueStmt
            | block  #BlockStmt
            ;

assign_op : '=' | '+=' | '-=';

method_call : method_name LPAREN expr_list? RPAREN  #SimpleMethodCall
              | TK_CALLOUT LPAREN STRING (COMMA callout_list)? RPAREN  #CalloutMethodCall
              ;
method_name : ID;

location : ID  #IdLocation
          | ID LSQUARE expr RSQUARE  #ArrayLocation
          ;

expr : location   #LocationExpr
      | method_call  #MethodCallExpr
      | literal  #LiteralExpr
      | '-' expr  #NegExpr
      | '!' expr  #NotExpr
      | expr op=('*' | '/' | '%') expr  #MultGrpExpr
      | expr op=('+' | '-') expr  #AddGrpExpr
      | expr op=('<' | '>' | '<=' | '>=') expr  #CmpExpr
      | expr op=('==' | '!=') expr  #EqOpExpr
      | expr '&&' expr  #AndExpr
      | expr '||' expr  #OrExpr
      | LPAREN expr RPAREN  #ParenExpr
      ;

callout_list : callout_arg (COMMA callout_arg)*;
callout_arg : expr | STRING;
expr_list : expr (COMMA expr)*;
literal : NUMBER | CHAR | BOOL;