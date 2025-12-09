grammar miniCPP;

translationUnit
    : (functionDecl)* EOF
    ;

functionDecl
    : type ID '(' ')' '{' '}'
    ;

type
    : 'int'
    | 'float'
    | 'void'
    ;

ID  : [a-zA-Z_][a-zA-Z0-9_]* ;
WS  : [ \t\r\n]+ -> skip ;