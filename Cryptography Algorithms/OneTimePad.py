import string
import random

# Variáveis globais
chave = ''
texto_criptografado = []
chave_bin = []

#=======================================================================#
#   Converte binário em string                                          #
#=======================================================================#
def bin_to_str(binario):
    binario = str(binario)
    caractere = ''
    char = ''
    tamanho = len(binario)
    k = 1
    for j in binario:
        if j != ' ':
            caractere += j
            if k == tamanho:
                char += chr(int(caractere, 2))
        else:
            char += chr(int(caractere, 2))
            caractere = ''
        k += 1        
    return char
#=======================================================================#
#   Converte string em binário                                          #
#=======================================================================#
def str_to_bin(string):
    binario = ''
    for i in string:
        binario += bin(ord(i))[2::] + ' '
    return binario
#=======================================================================#
#   Imprimir layout                                                     #
#=======================================================================#
def imprime_layout_name(name):
    print("\n+==================================================================+")
    print("  ",name,"\n+==================================================================+")
def imprime_menu():
    imprime_layout_name("ONE-TIME PAD")
    print("\n  1 - Criptografar\n  2 - Descriptografar\n  0 - Sair dos sistema\n")    
#=======================================================================#
#   Gerar chave                                                         #
#=======================================================================#
def gerador_chave(tam):
    return ''.join(random.choice(string.ascii_letters) for x in range(tam))
#=======================================================================#
#   Opções                                                              #
#=======================================================================#
def select_option(opcao):
    if opcao == 1:
        imprime_layout_name("Opção escolhida: Criptografia")   
        criptografa()    
    if opcao == 2:
        imprime_layout_name("Opção escolhida: Descriptografia")
        descriptografa()
    if opcao == 0:
        exit(0)
#=======================================================================#
#   Encriptografa                                                       #
#=======================================================================#
def encriptografa(chave, texto):
    bits_chave = chave.split(' ')
    bits_texto = texto.split(' ')
    # Remove posições nulas da lista
    del(bits_chave[-1])
    del(bits_texto[-1])
    resultado = []
    # Encriptografada cada bit da string
    for i in range(len(bits_texto)):
        resultado.append( str( bin( int(bits_texto[i],2) ^ int(bits_chave[i],2) )[2::] ) )
    return resultado
#=======================================================================#
#   Criptografa                                                         #
#=======================================================================#
def criptografa():
    global chave, chave_binario, texto_criptografado, chave_bin    
    # Recebe o texto aberto
    texto_aberto = str(input("  Insira o texto aberto: "))        
    # Converte o texto aberto em binário
    texto_binario = str_to_bin(texto_aberto)
    print("\n  '",texto_aberto, "' em binário é ", texto_binario)
    # O tamanho da chave deve ser do tamanho do texto aberto
    chave = gerador_chave(len(texto_aberto))
    print("\n  Chave gerada: ", chave)
    # Converte a chave string em binário
    chave_binario = str_to_bin(chave)
    print("\n  Chave gerada em binário: ", chave_binario)
    # Operação XOR com o texto e a chave
    texto_criptografado = encriptografa(chave_binario, texto_binario)
    chave_bin = chave_binario.split(' ')
    del(chave_bin[-1])    
    print("\n  MENSAGEM CRIPTOGRAFADA: ", texto_criptografado)    
#=======================================================================#
#   Descriptografa                                                      #
#=======================================================================#
def descriptografa():
    global chave, chave_bin, texto_criptografado
    texto_claro = []
    texto_descriptografado = []    
    if(chave != ''):
        print("\n  Texto aberto em binário: ", end="")
        # Desincriptografa o texto usando a chave e o texto encriptografado
        for i in range( len(texto_criptografado) ):
            texto_descriptografado.append( bin( int(chave_bin[i],2) ^ int(texto_criptografado[i],2) )[2::] )
            print(texto_descriptografado[i], " " ,end="")
        print("\n\n  MENSAGEM DECRIPTOGRAFADA: ", end="")
        # Tranforma o texto claro em bits para caracteres
        for j in range(len(texto_descriptografado)):
            texto_claro.append( bin_to_str( texto_descriptografado[j] ))
            print(texto_claro[j], end="" )
        print("\n")        
    else:
        print("\n  Nenhuma chave armazenada em memória")
#=======================================================================#
#   Fluxo principal
#=======================================================================#
def main():
    imprime_menu()
    opcao = int(input("  Selecione uma opção: "))
    select_option(opcao)
    while(opcao != 0): 
        imprime_menu()    
        opcao = int(input("  Selecione uma opção: "))
        select_option(opcao)

main()