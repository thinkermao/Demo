#include <exception>
#include <sstream>

#include "inputfile.h"
namespace scheme
{
    namespace lexer
    {
        input_file::input_file(const char * file)
        {
            this->file.open(file, std::fstream::in);
            if (!this->file)
            {
                std::stringstream str;
                str << "���ļ�" << file << "ʧ�ܣ�";
                throw std::runtime_error(str.str());
            }
        }
        input_file::~input_file()
        {
            file.close();
        }
        int input_file::getc()
        {
            char c = 0;
            if (file.get(c))
            {
                return c;
            }
            else
            {
                return -1;
            }
        }
        void input_file::ungetc(int c)
        {
            file.unget();
        }
    }
}
