#include <iostream>
namespace Cadastro
{

class Cliente
{
    private:
        std::string nome = "";
        std::string email = "";
    
    public:
    Cliente( std::string nomep, std::string emailp )
    {
        nome = nomep;
        email = emailp;
    }

    std::string imprimir()
    {
        std::cout << nome << ", " << email << std::endl;

        return nome + " / " + email;
    }
};

}
