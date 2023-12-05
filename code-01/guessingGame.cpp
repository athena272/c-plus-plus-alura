#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Apresenta uma mensagem de boas-vindas ao jogo
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
    cout << "**************************************" << endl;

    // Solicita ao jogador que escolha o nível de dificuldade
    cout << "Escolha o seu nível de dificuldade:" << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

    // Armazena o nível de dificuldade escolhido pelo jogador
    char dificuldade;
    cin >> dificuldade;
    cout << "A dificuldade escolhida foi: "<< dificuldade << endl;

    // Determina o número máximo de tentativas com base no nível de dificuldade
    int numero_de_tentativas;
    if (dificuldade == 'F')
    {
        numero_de_tentativas = 15;
    }
    else if (dificuldade == 'M')
    {
        numero_de_tentativas = 10;
    }
    else
    {
        numero_de_tentativas = 5;
    }

    // Gera um número aleatório entre 0 e 99 para ser o número secreto
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    // Inicializa variáveis para controle do jogo
    bool nao_acertou = true;
    int tentativas = 0;
    double pontos = 1000.0;

    // Inicia um loop que representa as tentativas do jogador
    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++)
    {
        // Solicita ao jogador que faça um chute
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        // Calcula os pontos perdidos com base na diferença entre o chute e o número secreto
        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos -= pontos_perdidos;

        // Exibe o valor do chute do jogador
        cout << "O valor do seu chute é: " << chute << endl;

        // Verifica se o chute é igual, maior ou menor que o número secreto
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        // Exibe mensagens de feedback ao jogador
        if (acertou)
        {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o número secreto!" << endl;
        }
    }

    // Exibe mensagem de fim de jogo e resultado
    cout << "Fim de jogo!" << endl;
    if (nao_acertou)
    {
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
    }
}
