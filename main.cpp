/*
logar.cpp

aplicação grava log de mensagens

getArquivo, retorna o nome do contexto com timestamp e randomico adicionado

logar, grava a mensagem, usar getArquivo para estabelecer o nome do arquivo padronizado.

*/
#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include "logar.cpp"
#include "cliente.cpp"
#include <jsoncpp/json/json.h>
#include <array>


int main( int argc, char** argv )
{
    Logar logar("logdeteste");
    logar.escrever("inicio");
    if( argc > 1 )
    {
      for( int i=1;i<argc;i++)
      {
        logar.escrever( argv[i] );
      }

    }

    std::vector<Cadastro::Cliente> lista = {};

    for (int i = 0; i < 2; i++)
    {
      Cadastro::Cliente cliente("luis " + std::to_string( i ) ,"lbortoletti@gmail.com");
      lista.push_back( cliente );
      logar.escrever("Novo cliente");
    }

    for( auto item : lista)
    {
      std::cout << item.imprimir() << std::endl;
    }
    int config_itens = 0;

    std::string nomeConfig = argv[1];
    nomeConfig.append(".json");
    std::ifstream ifs( nomeConfig );
    Json::Reader reader;
    Json::Value obj;
    reader.parse( ifs, obj );
    if( obj.empty() )
    {
      logar.escrever("parametro invalido");
    }
    if( ! obj.empty() )
    {
      config_itens = obj.get("itens",0).asInt();
      std::string mensagem = "";
      std::string nomep = obj.get("nome","teste" ).asString();
      std::string localEndereco = obj.get("enderecos","teste" )[0].get("local","").asString();
      mensagem.append( "Nome: ");
      mensagem.append(  nomep );
      logar.escrever( mensagem );
      mensagem = "";
      mensagem.append( "Local: ");
      mensagem.append(  localEndereco );
      logar.escrever( mensagem );      
    }

    std::ifstream ifsclientes ( "listacliente.json" );
    Json::Reader reader2;
    Json::Value clientesLista;
    reader.parse( ifsclientes, clientesLista );
    if( ! clientesLista.empty() )
    {
      for( int i=0;i< config_itens ;i++)
      {
        std::string nome = clientesLista[i].get("nome","").asString();
        if( nome.empty() )
        {
          break;
        }
        std::cout << nome << std::endl;
      }
      // exibir a lista de acordo com o tamanho da mesma.
      int contador = 0;
      while( ! clientesLista[contador].get("nome","").asString().empty()  )
      {
          std::string nome = clientesLista[contador].get("nome","").asString();
          std::string email = clientesLista[contador].get("email","").asString();
          std::cout << nome << "/" << email << std::endl;
          contador++;
      }

    }


    logar.escrever("** fim " );
    return 0;
}

