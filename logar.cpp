/*
logar.cpp

aplicação grava log de mensagens

getArquivo, retorna o nome do contexto com timestamp e randomico adicionado

logar, grava a mensagem, usar getArquivo para estabelecer o nome do arquivo padronizado.

*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

class Logar
{
    private:
        std::string arquivo;

    std::string getTimestamp()
    {
        std::string retorno;
        time_t agora;
        time( &agora );
        struct tm* timeinfo;
        timeinfo = localtime( &agora );

        char tmpv [80];
        strftime( tmpv, 80, "%Y%m%d-%H%M%S", timeinfo );
        retorno = tmpv;
        return retorno;
    }

    std::string getRandomico()
    {
        std::string retorno;
        char tmpv [80];
        srand (time(NULL));
        sprintf( tmpv, "%d", rand() );
        retorno = tmpv;
        return retorno;
    }

    public:
    Logar( std::string arquivop )
    {
        arquivo = "./logs/";
        arquivo += getTimestamp();
        arquivo += "-" + arquivop;
        arquivo += "-" + getRandomico();
        arquivo += ".log";    
    }

    int escrever( std::string mensagem )
    {
        std::ofstream arq( arquivo, std::ofstream::app );
        arq << std::endl << getTimestamp() << ":" << mensagem ;
        arq.close();
    }


};
