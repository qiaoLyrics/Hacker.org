%{
   int yywrap() ; 
%}

number   [0-9]+
id       [a-zA-Z]+

%%
{number}        { printf("%s\n", yytext); }
{id}            { printf("%s\n", yytext); }
[\’\-\—\“\”\:\;\'\`\"?\ ,\n.]        {                           }
%%

int yywrap() { return 1 ; }
int main() {
    yylex();
    return 0;
}
