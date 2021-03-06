#ifndef __LEXER_H__
#define __LEXER_H__

#include <queue>

#include "input.h"

namespace scheme
{
    namespace lexer
    {
        enum class token_kind
        {
            TK_ID,
            TK_CHAR,
            TK_BOOL,
            TK_STRING,
            TK_REAL,
            TK_NUMBER,      
            TK_LPAREN,      // (
            TK_RPAREN,      // )
            //TK_QUOTE,       // '
            TK_KEYWORD,
            TK_END,
        };

        enum class token_value
        {
            TV_VAR,

            // bool
            TV_FALSE,
            TV_TRUE,

            // keyword
            TV_IF,          // if
            TV_LAMBDA,      // lambda
            TV_SET,         // set!
            TV_BEGIN,       // begin 
            //TV_LET,         // let 
            TV_DEFINE,      // define 
        };

        struct token
        {
            token_kind kind;
            token_value val;
            unsigned int line, col;
            union {
                char c;
                int num;
                float fnum;
                struct {
                    const char *str;
                    int len;
                } string;
            } value;
        };

        void init_keywords();

        class lexer
        {
        public:
            lexer(input &i) : in(i), line(0), col(0) { init_keywords(); }

            token peek(int index);
            token get();

        protected:
            token make_token(token_kind k);
            token make_token(char c);
            token make_token(bool s);
            token make_token(const char *str, int len = 1);
            token make_token(int num);
            token make_token(float fnum);

            token get_char();
            token get_next();
            token get_identifier(char ch);
            token get_peculiar_identifier(char ch);
            token get_number(char ch);
            token get_pound_special();
            token get_string();

            bool is_delimiter(char ch);
            bool is_initial(char ch);
            bool is_special_initial(char ch);
            bool is_subsequent(char ch);

            int to_number(char ch);
            int get_real(int radix, char &ch);

            void skip_comment(void);
        protected:
            input &in;

            std::queue<token> token_pool;

            int line;
            int col;
        };
    }
}

#endif // __LEXER_H__
