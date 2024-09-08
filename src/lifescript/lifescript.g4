grammar lifescript;
options { language=Cpp; }

script : (prefdef | gridstmt | abscell | absprefab)* ;
gridstmt : 'grid' IDENTIFIER ABSNUM ;
prefdef : 'def' IDENTIFIER prefelems 'end' ;
prefelems : (relcell | relprefab)* ;
relprefab : '@' IDENTIFIER relcell ;
relcell : (ABSNUM | RELNUM) (ABSNUM | RELNUM) ;
abscell : ABSNUM ABSNUM ;
absprefab : '@' IDENTIFIER abscell ;

IDENTIFIER : [a-zA-Z_][a-zA-Z0-9_]* ;
NEWLINE : ('#' .*?)? '\r'?'\n' -> skip ;
WS : (' ' | '\t') -> skip ;
RELNUM : ('+' | '-') ('0'..'9')+ ;
ABSNUM : ('0'..'9')+ ;