lexer grammar DecafTokens;

COMMENT : '//' ~[\n]* -> skip;
WS : [ \t\n]+ -> skip;

TK_BOOLEAN : 'boolean';
TK_BREAK : 'break';
TK_CALLOUT : 'callout';
TK_CLASS : 'class';
TK_CONTINUE : 'continue';
TK_ELSE : 'else';
TK_FOR : 'for';
TK_IF : 'if';
TK_INT : 'int';
TK_RETURN : 'return';
TK_VOID : 'void';

LCURLY : '{';
RCURLY : '}';
LPAREN : '(';
RPAREN : ')';
LSQUARE : '[';
RSQUARE : ']';

BOOL : 'true' | 'false';
CHAR : '\'' (ESCAPED_CHAR | NORM_CHAR) '\'';
STRING : '"' (ESCAPED_CHAR | NORM_CHAR)* '"';
ID : ALPHA (ALPHA | DIGIT)*;
NUMBER : (DIGIT)+ | '0x' (HEX_DIGIT)+;

COMMA : ',';
SEMICOLON : ';';
DOT : '.';

BIN_OP : (ARITH_OP | REL_OP | EQ_OP | COND_OP);
ASSIGN_OP : ('=' | '+=' | '-=');
fragment ARITH_OP : [+\-*/%];
fragment REL_OP : '<' | '>' | '<=' | '>=';
fragment EQ_OP : '==' | '!=';
fragment COND_OP : '||' | '&&';

fragment ALPHA : [a-zA-Z_];
fragment DIGIT : [0-9];
fragment HEX_DIGIT : [0-9a-fA-F];
fragment NORM_CHAR : [ !#$%&\u0028-\u005B\u005D-\u007E];
fragment ESCAPED_CHAR : '\\' [nt\\'"];