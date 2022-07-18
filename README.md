# Arkanoid Game

Durante o desenvolvimento deste jogo, procurei basear-me ao máximo na documentação da API SFML, utilizando aulas apenas em pontos mais complexos.

## Instalação do SFML e configuração do Visual Studio Community
A instalação e configuração da API está descrita em detalhes em Learn -> Tutorials.

Há também informações sobre a configuração no Code::Blocks, Linux, Xcode e CMake.

### Tutorial rápido de configuração

- Criar um diretório API_SFML, fazer o download do SFML para Visual Studio (utilizei Visual C++ 15 (2017) - 32-bit);
- Descompactar o arquivo no diretório criado e renomeá-lo para SFML (irá facilitar mais adiante);
- Abrir o Visual Studio, criar um novo projeto (chamei de ArkanoidGame) e salvar no diretório API_SFML criado anteriormente;
- Criar um arquivo main.cpp
- Abrir as propriedades do projeto em Project, Properties;
- Em Configuration, selecionar All Configurations;
- Em Platform, Active(Win32);
- Clicar em C/C++, General, Additional Include Directories, Edit, clicar em New Line, inserir ``` $(SolutionDir)..\SFML\include ```, Ok e Apply;
- Clicar em Linker, Additionoal Library Directories, Edit, clicar New Line, inserir ``` $(SolutionDir)..\SFML\lib ```, Ok e Apply;
- Em Configuration, selecionar Release;
- Clicar em Linker, Input, Additional Dependencies e Edit;
- Adicionar:
```
sfml-graphics.lib

sfml-system.lib

sfml-network.lib

sfml-window.lib

sfml-audio.lib
```
- Clicar em Ok e Aplicar;
- Em Configuration, selecionar Debug;
- Clicar em Linker, Input, Additional Dependencies e Edit;
- Adicionar:
```
sfml-graphics-d.lib

sfml-system-d.lib

sfml-network-d.lib

sfml-window-d.lib

sfml-audio-d.lib
```
- Clicar em Ok e Aplicar;
- No diretório SFML, localizado em API_SFML, copiar todos os arquivos .dll do diretório bin ;
- Colar os arquivos dentro do diretório ArkanoidGame;
- Copiar o código fonte do arquivo testeSFML.txt ou direto do site da API no main.cpp;
- Compilar e executar (Ctrl + F5);
- Se tudo estiver correto irá aparecer a imagem abaixo.






## Distribuição do Jogo
Criar um diretório e copiar:
- arquivos DLL;
- pasta arkanoid;
- arquivo executável.
