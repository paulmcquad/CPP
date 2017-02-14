// Example 11-3: Expanding macros.
#define x             x.y
#define STR(x)        #x
#define XSTR(s)       STR(s)
#define CONCAT(x, y)  x ## y
#define PARENS(x)     (x)
#define APPLY(x,y)    x(y)
#define hello         HI

x                                       //  x.y
CONCAT(ST, R)(hello)                    //  "hello"
CONCAT(X,STR)(hello)                    //  "HI"
CONCAT(S, TR)PARENS(hello)              //  STR(HI)
CONCAT(S, TR)(PARENS(hello))            //  "PARENS(hello)"
APPLY(CONCAT(S, TR), hello)             //  "HI"
