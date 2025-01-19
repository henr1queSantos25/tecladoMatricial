# Atividade 1: Teclado Matricial EmbarcaTech👨🏻‍💻

Este repositório contém o código e a documentação e video da **Atividade 1 Controle de pinos GPIO com o
emprego de um teclado matricial**. Amplamente utilizados em sistemas embarcados e aplicações como automação, interfaces homem-máquina e dispositivos eletrônicos.
## 📹 video do Projeto
- **[Ver Video](https://drive.google.com/file/d/1cnQETIMx6UbuKRw7zj2zeR4Z1mioxkMB/view?usp=sharing)**

## 🎯 Objetivo

- Demonstrar como configurar e utilizar um **Teclado matricial e Componentes Buzzers** em microcontroladores.
- Fornecer exemplos práticos e reutilizáveis para projetos eletrônicos.
- Facilitar a integração de teclados matriciais em sistemas embarcados.
- Concluir Atividade 1 obrigatória do EmbarcaTech👨🏻‍💻

## 🛠️ Tecnologias Utilizadas

- **Linguagem de Programação**: C.
- **Placas Microcontroladoras**:
  - BitDogLab.
  - Rasberry Pico w.
- **Bibliotecas**:
  - `<stdio.h>`.
- **Ferramentas de Testes**:
  - Wokwi

## 🗂️ Estrutura do Repositório

- `tecladoMatricial.c/`: Código-fonte do projeto.
- `diagram.json/`: Simulação detalhadas sobre o funcionamento do teclado matricial, e Esquemas elétricos e diagramas de conexão.
- `README.md/`: Documentação do projeto.

## ⚙️ Funcionamento do Projeto

Um teclado matricial é composto por um arranjo de linhas e colunas que permite detectar qual tecla foi pressionada. Quando uma tecla é pressionada, ela conecta uma linha a uma coluna, permitindo que o microcontrolador identifique o evento.


## 🚀 Como Utilizar

1. Clone o repositório:
   ```bash
   git clone https://github.com/henr1queSantos25/tecladoMatricial.git
   cd tecladoMatricial
2. Configure o hardware:
-  Conecte o teclado matricial ao microcontrolador utilizando as portas GPIO.
- Consulte o esquema de pinos da sua placa.
- Faça a build e faça o upload do arquivo `.UF2` para o microcontrolador.

- Caso esteja usando Arduino, abra o arquivo no IDE e carregue no dispositivo.
Para outras plataformas, consulte as instruções no diretório docs/.

3. Teste o teclado:
- Observe no terminal serial ou display conectado o reconhecimento das teclas pressionadas.

## ✨ Funcionalidades

- Detecção precisa de teclas pressionadas.
- Facilidade de configuração com exemplos práticos.
- Compatibilidade com diversos microcontroladores.
- Toque do buzzer ao apertar `*` e `#`.
## 🔧 Exemplos Disponíveis
- Leitura básica de teclas (4x4).
- Implementação de senhas utilizando o teclado.
- Controle de LEDs baseado em entradas do teclado.
- Toque de Buzzers.


## 💡 Desenvolvido com dedicação por:
- **[Henrique Santos.](https://github.com/henr1queSantos25)**
- **[Erickson Moura.](https://github.com/ericksonsmoura)**
- **[Nicassio Santos.](https://github.com/nicassiosantos)**
- **[Everton Espedito.](https://github.com/EvertonEspedito)**
- **[MarcusVMFF.](https://github.com/MarcusVMFF)**
- **[João Pasip.](https://github.com/joao-pasip)**
- **[Osaná Thiago.](https://github.com/OsanaThiago)**
