%{
#include<stdio.h>
int col=1, line=1;
void print_out(char* type);
%}

/*正则表达式定义PASCAL语言的类型*/

digit       [0-9]
letter      [a-zA-Z]
identifier  ({letter}|_)({letter}|{digit})*

/*基本类型定义*/
integer     {digit}+
real        -?{digit}+(\.{digit}+)?([Ee][-+][0-9]+)?
char        (\'.{1,}\')
boolean     false|true
annotation  (\{\*[.\n]*\*\})|(\{[.]*\})

string      (\".{1,}\")
blank       [ ]
newLine     [\n]
return_     [\r]
tab         [\t]
illegal     ([^a-zA-Z1-9\t\n>=<:\'\(\)\;\[\]\.\!\+\-\/\*\"\, ]+)|(\'.{2,}\')

/*PASCAL语言的55个关键字*/
keyword     and|array|begin|case|const|div|do|downto|else|end|external|extern|file|for|forward|function|goto|if|in|label|mod|nil|not|of|or|otherwise|packed|procedure|program|record|repeat|set|then|to|type|until|var|while|with|exports|shr|string|asm|object|unit|constructor|implementation|destructor|uses|inherited|inline|interface|library|xor|shl

%%  /*模式匹配规则*/
{keyword}    {print_out("Keyword");col = col + yyleng;}   /*关键字*/
{boolean}    {print_out("Boolean"); col = col + yyleng;}
{blank}      {col = col + yyleng;}   /*空格*/
{newLine}    {line += 1; col = 1;}   /*换行*/
{return_}    {col = 1;}              /*\r返回当前行第一列*/
{tab}        {col += 8;}             /*制表符列加8*/

{integer}|{real} {
	if(yyleng > 14)     /*检查长度*/
	{
		printf("Error! The length of this number is too long!\n");
		exit(0);
	}
	print_out("Constant"); col = col + yyleng;
}
{char} {
	if(yyleng > 3){     /*char类型  长度为3*/
		printf("The length of char must be 1.");
		exit(0);
	}
	print_out("Char"); col = col + yyleng;
}
{identifier} {
	if(yyleng > 10){    /*检查长度是否超出范围*/
		printf("Error! The length of this idetifier is too long!\n");
		exit(0);
	}
	print_out("Identifier");   col = col + yyleng;
}

{string}      {print_out("String"); col = col + yyleng;}
{annotation}  {print_out("Annotation"); col = col + yyleng;}

"+"|"-"|"*"|"/"|"#"|"<"|">"|"="|"<>"|"!="|">="|"<="|":="	{print_out("Operator"); col = col + yyleng;} /*算符*/
"\["|"("|")"|","|":"|";"|"."|"\]"|".."		                {print_out("Delimiter");col = col + yyleng;} /*界符*/

{illegal} {
	/*含有非法字符的字符串*/
	/*数字开头的identifier*/
	/*real里是错误类型*/
	printf("This word is incorrect! ");
	print_out("Illegal");
}

%%
int yywrap(){
    return 1;
}

void print_out(char* type)
{
     printf("%s : %s, (%d,%d)\n",yytext,type,line,col);
}

int main(int argc,char** argv)
{
    FILE * fIn;
	switch(argc)
	{
	case 1: 			//打开缺省文件
		fIn=fopen("input.txt","r");
		if(fIn==NULL){
			printf("default file is not found\n");
			exit(1);
		}
		else	yyin = fIn;
		break;
	case 2: 			//打开指定文件
		if ((fIn = fopen(argv[1],"r")) == NULL) {
	            printf("File %s is not found.\n",argv[1]);
	            exit(1);
	        }
	        else	yyin=fIn;
		break;
	default:
		printf("useage:flex [filename]\n");
		exit(1);
	}
    yylex();

	fclose(fIn);
	return 0;
}